#pragma once

#include "PokerMgr.h"
#include "ResultMgr.h"
#include "ClassifyFunc.h"

#include <vector>

class ClassifyMgr
{
public:
	ClassifyMgr(PokerMgr* pokerMgr, ResultMgr* resMgr)
		: pokerMgr(pokerMgr), resMgr(resMgr)
	{}

	void Calculation();

private:
	PokerMgr* pokerMgr;
	ResultMgr* resMgr;
};


void ClassifyMgr::Calculation()
{
	// ��ʼ��ѭ���������
	const std::vector<Poker>& PokerArr = pokerMgr->GetArr();
	size_t siz = PokerArr.size();
	std::vector<size_t> stk;

	// ��ʼ�������������
	// һ��Ҫ��˳����Ϊ����"�����ж�"ͬʱҲ����"�����ж�"
	std::vector<ClassifyBase*> clsPtrArr(7);
	clsPtrArr[0] = new Classify_HuangJia();
	clsPtrArr[1] = new Classify_TongHuaShun();
	clsPtrArr[2] = new Classify_BaoZi();
	clsPtrArr[3] = new Classify_TongHua();
	clsPtrArr[4] = new Classify_Shun();
	clsPtrArr[5] = new Classify_Dui();
	clsPtrArr[6] = new Classify_None();

	std::vector<void(ResultMgr::*)(const Poker&, const Poker&, const Poker&)> resFuncArr(7);
	resFuncArr[0] = &ResultMgr::Add_HuangJia;
	resFuncArr[1] = &ResultMgr::Add_TongHuaShun;
	resFuncArr[2] = &ResultMgr::Add_BaoZi;
	resFuncArr[3] = &ResultMgr::Add_TongHua;
	resFuncArr[4] = &ResultMgr::Add_Shun;
	resFuncArr[5] = &ResultMgr::Add_Dui;
	resFuncArr[6] = &ResultMgr::Add_None;


	// ѭ���ж�
	for (size_t i = 0; i < siz; ++i)
	{
		stk.push_back(i);

		for (size_t j = i + 1; j < siz; ++j)
		{
			stk.push_back(j);

			for (size_t k = j + 1; k < siz; ++k)
			{
				stk.push_back(k);

				// ��˳���ж�����
				for (int idx = 0; idx < 7; ++idx)
				{
					if (clsPtrArr[idx]->Classify(PokerArr[stk[0]], PokerArr[stk[1]], PokerArr[stk[2]]) == true)
					{
						(resMgr->*resFuncArr[idx])(PokerArr[stk[0]], PokerArr[stk[1]], PokerArr[stk[2]]);
						break;	// ���� bug֮Դ
					}
				}

				stk.pop_back();
			}

			stk.pop_back();
		}

		stk.pop_back();
	}

	// ������
	resMgr->Sort();

	// ����
	for (int i = 0; i < 7; ++i)
	{
		delete clsPtrArr[i];
	}
}
