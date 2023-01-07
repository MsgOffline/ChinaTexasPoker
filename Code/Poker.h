#pragma once

enum class PokerColor
{
	Null,
	Hearts,		// ºìÌÒ
	Clubs,		// Ã·»¨
	Diamonds,	// ·½¿é
	Spades		// ºÚÌÒ
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