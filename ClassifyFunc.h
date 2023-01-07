#pragma once

#include "Poker.h"

class ClassifyBase
{
public:
	// 默认传入点数 a <= b <= c
	virtual bool Classify(const Poker& a, const Poker& b, const Poker& c) = 0;
};

// 皇家同花顺（方便起见以JQK为准）
class Classify_HuangJia : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num == 11 &&
				b.num == 12 &&
				c.num == 13 &&
				a.color == b.color &&
				a.color == c.color;
	}
};

// 同花顺
class Classify_TongHuaShun : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num + 1 == b.num &&
				a.num + 2 == c.num &&
				a.color == b.color &&
				a.color == c.color;
	}
};

// 豹子
class Classify_BaoZi : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num == b.num &&
				a.num == c.num;
	}
};

// 同花
class Classify_TongHua : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.color == b.color &&
				a.color == c.color;
	}
};

// 顺子
class Classify_Shun : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num + 1 == b.num &&
				a.num + 2 == c.num;
	}
};

// 对子
class Classify_Dui : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return  a.num == b.num ||
				a.num == c.num ||
				b.num == c.num;
	}
};

// 散牌
class Classify_None : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return true;
	}
};