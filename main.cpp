#include <iostream>
#include "Blackjack.h"

int main()
{
    Deck deck{};

    deck.shuffle();

    if (blackjack::playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}