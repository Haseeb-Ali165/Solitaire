#pragma once
#include "Card.h"
class Tableau {
private:
	vector<Card*> pile;
    static int nextPileNumber; 
    int pileNumber;
public:

    Tableau() {
        pileNumber = nextPileNumber++; 
    }
    sf::FloatRect bounds;

    void addCard( Card& card) {
        pile.push_back(&card);
    }

    void addCards(vector<Card*> v) {
        int i = 1;
        for (Card* card : v) {
            float x = getPile().back()->bounds.left;
            float y = (getPile().back()->bounds.top)+i*(50);
            card->sprite.setPosition(x, y);
            card->sprite2.setPosition(x, y);
            pile.push_back(card);
            
        }

      
    }

   
    
    // Function to return the current pile (for drawing/rendering)
     vector<Card*>& getPile()  {
        return pile;
     }

     bool isValidDrop(vector<Card*> s ) {
         if ((int(s.front()->getRank()) == int(getPile().back()->getRank()) - 1) &&
             s.front()->getIsBlack() != getPile().back()->getIsBlack()) {
             return true;
         }
         else {
             return false;
         }
            
     }
};

class Stock {
private:
    vector<Card*> pile;

public:
    sf::FloatRect bounds;

    Stock() {
        bounds.left = 30;
        bounds.top = 150;
        bounds.width = 130;
        bounds.height = 170;
    }

    void addCard(Card& card) {
        pile.push_back(&card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card*>& getPile() {
        return pile;
    }
};

class Waste {
private:
    vector<Card*> pile;

public:
    sf::FloatRect bounds;

    Waste() {
        bounds.left = 30;
        bounds.top = 340;
        bounds.width = 130;
        bounds.height = 170;
    }

    void addCard(Card& card) {
        pile.push_back(&card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card*>& getPile() {
        return pile;
    }
};

class Foundation {
private:
    vector<Card*> pile;

public:
    sf::FloatRect bounds;
    sf::RectangleShape rect;
    sf::Texture texture;

    void addCard(Card& card) {
        pile.push_back(&card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card*>& getPile() {
        return pile;
    }
};
