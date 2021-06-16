#include "engine.h";
#include "card.h"
#include <array>
#include <iostream>

int main()
{
    std::array<Card, numCardsInDeck> deck = createDeck();
    while (true)
    {
        shuffleDeck(deck);
        GameOutcome go = playBlackjack(deck);
        printGameResult(go);
        bool playAgain = queryForPlayAgain();
        if (!playAgain)
        {
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "Thanks for playing!\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        std::cout << "\n\n";
    }
}
