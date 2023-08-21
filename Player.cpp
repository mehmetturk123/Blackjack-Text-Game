#include "Player.h"

int Player::drawCard(Deck& deck)
{
	int value{ deck.dealCard().value() };
	m_Score += value;
	return value;
}

bool Player::isBust()
{
	return (m_Score > constants::g_maximumScore) ? true : false;
}

int Player::score() const
{
	return m_Score;
}