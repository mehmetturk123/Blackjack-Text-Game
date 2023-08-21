#include <iostream>
#include <ctime> // std::time
#include <random> // std::mt19937
#include "Deck.h"


Deck::Deck() 
{
	Deck::DeckIndex index{ 0 };
	for (int suit{ 0 }; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
	{
		for (int rank{ 0 }; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
		{
			Deck::m_deck[index].m_suit = static_cast<Card::CardSuit>(suit);
			Deck::m_deck[index].m_rank = static_cast<Card::CardRank>(rank);
			++index;
		}
	}
}


void Deck::print() const
{
	for (const auto& card : Deck::m_deck)
	{
		card.print();
		std::cout << ' ';
	}
	
	std::cout << '\n';
}

void Deck::shuffle()
{
	Deck::m_cardIndex = 0;

	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(Deck::m_deck.begin(),Deck::m_deck.end(), mt);
}

const Card& Deck::dealCard() 
{
	return Deck::m_deck[Deck::m_cardIndex++];	
}