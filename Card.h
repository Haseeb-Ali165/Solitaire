#pragma once
#include<algorithm>
#include<random>
using namespace std;
enum class Suit {
	hearts, diamonds, clubs, spades
};

enum class Rank {
	ace = 1, two, three, four, five, six,
	seven, eight, nine, ten, jack, queen, king
};

class Pos { public:float x, y; };
class size{};

string getCardImageFileName(Suit s, Rank r) {
	ostringstream os;

	switch (r) {
	case Rank::ace:   os << "ace"; break;
	case Rank::two:   os << "two"; break;
	case Rank::three: os << "three"; break;
	case Rank::four:  os << "four"; break;
	case Rank::five:  os << "five"; break;
	case Rank::six:   os << "six"; break;
	case Rank::seven: os << "seven"; break;
	case Rank::eight: os << "eight"; break;
	case Rank::nine:  os << "nine"; break;
	case Rank::ten:   os << "ten"; break;
	case Rank::jack:  os << "jack"; break;
	case Rank::queen: os << "queen"; break;
	case Rank::king:  os << "king"; break;
	}

	switch (s) {
	case Suit::hearts:   os << "hearts"; break;
	case Suit::diamonds: os << "diamonds"; break;
	case Suit::clubs:    os << "clubs"; break;
	case Suit::spades:   os << "spades"; break;
	}

	os << ".jpeg";
	return os.str();
}

class Card {
private:
	Suit suit;
	Rank rank;
	bool isFaceUp;
	sf::Vector2f pos;
	

public:
	sf::Texture texture;
	sf::Texture facedown_texture;
	sf::Sprite sprite;
	sf::Sprite sprite2;  // for facedown texture
	sf::FloatRect bounds;

	Card(Suit s, Rank r, bool i)
		: suit(s), rank(r), isFaceUp(i) {

		texture.loadFromFile(getCardImageFileName(s,r));
		facedown_texture.loadFromFile("facedown.jpg");

		// Initialize sprites
		sprite.setTexture(texture);
		sprite2.setTexture(facedown_texture);


		// Set the desired size for both sprites
		sprite.setScale(130.f / texture.getSize().x, 170.f / texture.getSize().y);
		sprite2.setScale(130.f / facedown_texture.getSize().x, 170.f / facedown_texture.getSize().y);

		/*bounds = sprite.getGlobalBounds();
		bounds.height = 50;*/

		// Set initial state (face down)
		//isFaceUp = false;
	}

	Suit getSuit() const { return suit; }
	Rank getRank() const { return rank; }
	bool getIsFaceUp() const { return isFaceUp; }
	sf::Vector2f getPos() { return pos; }
	void setPos(Pos p) { pos.x = p.x, pos.y = p.y; }

	sf::Sprite& getSprite()   { 
		if (isFaceUp)
			return sprite;
		else
			return sprite2;
	}

	void flip() {
		isFaceUp = !isFaceUp;

	}
};

void shuffleDeck(std::vector<Card*>& deck) {
	
	random_device rd;  // Obtain a random number from hardware
	mt19937 g(rd()); // Seed the generator

	// Shuffle the deck
	shuffle(deck.begin(), deck.end(), g);
}
