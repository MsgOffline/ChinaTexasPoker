#pragma once

enum class PokerColor
{
	Null,
	Hearts,		// ����
	Clubs,		// ÷��
	Diamonds,	// ����
	Spades		// ����
};

class Poker
{
public:
	Poker() : num(0), color(PokerColor::Null)
	{}

	bool IsNull()
	{
		return num == 0 || color == PokerColor::Null;
	}

	unsigned short int num;
	PokerColor color;
};