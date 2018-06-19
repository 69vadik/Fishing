#pragma once
#include "cocos2d.h"
#include "cocos2d/cocos/ui/CocosGUI.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Main_Menu.h"
#include "Jus.h"


USING_NS_CC;

using namespace std;

using namespace cocos2d::ui;


class Shop : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void ButtonMRood();
	void buttonClickMRood(Ref *ref);
	void ButtonMLure();
	void buttonClickMLure(Ref *ref);
	void ButtonMLine();
	void buttonClickMLine(Ref *ref);
	void ButtonMCoil();
	void buttonClickMCoil(Ref *ref);
	void ButtonMHook();
	void buttonClickMHook(Ref *ref);
	void outTextMoney();
	void ReadWithFile();
	void ReadWithFileMoney();
	void ReadWithFileHelpWord();
	void ReadWithFileHelpPredmet();
	vector<string> ReturnVectorWriteTheLine(const char* text);
	void exampleLabelMenu();
	void Click_lbl0();
	void Click_lbl1();
	void Click_lbl2();
	void Click_lbl3();
	void Click_lbl4();
	void Click_lbl5();
	void Click_lbl6();
	void Click_lbl7();
	void Click_lbl8();
	void Click_lbl9();
	void Click_lbl10();
	void Click_lbl11();
	void InitExit();
	void buttonClickExit(Ref *ref);
	void exactlyBuy(string str);
	void buttonClickExectlyNo(Ref *ref);
	void buttonClickExectlyYes(Ref *ref);
	void writeInFile();
	void writePredmet(string way);
	bool itIsInFile(string str);
	void youHaveItPredmet();
	void buttonClickyouHaveItPredmet(Ref *ref);
	void ReadIntLure(string str, int type, int TimeType);
	void WriteIntLure(string str, int type);

	CREATE_FUNC(Shop);
	
private:
	Button *MRood, *MLure, *MLine, *MHook, *MCoil, *Exit;
	Label  *TextMoney;
	string path = FileUtils::getInstance()->getWritablePath();
	vector<string> FileForWrite;
	Menu *m, *mLure;
	int Count = 12;
	vector <string> HelpWord;
	string pathMoney = FileUtils::getInstance()->getWritablePath();
	string pathHelpWord = FileUtils::getInstance()->getWritablePath();
	int Money;
	enum TypeShop { typeMRood, typeMCoil, typeMLine, typeMLure, typeMHook } typeShop;
	int BuyWithShop = 0;
	Sprite *exectly;
	Button *exectlyNo, *exectlyYes;
	Label *exectlylabel, *labelouttext;
	string BuyWithShopToInt, mon, predmet;
	bool helpExectly = false;
	vector<string> HelpPredmet;
	string pathHelpPredmet = FileUtils::getInstance()->getWritablePath();
	int Ibread, Iworm, Icorn, Idough, Ifish, Imeat, Ioparish, Iperlovka, Itvister;
	int Tbread, Tworm, Tcorn, Tdough, Tfish, Tmeat, Toparish, Tperlovka, Ttvister;
	string WithIntToString;
};

