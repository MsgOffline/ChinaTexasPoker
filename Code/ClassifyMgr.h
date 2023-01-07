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
	// 初始化循环所需变量
	const std::vector<Poker>& PokerArr = pokerMgr->GetArr();
	size_t siz = PokerArr.size();
	std::vector<size_t> stk;

	// 初始化分类所需变量
	// 一定要有顺序，因为比如"豹子判定"同时也满足"对子判定"
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


	// 循环判定
	for (size_t i = 0; i < siz; ++i)
	{
		stk.push_back(i);

		for (size_t j = i + 1; j < siz; ++j)
		{
			stk.push_back(j);

			for (size_t k = j + 1; k < siz; ++k)
			{
				stk.push_back(k);

				// 按顺序判定牌型
				for (int idx = 0; idx < 7; ++idx)
				{
					if (clsPtrArr[idx]->Classify(PokerArr[stk[0]], PokerArr[stk[1]], PokerArr[stk[2]]) == true)
					{
						(resMgr->*resFuncArr[idx])(PokerArr[stk[0]], PokerArr[stk[1]], PokerArr[stk[2]]);
						break;	// 别忘 bug之源
					}
				}

				stk.pop_back();
			}

			stk.pop_back();
		}

		stk.pop_back();
	}

	// 排序结果
	resMgr->Sort();

	// 清理
	for (int i = 0; i < 7; ++i)
	{
		delete clsPtrArr[i];
	}
}
