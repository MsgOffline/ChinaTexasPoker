#pragma once

#include "Poker.h"

class ClassifyBase
{
public:
	// Ĭ�ϴ������ a <= b <= c
	virtual bool Classify(const Poker& a, const Poker& b, const Poker& c) = 0;
};

// �ʼ�ͬ��˳�����������JQKΪ׼��
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

// ͬ��˳
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

// ����
class Classify_BaoZi : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num == b.num &&
				a.num == c.num;
	}
};

// ͬ��
class Classify_TongHua : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.color == b.color &&
				a.color == c.color;
	}
};

// ˳��
class Classify_Shun : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return	a.num + 1 == b.num &&
				a.num + 2 == c.num;
	}
};

// ����
class Classify_Dui : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return  a.num == b.num ||
				a.num == c.num ||
				b.num == c.num;
	}
};

// ɢ��
class Classify_None : public ClassifyBase
{
	bool Classify(const Poker& a, const Poker& b, const Poker& c) override
	{
		return true;
	}
};