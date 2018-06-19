#pragma once
#include "cocos2d.h"
#include "cocos2d/cocos/ui/CocosGUI.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Main_Menu.h"
#include "SimpleAudioEngine.h"
#include "Jus.h"
using namespace CocosDenshion;


USING_NS_CC;

using namespace std;

using namespace cocos2d::ui;


class Maps : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void AddObject(Button **Exemplar, string Way, int x, int y, int v);
	void River1();
	void River2();
	void River3();
	void River4();
	void River5();
	void River6();
	void River7();
	void River8();
	void River9();
	void River10();
	void River11();
	void River12();
	void outText1();
	void FinishFalse();
	void FinishTrue();
	void Component_Exit();
	void RiverComponentVisible(bool type);
	void StartLocation(string str);
	void Baza();
	void VisibleBaza(bool VisibleBazaForEat);
	vector<string> ReturnVectorWriteTheLine(const char* text);
	void ReadWithFile(string str, vector<string> *vec);
	void FOutTextFishEat(string text, string type, int textSize, int x, int y);
	void buttonClickExit(Ref *ref);
	void buttonClickStartRiver(Ref *ref);
	void buttonClickFishingRod(Ref *ref);
	void buttonClickEat(Ref *ref);
	void buttonClickEatMenuOK(Ref *ref);
	void exampleLabelMenu();
	void Click_lbl0(int i);
	void StartProcesTime();
	void WriteInFileZ(string str, string type);
	void ReadInFileZ(string str, string *type);
	void WriteluggageForFishing();
	void EatMenuOK();
	void buttonClickOutFishOk(Ref *ref);
	void buttonClickOutFishOkTrue(Ref *ref);
	void buttonClickOutFishOkProblem(Ref *ref);
	string OutFishImage();
	void ProblemLure();
	int ReadInFile1(string s);
	void OptionsCatchFish();
	void StartMusicFont();
	void StartMusicEffect();

	string *pString = nullptr;
	vector<string> *pV = nullptr;
	

	CREATE_FUNC(Maps);

private:
	void initMouse();
	void initDial();
	void initDrawNode();
	void mousePress(Vec2 touch);
	void onEnterCatchFish();
	void onExitCatchFish();
	void onFishStart();
	void onFishTake();
	void startAnimationSwimmer();
	void startAnimationDown();
	void stopAnimations();
	void onCatchFish();
	void catchFishController();
	void onLeaveFish();
	void ReadWithFileFishLure();
	void getTOPLure();
	float getRandTimeFloat();
	string TypeFish();
	int SizeFish();
	int To_Massa(vector<string> *vec, int type);

	struct Dial {
		Sprite *speed = nullptr;
		Sprite *arrow = nullptr;
	} dial;
	DrawNode *drawLine;
	Sprite *Location, *MenuBaza;
	Button *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *r12;
	Button *StartVolga, *StartBalay, *StartAdyi, *Exit;
	enum River { R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12 } river;
	string NumberRiver;
	bool VisibleRiver, OneTochka = true;
	Button *FishingRod, *Eat, *CatchFish, *Down, *EatOK;
	Sprite *Rod = nullptr, *Tochka, *TochkaWhite = nullptr, *EatMenu;
	int CountFishingRod = 0;
	vector<string> FishingEat;
	string path = FileUtils::getInstance()->getWritablePath();
	bool ATrueFile = true;
	vector<Label*> OutTextFishingEat;
	string Lure = "bread";
	bool isActive = true;
	Action *repeatFish = nullptr;
	Menu *m;
	bool StartT = false;
	vector<string> FishLure;
	string pathFileLure = FileUtils::getInstance()->getWritablePath();
	bool ES = false;
	string Z, trueCatchFish;
	vector<string> helpPredmet, helpWord, typeFish;
	vector<string> fishMassa;
	vector <int> *pVi = nullptr;
	vector<string> luggageForFishing;
	Sprite *Text1, *outFish;
	Button *outFishOk;
	string TypeF, LURE; Sprite *fishT;
	int sizeF, L;
	string W, WW;
	float FFF;
	SimpleAudioEngine *audio, *start;
};

