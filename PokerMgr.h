#pragma once

#include <vector>
#include "Poker.h"

class PokerMgr
{
public:
	PokerMgr()
	{
		Arr.resize(52);

		// 初始化数字
		for (unsigned short int i = 0; i < 52; ++i)
		{
			Arr[i].num = (i + 4) / 4;
		}

		// 初始化花色
		for (int i = 0; i < 13; ++i)
		{
			Arr[i * 4 + 0].color = PokerColor::Hearts;
			Arr[i * 4 + 1].color = PokerColor::Clubs;
			Arr[i * 4 + 2].color = PokerColor::Diamonds;
			Arr[i * 4 + 3].color = PokerColor::Spades;
		}
	}

	const std::vector<Poker>& GetArr() { return Arr; }
	
private:
	std::vector<Poker> Arr;
};