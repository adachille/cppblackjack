#include "card.h"
#include <array>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>


void printCard(const Card card)
{
	std::string output{};
	switch (card.rank)
	{
	case Rank::two:
		output = output + "2";
		break;
	case Rank::three:
		output = output + "3";
		break;
	case Rank::four:
		output = output + "4";
		break;
	case Rank::five:
		output = output + "5";
		break;
	case Rank::six:
		output = output + "6";
		break;
	case Rank::seven:
		output = output + "7";
		break;
	case Rank::eight:
		output = output + "8";
		break;
	case Rank::nine:
		output = output + "9";
		break;
	case Rank::ten:
		output = output + "T";
		break;
	case Rank::jack:
		output = output + "J";
		break;
	case Rank::queen:
		output = output + "Q";
		break;
	case Rank::king:
		output = output + "K";
		break;
	case Rank::ace:
		output = output + "A";
		break;
	default:
		output = output + "?";
		break;
	}

	switch (card.suit)
	{
	case Suit::heart:
		output = output + "H";
		break;
	case Suit::club:
		output = output + "C";
		break;
	case Suit::spade:
		output = output + "S";
		break;
	case Suit::diamond:
		output = output + "D";
		break;
	default:
		output = output + "?";
		break;
	}

	std::cout << output;
}

deck_type createDeck()
{
	deck_type deck{};
	int ranks = static_cast<int>(Rank::num_ranks);
	int suits = static_cast<int>(Suit::num_suits);
	int index{ 0 };
	for (int rankInd{ 0 }; rankInd < ranks; rankInd++)
	{
		for (int suitInd{ 0 }; suitInd < suits; suitInd++)
		{
			deck[index].rank = static_cast<Rank>(rankInd);
			deck[index].suit = static_cast<Suit>(suitInd);
			index++;
		}
	}

	return deck;
}

void printDeck(const deck_type& deck)
{
	for (auto card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
}

void printHand(const hand_type& hand)
{
	for (auto card : hand)
	{
		printCard(card);
		std::cout << " ";
	}
}

void shuffleDeck(deck_type& deck)
{
	//std::random_device rd;
	//std::mt19937 g{ rd() };
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int getValue(const Card card)
{
	switch (card.rank)
	{
	case Rank::two:
		return 2;
	case Rank::three:
		return 3;
	case Rank::four:
		return 4;
	case Rank::five:
		return 5;
	case Rank::six:
		return 6;
	case Rank::seven:
		return 7;
	case Rank::eight:
		return 8;
	case Rank::nine:
		return 9;
	case Rank::ten:
	case Rank::jack:
	case Rank::queen:
	case Rank::king:
		return 10;
	case Rank::ace:
		return 11;
	default:
		return -1;
	}
}

int getHandValue(hand_type hand)
{
	int value = 0;
	for (auto card : hand)
	{
		value += getValue(card);
	}
	return value;
}
