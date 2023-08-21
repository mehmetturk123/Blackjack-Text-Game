#pragma once
#include "Player.h"

namespace blackjack
{
	bool playerWantsHit();

	// Returns true if the player went bust. False otherwise.
	bool playerTurn(Deck& deck, Player& player);

	// Returns true if the dealer went bust. False otherwise.
	bool dealerTurn(Deck& deck, Player& player);

	// Returns true if the player won. False otherwise.
	bool playBlackjack(Deck& deck);
}

