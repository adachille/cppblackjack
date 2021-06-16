#include "card.h"
#include "engine.h"
#include "utils.h"
#include <iostream>
#include <vector>

static enum class PlayerMove
{
    hit,
    stand
};

static PlayerMove getPlayerMove()
{
    while (true)
    {
        std::cout << "Enter 'h' to hit or 's' to stand: ";
        std::string stringMove;
        std::cin >> stringMove;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (stringMove == "h")
        {
            return PlayerMove::hit;
        }
        else if (stringMove == "s")
        {
            return PlayerMove::stand;
        }
    }
}

static void printHandInfo(hand_type dealerHand, hand_type playerHand)
{
    std::cout << "Dealer's hand: ";
    printHand(dealerHand);
    std::cout << "\n";
    std::cout << "Your hand: ";
    printHand(playerHand);
    std::cout << "\n";
}

void printGameResult(GameOutcome go)
{
    switch (go)
    {
    case GameOutcome::player_wins:
        std::cout << "Congratulations, you won!";
        break;
    case GameOutcome::dealer_wins:
        std::cout << "Sorry, you lost.";
        break;
    case GameOutcome::draw:
        std::cout << "It was a tie!";
        break;
    default:
        std::cout << "Unknown game outcome";
        break;
    }
    std::cout << "\n\n\n\n";
}

bool queryForPlayAgain()
{
    std::cout << "Enter 'q' to quit or anything else to play again: ";
    std::string stringMove;
    std::cin >> stringMove;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return stringMove != "q";
}

GameOutcome playBlackjack(deck_type deck)
{
    // Print game greeting message
    std::cout << "Welcome to C++ Blackjack!\n";
    std::cout << "_______________________________________________\n\n";

    std::vector<Card> dealerHand{};
    std::vector<Card> playerHand{};
    int nextCardInd = 0;

    // Deal initial cards
    dealerHand.push_back(deck[nextCardInd++]);
    playerHand.push_back(deck[nextCardInd++]);
    playerHand.push_back(deck[nextCardInd++]);

    std::cout << "Starting cards:\n";
    printHandInfo(dealerHand, playerHand);
    std::cout << "_______________________________________________\n\n";


    // Player's turn
    std::cout << "YOUR TURN\n";
    bool playerBusted = false;
    while (true)
    {
        sleep(1500);
        // Check value for 21 / bust
        int handValue = getHandValue(playerHand);
        if (handValue == 21)
        {
            std::cout << "Nice, you got 21!\n";
            break;
        }
        else if (handValue > 21)
        {
            playerBusted = true;
            break;
        }
        else if (nextCardInd >= numCardsInDeck)
        {
            return GameOutcome::unknown;
        }

        printHandInfo(dealerHand, playerHand);

        // Player plays
        PlayerMove pm = getPlayerMove();
        if (pm == PlayerMove::stand)
        {
            std::cout << "You chose to stand.\n";
            break;
        }
        else if (pm == PlayerMove::hit)
        {
            playerHand.push_back(deck[nextCardInd++]);
            std::cout << "You drew ";
            printCard(playerHand.back());
            std::cout << "\n";
        }
    }

    // Dealers's turn
    bool dealerBusted = false;
    if (!playerBusted)
    {
        std::cout << "_______________________________________________\n\n";
        std::cout << "DEALER'S TURN\n";
        while (true)
        {
            printHandInfo(dealerHand, playerHand);
            sleep(3000);

            dealerHand.push_back(deck[nextCardInd++]);
            std::cout << "Dealer drew ";
            printCard(dealerHand.back());
            std::cout << "\n";

            // Check value for 21 / bust
            int handValue = getHandValue(dealerHand);
            if (handValue > 21)
            {
                dealerBusted = true;
                break;
            }
            else if (handValue >= 17)
            {
                std::cout << "Dealer's turn over\n";
                break;
            }
            else if (nextCardInd >= numCardsInDeck)
            {
                return GameOutcome::unknown;
            }
        }
    }

    // Determine winner
    std::cout << "_______________________________________________\n\n";
    std::cout << "RESULTS\n";
    sleep(2000);
    int dealerHandValue = getHandValue(dealerHand);
    int playerHandValue = getHandValue(playerHand);
    if (playerBusted)
    {
        std::cout << "Oof, you busted with a " << playerHandValue << ".\n";
        return GameOutcome::dealer_wins;
    }
    else if (dealerBusted)
    {
        std::cout << "Dealer busted with a " << dealerHandValue << ".\n";
        return GameOutcome::player_wins;
    }
    else
    {
        std::cout << "Final Player Score: " << playerHandValue << "\n";
        std::cout << "Final Dealer Score: " << dealerHandValue << "\n";

        if (dealerHandValue > playerHandValue)
        {
            return GameOutcome::dealer_wins;
        }
        else if (dealerHandValue == playerHandValue)
        {
            return GameOutcome::draw;
        }
        else
        {
            return GameOutcome::player_wins;
        }
    }
}
