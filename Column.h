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

    Stock() {
        bounds.left = 30;
        bounds.left = 150;
        bounds.width = 130;
        bounds.height = 170;
    }

    void addCard(Card& card) {
        pile.push_back(card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card>& getPile() {
        return pile;
    }
};

class Waste {
private:
    vector<Card> pile;

public:
    sf::FloatRect bounds;

    Waste() {
        bounds.left = 30;
        bounds.top = 340;
        bounds.width = 130;
        bounds.height = 170;
    }

    void addCard(Card& card) {
        pile.push_back(card);
    }

    // Function to return the current pile (for drawing/rendering)
    vector<Card>& getPile() {
        return pile;
    }
};
