#include <iostream>
#include "Blackjack.h"

bool blackjack::playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

bool blackjack::playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            // This can happen even before the player had a choice if they drew 2 aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                std::cout << "You were dealt a " << player.drawCard(deck) << " and now have " << player.score() << '\n';
            }
            else
            {
                return false;
            }
        }
    }
}

bool blackjack::dealerTurn(Deck& deck, Player& player)
{
    // Draw cards until we reach the minimum value.
    while (player.score() < constants::g_minimumDealerScore)
    {
        std::cout << "The dealer turned up a " << player.drawCard(deck) << " and now has " << player.score() << '\n';
    }

    // If the dealer's score is too high, they went bust.
    if (player.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool blackjack::playBlackjack(Deck& deck)
{
    Player dealer{}; // Create the dealer.
    dealer.drawCard(deck); // Give them 1 card.

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{}; // Create the player.
    player.drawCard(deck); // Give them 2 card.
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score() > dealer.score());

}
