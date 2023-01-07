#pragma once

#include "File.h"

#include <vector>
#include <string>
#include <algorithm>

class ResultMgr
{
public:
	ResultMgr()
		:	ResArr(7, {0, ""}),
			sum(0)
	{
		Clear();

		ResArr[0].second = "皇家";
		ResArr[1].second = "同花顺";
		ResArr[2].second = "豹子";
		ResArr[3].second = "同花";
		ResArr[4].second = "顺子";
		ResArr[5].second = "对子";
		ResArr[6].second = "散牌";

		fileMgr = new FileMgr();
	}

	~ResultMgr()
	{
		delete fileMgr;
	}


	// 计数
	void Add_HuangJia    (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[0].first; ++sum; fileMgr->Output_HuangJia(a, b, c);    }
	void Add_TongHuaShun (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[1].first; ++sum; fileMgr->Output_TongHuaShun(a, b, c); }
	void Add_BaoZi       (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[2].first; ++sum; fileMgr->Output_BaoZi(a, b, c);       }
	void Add_TongHua     (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[3].first; ++sum; fileMgr->Output_TongHua(a, b, c);     }
	void Add_Shun        (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[4].first; ++sum; fileMgr->Output_Shun(a, b, c);        }
	void Add_Dui         (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[5].first; ++sum; fileMgr->Output_Dui(a, b, c);         }
	void Add_None        (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[6].first; ++sum; fileMgr->Output_None(a, b, c);        }

	// 清零
	void Clear()
	{
		for (std::pair<unsigned int, std::string>& cur : ResArr)
		{
			cur.first = 0;
		}

		sum = 0;
	}

	// 排序（pair排序会优先first、后second的机制）
	void Sort()
	{
		std::sort(ResArr.begin(), ResArr.end());
	}

	const std::vector<std::pair<unsigned int, std::string>>& GetResArr() { return ResArr; }
	size_t GetSum() { return sum; }

private:
	std::vector<std::pair<unsigned int, std::string>> ResArr;	// first存出现次数，second存牌型名称
	size_t sum;		// 组合的总数
	FileMgr* fileMgr;
};