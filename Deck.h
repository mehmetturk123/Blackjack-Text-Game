#pragma once
#include <array>
#include "Card.h"

class Deck
{
public:
	using Deck_t = std::array<Card, 52>;
	using DeckIndex = Deck_t::size_type;

	Deck();

	void print() const;

	void shuffle();

	const Card& dealCard();

private:
	Deck_t m_deck{};
	DeckIndex m_cardIndex{ 0 };
};

