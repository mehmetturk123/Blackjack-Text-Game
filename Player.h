#pragma once
#include "Constants.h"
#include "Deck.h"

class Player
{
public:

	int drawCard(Deck& deck);
	
	bool isBust();
	
	int score() const;

private:
	int m_Score{ 0 };

};

