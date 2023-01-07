#pragma once

#include "ResultMgr.h"

#include <iostream>
#include <iomanip>

class PrintRes
{
public:
	PrintRes(ResultMgr* resMgr)
		: resMgr(resMgr)
	{}

	void Print();

private:
	ResultMgr* resMgr;
};


void PrintRes::Print()
{
	float sum = static_cast<float>(resMgr->GetSum());
	const std::vector<std::pair<unsigned int, std::string>>& resArr = resMgr->GetResArr();

	for (int i = 0; i < 7; ++i)
	{
		std::cout << resArr[i].second << "\t->   ";
		std::cout << std::fixed << std::setprecision(6) << static_cast<float>(resArr[i].first) / sum;
		std::cout << "   (";
		std::cout << std::setiosflags(std::ios::right) << std::setw(5) << resArr[i].first;
		std::cout << " / " << resMgr->GetSum() << ")";
		std::cout << std::endl;
	}
}