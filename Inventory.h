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


class Inventory : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();	
	void OutInvName();
	void OutInvRood();
	void OutInvCoil();
	void OutInvLine();
	void OutInvHook();
	void OutInvLure();
	void OutInvComplect();
	void buttonClickInvRood(Ref *ref);
	void buttonClickInvCoil(Ref *ref);
	void buttonClickInvLine(Ref *ref);
	void buttonClickInvHook(Ref *ref);
	void buttonClickInvLure(Ref *ref);
	void buttonClickInvComplect(Ref *ref);
	vector<string> ReturnVectorWriteTheLine(const char* text);
	void ReadWithFile(string str, vector<string> *vec);
	void exampleLabelMenu();
	void Click_lbl0(int i);
	void Click_lblComplect();
	void buttonClickExectlyNo(Ref *ref);
	void buttonClickExectlyYes(Ref *ref);
	void WriteluggageForFishing(string str, string type);
	int ReadIntLure(string str);
	void InitExit();
	void buttonClickExit(Ref *ref);
	void ClearLureNull();
	

	CREATE_FUNC(Inventory);

private:
	Sprite *InvName;
	Button *InvRood, *InvCoil, *InvLine, *InvHook, *InvLure, *InvComplect;
	enum TypeShop { typeInvRood, typeInvCoil, typeInvLine, typeInvHook, typeInvLure, typeInvComplect  } typeInv;
	vector<string> InvTypeVector;
	Menu *m;
	Sprite *exectly;
	Button *exectlyNo, *exectlyYes, *Exit;
	Label *exectlylabel;
	vector <string> helpWord, luggageForFishing, helpPredmet, luggageForShopLure;
	vector<string> *pV, *pPredmet;
	string stroka;
	int nnn;
};
