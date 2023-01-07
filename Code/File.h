#pragma once

#include "Poker.h"

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <io.h>

using namespace std;

class FileMgr
{
public:
	FileMgr()
	{
		SpawnFolder();

		ofs_HuangJia   .open("Res/HuangJia.txt"   , ios::trunc);
		ofs_TongHuaShun.open("Res/TongHuaShun.txt", ios::trunc);
		ofs_BaoZi      .open("Res/BaoZi.txt"      , ios::trunc);
		ofs_TongHua    .open("Res/TongHua.txt"    , ios::trunc);
		ofs_Shun       .open("Res/Shun.txt"       , ios::trunc);
		ofs_Dui        .open("Res/Dui.txt"        , ios::trunc);
		ofs_None       .open("Res/None.txt"       , ios::trunc);

		colorMap[PokerColor::Hearts]   = "红桃";
		colorMap[PokerColor::Clubs]    = "梅花";
		colorMap[PokerColor::Diamonds] = "方块";
		colorMap[PokerColor::Spades]   = "黑桃";

		numMap[1] = "A";
		numMap[2] = "2";
		numMap[3] = "3";
		numMap[4] = "4";
		numMap[5] = "5";
		numMap[6] = "6";
		numMap[7] = "7";
		numMap[8] = "8";
		numMap[9] = "9";
		numMap[10] = "10";
		numMap[11] = "J";
		numMap[12] = "Q";
		numMap[13] = "K";
	}

	~FileMgr()
	{
		ofs_HuangJia   .close();
		ofs_TongHuaShun.close();
		ofs_BaoZi      .close();
		ofs_TongHua    .close();
		ofs_Shun       .close();
		ofs_Dui        .close();
		ofs_None       .close();
	}

	// 将数据可读
	string Switch(const Poker& pkr);

	// 生成输出文件夹
	void SpawnFolder();

	void Output_HuangJia   (const Poker& a, const Poker& b, const Poker& c);
	void Output_TongHuaShun(const Poker& a, const Poker& b, const Poker& c);
	void Output_BaoZi      (const Poker& a, const Poker& b, const Poker& c);
	void Output_TongHua    (const Poker& a, const Poker& b, const Poker& c);
	void Output_Shun       (const Poker& a, const Poker& b, const Poker& c);
	void Output_Dui        (const Poker& a, const Poker& b, const Poker& c);
	void Output_None       (const Poker& a, const Poker& b, const Poker& c);

private:
	ofstream ofs_HuangJia;
	ofstream ofs_TongHuaShun;
	ofstream ofs_BaoZi;
	ofstream ofs_TongHua;
	ofstream ofs_Shun;
	ofstream ofs_Dui;
	ofstream ofs_None;

	unordered_map<PokerColor, string> colorMap;
	unordered_map<unsigned short int, string> numMap;
};


string FileMgr::Switch(const Poker& pkr)
{
	return colorMap[pkr.color] + numMap[pkr.num];
}

void FileMgr::SpawnFolder()
{
	char folderPath[10] = "./Res";
	if (_access(folderPath, 0) != 0)
	{
		system("mkdir Res");
	}
}


void FileMgr::Output_HuangJia(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_HuangJia << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_TongHuaShun(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_TongHuaShun << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_BaoZi(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_BaoZi << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_TongHua(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_TongHua << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_Shun(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_Shun << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_Dui(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_Dui << a_str << "\t" << b_str << "\t" << c_str << endl;
}

void FileMgr::Output_None(const Poker& a, const Poker& b, const Poker& c)
{
	string&& a_str = Switch(a);
	string&& b_str = Switch(b);
	string&& c_str = Switch(c);

	ofs_None << a_str << "\t" << b_str << "\t" << c_str << endl;
}