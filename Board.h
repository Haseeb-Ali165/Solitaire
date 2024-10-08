#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "Card.h"
#include "Column.h"
using namespace std;


class Board {
private:

    std::vector<Card*> selectedCards;
    sf::Vector2f originalPosition;

    void handleMouseClick(int mouseX, int mouseY, vector<Tableau>& t, Stock& s, Waste& w) {
        if (s.bounds.contains(mouseX, mouseY)) {
            //Card* c = s.getPile().back();
            w.getPile().push_back(s.getPile().back()); // back = last element(top of stack)
            s.getPile().pop_back();
            return;
        }
        for (int i = 0; i < 7; i++) {
            cout << t[i].bounds.contains(mouseX, mouseY);
            if (t[i].bounds.contains(mouseX, mouseY)) {
                for (int j = 0; j < t[i].getPile().size(); j++) {
                    if (t[i].getPile()[j].bounds.contains(mouseX, mouseY) && t[i].getPile()[j].getIsFaceUp() == 1) {
                        selectedCards.push_back(&t[i].getPile()[j]);
                    }
                    
                }
            }
        }
       
    }
    void handleMouseMovement(int mouseX, int mouseY) {
        if (!selectedCards.empty()) {
            for (Card* card : selectedCards) {
                card->getSprite().setPosition(mouseX, mouseY); // Move with the mouse
            }
        }
    }
    
public:
    
	void initBoard() {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        sf::RenderWindow window(desktop, "Klondike Solitaire", sf::Style::Fullscreen);


        sf::Texture t;
        t.loadFromFile("backg.jpg");
        sf::Sprite s(t);
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = t.getSize();

        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

        s.setScale(scaleX, scaleY);

        //-----------------------------------------------------------

        vector<Card*> deck;

        for (int s = int(Suit::hearts); s <= int(Suit::spades); s++) {
            for (int r = int(Rank::ace); r <= int(Rank::king); r++) {
                Card* c = new Card(Suit(s), Rank(r), false);
                
                
                deck.push_back(c);
            }
        }
        shuffleDeck(deck);


        ////now for placement of cards into piles::

        vector<Tableau> tableaus(7);
        Stock stock;

        float startX = 250.f;  
        float startY = 150.f; 
        float xSpacing = 30.f;  
        float ySpacing = 50.f;

        int deckIndex = 0;  // Index to track which card from the deck we're dealing

        for (int i = 0; i < 24; i++) {
            Card* card = deck[deckIndex++];
            card->flip();
            stock.addCard(*card);
        }

        sf::Texture t1;
        t1.loadFromFile("facedown.jpg");
        sf::RectangleShape stock_pic(sf::Vector2f(130,170));
        stock_pic.setTexture(&t1);
        stock_pic.setPosition(30.f, 150.f);

        // Distribute the cards into the 7 tableaus
        for (int i = 0; i < 7; i++) {
            float tableauX = startX + i * (170 + xSpacing);  // X position of the tableau

            for (int j = 0; j <= i; j++) {  
                if (deckIndex == 24 || deckIndex == 26 || deckIndex == 29 || deckIndex == 33 || deckIndex == 38 || deckIndex == 44 || deckIndex == 51)
                    deck[deckIndex]->flip();
                Card* card = deck[deckIndex++];
                card->getSprite().setPosition(tableauX, startY + j * ySpacing);
                card->bounds = card->getSprite().getGlobalBounds();
                card->bounds.height = 50;
                tableaus[i].addCard(*card);
            }
            //setting bounds for tableau:
            tableaus[i].bounds = tableaus[i].getPile().front().bounds;
            tableaus[i].bounds.height = (50*(tableaus[i].getPile().size()))+120;
        }


        Waste waste;
        


        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
                    handleMouseClick(event.mouseButton.x, event.mouseButton.y, tableaus,stock, waste);
                    
                }
                if (event.type == sf::Event::MouseMoved) {
                    handleMouseMovement(event.mouseMove.x, event.mouseMove.y);
                }
               
            }

            window.clear();

            
            window.draw(s);                         //draw background
            window.draw(stock_pic);                 //stockPile pic
            for (Tableau& tbl : tableaus) {         //draw tableaus
                for (Card& card : tbl.getPile()) {
                    window.draw(card.getSprite());
                }
            }



            window.display();
        }
	}

    /*void play()
    {
        while (window.isOpen()) {

        }
    }*/ 
};
