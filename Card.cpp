#include "Card.h"
#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <string_view>

Card::Card(CardRank cardRank, CardSuit cardSuit) : m_rank{ cardRank } , m_suit{ cardSuit }
{

}

char Card::getCardRankChar() const
{
	switch (Card::m_rank)
	{
	case CardRank::rank_2:      return '2';
	case CardRank::rank_3:      return '3';
	case CardRank::rank_4:      return '4';
	case CardRank::rank_5:      return '5';
	case CardRank::rank_6:      return '6';
	case CardRank::rank_7:      return '7';
	case CardRank::rank_8:      return '8';
	case CardRank::rank_9:      return '9';
	case CardRank::rank_10:     return 'T';
	case CardRank::rank_jack:   return 'J';
	case CardRank::rank_king:   return 'K';
	case CardRank::rank_queen:  return 'Q';
	case CardRank::rank_ace:    return 'A';
	default:
		return '?';
	}
}

char Card::getCardSuitChar() const
{
	switch (Card::m_suit)
	{
	case CardSuit::club:       return 'C'; 
	case CardSuit::diamond:    return 'D'; 
	case CardSuit::heart:      return 'H'; 
	case CardSuit::spade:      return 'S'; 
	default:
		return '?';
		
	}
}

void Card::print() const
{
	std::cout << Card::getCardRankChar() << Card::getCardSuitChar();
}

int Card::value() const
{
	switch (m_rank)
	{
	case CardRank::rank_2:        return 2;
	case CardRank::rank_3:        return 3;
	case CardRank::rank_4:        return 4;
	case CardRank::rank_5:        return 5;
	case CardRank::rank_6:        return 6;
	case CardRank::rank_7:        return 7;
	case CardRank::rank_8:        return 8;
	case CardRank::rank_9:        return 9;
	case CardRank::rank_10:       return 10;
	case CardRank::rank_jack:     return 10;
	case CardRank::rank_queen:    return 10;
	case CardRank::rank_king:     return 10;
	case CardRank::rank_ace:      return 11;
	default:
		assert(false && "should never happen");
		return 0;
	}
}