#pragma once
#include "Card.h"
class Tableau {
private:
	vector<Card> pile;

public:
    sf::FloatRect bounds;

    void addCard( Card& card) {
        pile.push_back(card);
    }

    // Function to return the current pile (for drawing/rendering)
     vector<Card>& getPile()  {
        return pile;
     }
};

class Stock {
private:
    vector<Card> pile;

public:
    sf::FloatRect bounds;

    void addCard(Card& card) {
        pile.push_back(card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card>& getPile() {
        return pile;
    }
};
