#pragma once

class Card
{
public:
	enum CardSuit
	{
		club,
		diamond,
		heart,
		spade,
		max_suits
	};

	enum CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,
        max_ranks
    };

    Card() = default;

    Card(CardRank cardRank, CardSuit cardSuit);

    char getCardSuitChar() const;
    char getCardRankChar() const;

    void print() const;

    int value() const;

    friend class Deck;

private:
	CardRank m_rank{};
    CardSuit m_suit{};
};

