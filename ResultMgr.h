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

		ResArr[0].second = "�ʼ�";
		ResArr[1].second = "ͬ��˳";
		ResArr[2].second = "����";
		ResArr[3].second = "ͬ��";
		ResArr[4].second = "˳��";
		ResArr[5].second = "����";
		ResArr[6].second = "ɢ��";

		fileMgr = new FileMgr();
	}

	~ResultMgr()
	{
		delete fileMgr;
	}


	// ����
	void Add_HuangJia    (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[0].first; ++sum; fileMgr->Output_HuangJia(a, b, c);    }
	void Add_TongHuaShun (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[1].first; ++sum; fileMgr->Output_TongHuaShun(a, b, c); }
	void Add_BaoZi       (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[2].first; ++sum; fileMgr->Output_BaoZi(a, b, c);       }
	void Add_TongHua     (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[3].first; ++sum; fileMgr->Output_TongHua(a, b, c);     }
	void Add_Shun        (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[4].first; ++sum; fileMgr->Output_Shun(a, b, c);        }
	void Add_Dui         (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[5].first; ++sum; fileMgr->Output_Dui(a, b, c);         }
	void Add_None        (const Poker& a, const Poker& b, const Poker& c) { ++ResArr[6].first; ++sum; fileMgr->Output_None(a, b, c);        }

	// ����
	void Clear()
	{
		for (std::pair<unsigned int, std::string>& cur : ResArr)
		{
			cur.first = 0;
		}

		sum = 0;
	}

	// ����pair���������first����second�Ļ��ƣ�
	void Sort()
	{
		std::sort(ResArr.begin(), ResArr.end());
	}

	const std::vector<std::pair<unsigned int, std::string>>& GetResArr() { return ResArr; }
	size_t GetSum() { return sum; }

private:
	std::vector<std::pair<unsigned int, std::string>> ResArr;	// first����ִ�����second����������
	size_t sum;		// ��ϵ�����
	FileMgr* fileMgr;
};