#pragma once
#include <array>
#include <vector>

const std::size_t numCardsInDeck = 52;
// Define card
enum class Rank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
	num_ranks
};
enum class Suit
{
	heart,
	diamond,
	spade,
	club,
	num_suits
};
struct Card
{
	Rank rank{};
	Suit suit{};
};

using deck_type = std::array<Card, numCardsInDeck>;
using hand_type = std::vector<Card>;
// Print a card using code "<Rank><Suit>", e.g. QH = Queen of Hearts
void printCard(const Card card);
// Create a deck of 52 cards
deck_type createDeck();
// Print all cards of the deck in a line
void printDeck(const deck_type& deck);
// Print hand
void printHand(const hand_type& hand);
// Shuffle the cards in the deck
void shuffleDeck(deck_type& deck);
// Get the value of a card
int getValue(const Card card);
// Get the value of a hand
int getHandValue(hand_type hand);
