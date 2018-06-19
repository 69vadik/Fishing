#include "Main_Menu.h"
#include "Maps.h"
#include "Market.h"
#include "Inventory.h"
#include "Shop.h"

Scene* Main_Menu::createScene()
{
	return Main_Menu::create();
}

bool Main_Menu::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto menuImage = Sprite::create("FontMenu.png");
	menuImage->setPosition(visibleSize/2);
	addChild(menuImage, 0);

	InitExit();
	InitLocation();
	InitInventar();
	InitMagaz();
	InitRinok();

	return true;
}

void Main_Menu::InitExit()
{
	Exit = Button::create("mExit.png");
	//Exit->setPosition(Vec2(740, 450));
	Exit->setPosition(Jus::getDisplayPoint(0.740,0.450));
	addChild(Exit, 5);
	Exit->addClickEventListener(CC_CALLBACK_1(Main_Menu::buttonClickExit, this));
}

void Main_Menu::InitLocation()
{
	Location = Button::create("m1.png");
	//Location->setPosition(Vec2(340, 430));
	Location->setPosition(Jus::getDisplayPoint(0.340,0.430));
	addChild(Location, 5);
	Location->addClickEventListener(CC_CALLBACK_1(Main_Menu::buttonClickLocation, this));
}

void Main_Menu::InitRinok()
{
	Rinok = Button::create("m2.png");
	//Rinok->setPosition(Vec2(340, 340));
	Rinok->setPosition(Jus::getDisplayPoint(0.340,0.340));
	addChild(Rinok, 5);
	Rinok->addClickEventListener(CC_CALLBACK_1(Main_Menu::buttonClickRinok, this));
}

void Main_Menu::InitInventar()
{
	Inventar = Button::create("m3.png");
	//Inventar->setPosition(Vec2(340, 250));
	Inventar->setPosition(Jus::getDisplayPoint(0.340,0.250));
	addChild(Inventar, 5);
	Inventar->addClickEventListener(CC_CALLBACK_1(Main_Menu::buttonClickInventar, this));
}

void Main_Menu::InitMagaz()
{
	Magaz = Button::create("m4.png");
	//Magaz->setPosition(Vec2(340, 160));
	Magaz->setPosition(Jus::getDisplayPoint(0.340,0.160));
	addChild(Magaz, 5);
	Magaz->addClickEventListener(CC_CALLBACK_1(Main_Menu::buttonClickMagaz, this));
}

void Main_Menu::buttonClickExit(Ref *ref) 
{
	Director::getInstance()->end();
}

void Main_Menu::buttonClickLocation(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Maps::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}

void Main_Menu::buttonClickRinok(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Market::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}

void Main_Menu::buttonClickInventar(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Inventory::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}

void Main_Menu::buttonClickMagaz(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Shop::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}










/*
Exit = Button::create("Component_Exit.png");
Exit->setPosition(Vec2(800, 450));
addChild(Exit, 1);

void MenuScene::buttonClick(Ref *ref) {
auto director = Director::getInstance();
auto scene = MenuScene_2::create();
auto transition = TransitionCrossFade::create(1, scene);
director->replaceScene(transition);
log("button click");
}

void MenuScene::initButton_1() {
button_1 = Button::create("Menu_Component_1.png");
button_1->setPosition(Vec2(660, 390));
addChild(button_1, 1);
//std::function<void(Ref*)>
button_1->addClickEventListener(CC_CALLBACK_1(MenuScene::buttonClick, this));
}
*/