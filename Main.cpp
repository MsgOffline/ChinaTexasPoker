#include "PokerMgr.h"
#include "ResultMgr.h"
#include "ClassifyMgr.h"
#include "PrintRes.h"

int main()
{
	PokerMgr* pokerMgr  = new PokerMgr();
	ResultMgr* resMgr   = new ResultMgr();

	ClassifyMgr* clsMgr = new ClassifyMgr(pokerMgr, resMgr);
	clsMgr->Calculation();

	PrintRes* prtRes = new PrintRes(resMgr);
	prtRes->Print();

	delete pokerMgr;
	delete resMgr;
	delete clsMgr;
	delete prtRes;

	return 0;
}