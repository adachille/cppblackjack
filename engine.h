#pragma once
#include "card.h"

enum class GameOutcome
{
    player_wins,
    dealer_wins,
    draw,
    unknown
};

void printGameResult(GameOutcome go);
bool queryForPlayAgain();
GameOutcome playBlackjack(deck_type deck);
