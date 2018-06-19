#pragma once
#include "cocos2d.h"
#include "cocos2d/cocos/ui/CocosGUI.h"
#include <string>
#include "Jus.h"

USING_NS_CC;
using namespace cocos2d::ui;
using std::string;

class Main_Menu: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void InitExit();
	void InitLocation();
	void InitInventar();
	void InitMagaz();
	void InitRinok();
	void buttonClickExit(Ref *ref);
	void buttonClickLocation(Ref *ref);
	void buttonClickInventar(Ref *ref);
	void buttonClickMagaz(Ref *ref);
	void buttonClickRinok(Ref *ref);
	

	CREATE_FUNC(Main_Menu);

private:
	Button *Exit, *Location, *Inventar, *Magaz, *Rinok;
};

