#pragma once
#include "cocos2d.h"
#include "cocos2d/cocos/ui/CocosGUI.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Jus.h"

USING_NS_CC;

using namespace std;

using namespace cocos2d::ui;
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
using std::getline;
using std::cout;


class Market : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	vector<string> ReturnVectorWriteTheLine(const char* text);
	void ReadWithFile(string str, vector<string> *vec);
	void OutTextFish();
	void helpOut(string str, int size, int n, int y);	
	void InitPriceOfFish();
	void InitSellFish();
	void OutTextNameMarket();
	void buttonClickPriceOfFish(Ref *ref);
	void buttonClickSellFish(Ref *ref);
	void sellFishWithFile();
	void WriteInMoney(string str, int integer);
	string ReadWithMoney();
	void OutTextSellFish();
	void clearFile();
	void InitExit();
	void buttonClickExit(Ref *ref);


	CREATE_FUNC(Market);

private:
	Button *PriceOfFish, *SellFish, *Exit;
	Sprite *TextNameMarket;
	vector<string> textFish, Fish, FishMasa, HawMachMoney, OutVector, helpWord;
	vector<string> *pV;
	vector<Label*> OutTextLabel;
	Label *L;
	bool B = false;
};

