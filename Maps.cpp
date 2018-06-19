#include "Maps.h"

Scene* Maps::createScene()
{
	return Maps::create();
}

void Maps::exampleLabelMenu() 
{
	int count = FishingEat.size();
	vector<MenuItemLabel*> vec;
	vec.resize(count);

	for (int i = 1; i < count; i++)
	{
		auto lb0 = Label::createWithTTF(FishingEat.at(i), "fonts/arial.ttf", 22);
		lb0->setTextColor(Color4B::BLACK);
		int k = i - 1;	
		vec.at(k) = MenuItemLabel::create(lb0, [=](Ref *ref) { Click_lbl0(i); });

	}

	switch (count)
	{
	case 2: m = Menu::create(vec.at(0), nullptr);
		break;
	case 3: m = Menu::create(vec.at(0), vec.at(1), nullptr);
		break;
	case 4: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), nullptr);
		break;
	case 5: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), nullptr);
		break;
	case 6: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), nullptr);
		break;
	case 7: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), nullptr);
		break;
	case 8: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), vec.at(6), nullptr);
		break;
	case 9: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), vec.at(6), vec.at(7), nullptr);
		break;
	case 10: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), vec.at(6), vec.at(7), vec.at(8), nullptr);
		break;
	case 11: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), vec.at(6), vec.at(7), vec.at(8), vec.at(9), nullptr);
		break;
	case 12: m = Menu::create(vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), vec.at(6), vec.at(7), vec.at(8), vec.at(9), vec.at(10), nullptr);
		break;
	}

	m->alignItemsVerticallyWithPadding(10);
	m->setPosition(Jus::getDisplayPoint(0.500,0.300));
//	m->setPosition(Vec2(500, 300));
	addChild(m, 4);

	
}

void Maps::Click_lbl0(int i)
{
	Lure = FishingEat.at(i);
	WriteluggageForFishing();
}

void Maps::WriteluggageForFishing()
{
	luggageForFishing.at(5) = Lure;
	int n = luggageForFishing.size();
	string str;
	for (int i = 0; i < n-1; i++)
	{
		str += luggageForFishing.at(i) + "\n";
	}
	WriteInFileZ("luggageForFishing.txt", str);
}

void Maps::getTOPLure()
{
	if (Lure == helpPredmet.at(49)) { WW = "FishOnWorm.txt"; W = "intWorm.txt"; }
	if (Lure == helpPredmet.at(48)) { WW = "FishOnBread.txt"; W = "intBread.txt"; }
	if (Lure == helpPredmet.at(50)) { WW = "FishOnCorn.txt"; W = "intCorn.txt"; }
	if (Lure == helpPredmet.at(53)) { WW = "FishOnMeat.txt"; W = "intMeat.txt";}
	if (Lure == helpPredmet.at(51)) { WW = "FishOnDough.txt"; W = "intDough.txt";}
	if (Lure == helpPredmet.at(52)) { WW = "FishOnFish.txt"; W = "intFish.txt";}
	if (Lure == helpPredmet.at(54)) { WW = "FishOnOparish.txt"; W = "intOparish.txt";}
	if (Lure == helpPredmet.at(55)) { WW = "FishOnPerlovka.txt"; W = "intPerlovka.txt";}
	if (Lure == helpPredmet.at(56)) { WW = "FishOnTvister.txt"; W = "intTvister.txt";}
}

bool Maps::init()
{ 
	if (!Scene::init())
	{
		return false;
	}

	//3.0f - час в секундах, unique_name - унікальне імя
//	schedule([=](float dt) {
//		cocos2d::log("Call scheduller [delay %f]", dt);
		//виключити 
//		unschedule("unique_name");
//	}, 3.0f, "unique_name");
	//scheduleOnce - викликати тільки один раз
	auto visibleSize = Director::getInstance()->getVisibleSize();

	pString = &Z;
	ReadInFileZ("Z.txt", pString);
	log("o");
	if (Z == "Exit")
	{
		auto menuImage = Sprite::create("FontShop.jpg");
		menuImage->setPosition(visibleSize / 2);
		addChild(menuImage, 0);

		outText1();
		River1();
		River2();
		River3();
		River4();
		River5();
		River6();
		River7();
		River8();
		River9();
		River10();
		River11();
		River12();
		Component_Exit();
		catchFishController();
	}
	else
	{
		StartLocation(Z);
		Baza();
		Component_Exit();
		catchFishController();
	}

	pString = nullptr;
	pV = &helpPredmet;
	ReadWithFile("helpPredmet.txt", pV);
	pV = &luggageForFishing;
	ReadWithFile("luggageForFishing.txt", pV);
	Lure = luggageForFishing.at(5);
	getTOPLure();
	L = ReadInFile1(W);
	pV = &helpWord;
	ReadWithFile("helpWord.txt", pV);
	pV = &fishMassa;
	if (L <= 0)
	{
		ProblemLure();
	}
	ReadWithFile("fishMasa.txt", pV);
	pV = nullptr;

	return true;
}

void Maps::StartMusicFont()
{
	audio =  SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Z.mp3", true);
}

void Maps::StartMusicEffect()
{
	start = SimpleAudioEngine::getInstance();
	start->playEffect("S.mp3", false, 1.0f, 1.0f, 1.0f);
}

int Maps::ReadInFile1(string str)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	int type;
	ifstream file(s);
	file >> type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
	return type;
}

void Maps::ProblemLure()
{
	outFish = Sprite::create("outFish.png");
	outFish->setPosition(Jus::getCenter());
	addChild(outFish, 10);

	string str = helpWord.at(18) + "\n" + helpWord.at(19) + "\n" + helpWord.at(20) + "\n" + helpWord.at(21) + "\n" + helpWord.at(22);
	auto label = Label::createWithTTF(str, "fonts/arial.ttf", 20);
	label->setColor(Color3B::WHITE);
	label->setPosition(Jus::getCenter());
	addChild(label, 11);

	outFishOk = Button::create("outFishOk.png");
	//outFishOk->setPosition(Vec2(610, 230));
	outFishOk->setPosition(Jus::getDisplayPoint(0.610, 0.230));
	addChild(outFishOk, 11);
	outFishOk->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickOutFishOkProblem, this));
}

void Maps::buttonClickOutFishOkProblem(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Main_Menu::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
	WriteInFileZ("Z.txt", "Exit");
	if(audio)
	audio->stopBackgroundMusic();
}

void Maps::AddObject(Button **Exemplar, string Way, int x, int y, int v)
{
	if (*Exemplar == nullptr)
	{
		*Exemplar = Button::create(Way);
		(*Exemplar)->setPosition(Vec2(x, y));
		addChild(*Exemplar, v);
	}
}

void Maps::River1() 
{
	Vec2 x(Jus::getDisplayPoint(0.315, 0.380));
	AddObject(&r1, "aktai.png", x.x, x.y, 1);
	r1->addClickEventListener([&](Ref *ref) { river = R1; buttonClickStartRiver(ref); });
}

void Maps::River2()
{
	Vec2 x(Jus::getDisplayPoint(0.315, 0.300));
	AddObject(&r2, "brusianka.png", x.x, x.y, 1);
	r2->addClickEventListener([&](Ref *ref) { river = R2; buttonClickStartRiver(ref); });
}

void Maps::River3()
{
	Vec2 x(Jus::getDisplayPoint(0.315, 0.220));
	AddObject(&r3, "byg.png", x.x, x.y, 1);
	r3->addClickEventListener([&](Ref *ref) { river = R3; buttonClickStartRiver(ref); });
}

void Maps::River4()
{
	Vec2 x(Jus::getDisplayPoint(0.315, 0.140));
	AddObject(&r4, "desna.png", x.x, x.y, 1);
	r4->addClickEventListener([&](Ref *ref) { river = R4; buttonClickStartRiver(ref); });
}

void Maps::River5()
{
	Vec2 x(Jus::getDisplayPoint(0.515, 0.380));
	AddObject(&r5, "iordan.png", x.x, x.y, 1);
	r5->addClickEventListener([&](Ref *ref) { river = R5; buttonClickStartRiver(ref); });
}

void Maps::River6()
{
	Vec2 x(Jus::getDisplayPoint(0.515, 0.300));
	AddObject(&r6, "krok.png", x.x, x.y, 1);
	r6->addClickEventListener([&](Ref *ref) { river = R6; buttonClickStartRiver(ref); });
}

void Maps::River7()
{
	Vec2 x(Jus::getDisplayPoint(0.515, 0.220));
	AddObject(&r7, "lomina.png", x.x, x.y, 1);
	r7->addClickEventListener([&](Ref *ref) { river = R7; buttonClickStartRiver(ref); });
}

void Maps::River8()
{
	Vec2 x(Jus::getDisplayPoint(0.515, 0.140));
	AddObject(&r8, "sirka.png", x.x, x.y, 1);
	r8->addClickEventListener([&](Ref *ref) { river = R8; buttonClickStartRiver(ref); });
}

void Maps::River9()
{
	Vec2 x(Jus::getDisplayPoint(0.715, 0.380));
	AddObject(&r9, "vagran.png", x.x, x.y, 1);
	r9->addClickEventListener([&](Ref *ref) { river = R9; buttonClickStartRiver(ref); });
}

void Maps::River10()
{
	Vec2 x(Jus::getDisplayPoint(0.715, 0.300));
	AddObject(&r10, "vilva.png", x.x, x.y, 1);
	r10->addClickEventListener([&](Ref *ref) { river = R10; buttonClickStartRiver(ref); });
}

void Maps::River11()
{
	Vec2 x(Jus::getDisplayPoint(0.715, 0.220));
	AddObject(&r11, "yraika.png", x.x, x.y, 1);
	r11->addClickEventListener([&](Ref *ref) { river = R11; buttonClickStartRiver(ref); });
}

void Maps::River12()
{
	Vec2 x(Jus::getDisplayPoint(0.715, 0.140));
	AddObject(&r12, "volga.png", x.x, x.y, 1);
	r12->addClickEventListener([&](Ref *ref) { river = R12; buttonClickStartRiver(ref); });
}

void Maps::buttonClickStartRiver(Ref *ref)
{
	switch (river)
	{
	case R1: NumberRiver = "1.jpg";//
		break;
	case R2: NumberRiver = "2.jpg";
		break;
	case R3: NumberRiver = "5.jpg";
		break;
	case R4: NumberRiver = "10.jpg";
		break;
	case R5: NumberRiver = "12.jpg";
		break;
	case R6: NumberRiver = "9.jpg";
		break;
	case R7: NumberRiver = "7.jpg";
		break;
	case R8: NumberRiver = "11.jpg";
		break;
	case R9: NumberRiver = "3.jpg";
		break;
	case R10: NumberRiver = "4.jpg";
		break;
	case R11: NumberRiver = "8.jpg";
		break;
	case R12: NumberRiver = "6.jpg";
		break;
	}

	RiverComponentVisible(false);

	StartLocation(NumberRiver);

	Baza();


	Z = NumberRiver;
	WriteInFileZ("Z.txt", Z);
}

void Maps::outText1()
{
	Text1 = Sprite::create("text1.png");
	//Text1->setPosition(Vec2(500, 450));
	Text1->setPosition(Jus::getDisplayPoint(0.500, 0.450));
	addChild(Text1, 1);
}

void Maps::Component_Exit()
{
	Exit = Button::create("exit.png");
//	Exit->setPosition(Vec2(780, 470));
	Exit->setPosition(Jus::getDisplayPoint(0.780,0.470));
	addChild(Exit, 15);
	Exit->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickExit, this));
}

void Maps::buttonClickExit(Ref *ref) 
{
	auto director = Director::getInstance();
	auto scene = Main_Menu::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
	WriteInFileZ("Z.txt", "Exit");
	audio->stopBackgroundMusic();
}


void Maps::WriteInFileZ(string str, string type)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	ofstream file(s, ios_base::trunc);
	file << type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
}

void Maps::ReadInFileZ(string str, string *type)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	ifstream file(s);
	file >> *type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
}

void Maps::StartLocation(string str)
{
	Location = Sprite::create(str);
	//Location->setPosition(Vec2(512, 300));
	Location->setPosition(Jus::getDisplayPoint(0.5,0.5));
	addChild(Location, 2);
}

void Maps::RiverComponentVisible(bool type)
{	
	r1->setVisible(type);
	r2->setVisible(type);
	r3->setVisible(type);
	r4->setVisible(type);
	r5->setVisible(type);
	r6->setVisible(type);
	r7->setVisible(type);
	r8->setVisible(type);
	r9->setVisible(type);
	r10->setVisible(type);
	r11->setVisible(type);
	r12->setVisible(type);
	Text1->setVisible(type);
}

void Maps::initDial() {
	dial.speed = Sprite::create("speed.png");
	dial.arrow = Sprite::create("arrow.png");

	dial.speed->setScale(0.26);
	dial.arrow->setScale(0.26);

	dial.speed->setPosition(Jus::getDisplayPoint(0.718, 0.165));
	dial.arrow->setPosition(Jus::getDisplayPoint(0.718, 0.165));

	dial.speed->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	dial.arrow->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

	addChild(dial.speed, 9);
	addChild(dial.arrow, 9);
}

void Maps::Baza()
{
	StartMusicFont();
	MenuBaza = Sprite::create("baza.png");
	//MenuBaza->setPosition(Vec2(512, 130));
	MenuBaza->setPosition(Jus::getDisplayPoint(0.512, 0.130));
	addChild(MenuBaza, 2);

	FishingRod = Button::create("FishingRod.png");
	FishingRod->setScale(0.9,0.9);
	//FishingRod->setPosition(Vec2(225, 125));
	FishingRod->setPosition(Jus::getDisplayPoint(0.225,0.125));
	addChild(FishingRod, 2);
	FishingRod->addClickEventListener([&](Ref *ref) { CountFishingRod++; buttonClickFishingRod(ref);});

	Eat = Button::create("Eat.png");
	Eat->setScale(0.9, 0.9);
	//Eat->setPosition(Vec2(295, 125));
	Eat->setPosition(Jus::getDisplayPoint(0.295,.125));
	addChild(Eat, 2);
	Eat->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickEat, this));
	
	initDial();
	initDrawNode();

	isActive = false;
	CatchFish = Button::create("CatchFish.png");
	CatchFish->setScale(0.9, 0.9);
	CatchFish->addTouchEventListener([&](cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type) {
		if (!isActive)
			return;

		switch (type) {
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
			onEnterCatchFish();
			break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
			case cocos2d::ui::Widget::TouchEventType::CANCELED:
			onExitCatchFish();
			break;
		}
	}); 
	//CatchFish->setPosition(Vec2(805, 125));
	CatchFish->setPosition(Jus::getDisplayPoint(0.805,0.125));
	addChild(CatchFish, 2);
	
	Rod = Sprite::create("rood1.png");
	//Rod->setPosition(Vec2(500, 150));
	Rod->setPosition(Jus::getDisplayPoint(0.500,0.150));
	addChild(Rod, 2);

	if (OneTochka = true) { initMouse(); }
	



}

void Maps::onExitCatchFish() {
	startAnimationDown();
}

void Maps::onEnterCatchFish() {
	dial.arrow->stopAllActions();
	
	auto rotUp = RotateTo::create(0.7, 90);
	auto callback = CallFunc::create([&] { onLeaveFish(); });
	dial.arrow->runAction(Sequence::create(rotUp, callback, nullptr));
}

void Maps::buttonClickEat(Ref *ref)
{
	if (TochkaWhite)
	{
		TochkaWhite->setVisible(false);
		drawLine->setVisible(false);
		OneTochka = false;
	}
	EatMenu = Sprite::create("BoardEit.png");
	EatMenu->setPosition(Jus::getCenter());
	addChild(EatMenu, 3);
	pV = &FishingEat;
	ReadWithFile("luggageForShopLure.txt", pV);
	pV = nullptr;
	VisibleBaza(false);
	EatMenuOK();
	exampleLabelMenu();
}

void Maps::EatMenuOK()
{
	EatOK = Button::create("Component_OK.png");
	//EatOK->setPosition(Vec2(605,170));
	EatOK->setPosition(Jus::getDisplayPoint(0.605,0.170));
	addChild(EatOK, 3);
	EatOK->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickEatMenuOK, this));
}

void Maps::buttonClickEatMenuOK(Ref *ref)
{
	EatMenu->setVisible(false);
	EatMenu = nullptr;
	EatOK->setVisible(false);
	EatOK = nullptr;
	VisibleBaza(true);
	FishingEat.clear();
	m->removeFromParent();
	_director->replaceScene(Maps::createScene());
}

void Maps::VisibleBaza(bool VisibleBazaForEat)
{
	FishingRod->setVisible(VisibleBazaForEat);
	Eat->setVisible(VisibleBazaForEat);
	CatchFish->setVisible(VisibleBazaForEat);
	MenuBaza->setVisible(VisibleBazaForEat);
	Rod->setVisible(VisibleBazaForEat);
	dial.speed->setVisible(VisibleBazaForEat);
	dial.arrow->setVisible(VisibleBazaForEat);
	OneTochka = VisibleBazaForEat;
}

void Maps::buttonClickFishingRod(Ref *ref)
{
	if (ES == true) {
		_director->replaceScene(Maps::createScene());
	}

	if (CountFishingRod % 2 != 0)
	{
		Rod->setVisible(false);
		OneTochka = false;
		if (TochkaWhite)
		{
			TochkaWhite->setVisible(false);
			drawLine->setVisible(false);
			ES = true;
		}
	}
	else {
		Rod->setVisible(true);	
		OneTochka = true;
	} 

}

void Maps::initDrawNode() {
	drawLine = DrawNode::create(1);
	drawLine->setPosition(Vec2::ZERO);
	addChild(drawLine, 10);
	schedule([&](float) {
		if (Rod && TochkaWhite) {
			drawLine->clear();
			Vec2 p1 = Rod->getPosition();
			p1.y += Rod->getContentSize().height / 2;
			
			drawLine->drawLine(p1, TochkaWhite->getPosition(), Color4F::WHITE);
		}
	}, 1.0/40, "draw_line");
}

void Maps::onFishStart() {
	log("onFishStart");
	auto ScaleYStart = ScaleTo::create(0.3, 1, 1.5, 1);
	auto ScaleYFinish = ScaleTo::create(0.3, 1, 1, 1);
	auto moveR = MoveBy::create(0.7, Vec2(-20, 0));
	auto moveL = MoveBy::create(0.7, Vec2( 20, 0));

	auto sequenceScaler = Sequence::create(ScaleYStart, ScaleYFinish, nullptr);
	auto sequenceMover  = Sequence::create(moveR, moveL, nullptr);
	repeatFish = RepeatForever::create(Spawn::create(sequenceScaler, sequenceMover, nullptr));
	TochkaWhite->runAction(repeatFish);
	startAnimationDown();
	startAnimationSwimmer();
}

void Maps::startAnimationDown() {
	log("onFishStart");
	auto rotDown = RotateTo::create(FFF, -90);
	auto callback = CallFunc::create([&] { onLeaveFish(); });
	dial.arrow->stopAllActions();
	dial.arrow->runAction(Sequence::create(rotDown, callback, nullptr));
}

void Maps::stopAnimations() {
	dial.arrow->stopAllActions();
	if (TochkaWhite)
		TochkaWhite->stopAllActions();
}
void Maps::onCatchFish() {
	stopAnimations();
	TochkaWhite->removeFromParent();
	TochkaWhite = nullptr;
	drawLine->removeFromParent();
	drawLine = nullptr;
	isActive = false;
	log("Fish was catched");
	FinishTrue();

}

void Maps::FinishTrue()
{
	outFish = Sprite::create("outFish.png");
	outFish->setPosition(Jus::getCenter());
	addChild(outFish, 10);

	string str = TypeF + "\n\n\n\n\n\n\n" + to_string(sizeF) + helpWord.at(17);
	auto label = Label::createWithTTF(str, "fonts/arial.ttf", 20);
	label->setColor(Color3B::WHITE);
	label->setPosition(Jus::getCenter());
	addChild(label, 11);

	string way = OutFishImage();
	fishT = Sprite::create(way);
	fishT->setPosition(Jus::getCenter());
	addChild(fishT, 15);

	outFishOk = Button::create("outFishOk.png");
	//outFishOk->setPosition(Vec2(610, 230));
	outFishOk->setPosition(Jus::getDisplayPoint(0.610,0.230));
	addChild(outFishOk, 11);
	outFishOk->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickOutFishOkTrue, this));

}

void Maps::buttonClickOutFishOkTrue(Ref *ref)
{
	L--;
	string str = to_string(L);
	WriteInFileZ(W, str);
	_director->replaceScene(Maps::createScene());
}

string Maps::OutFishImage()
{
	pV = &typeFish;
	ReadWithFile("Fish.txt", pV);
	pV = nullptr;
	int n = typeFish.size(), k(0), t(0);
	for (int i = 0; i < n-1; i++)
	{
		if (TypeF == typeFish.at(i)) {
			t = k; break; }
		k++;
	}
	string a = fishMassa.at(t);
	int b = atoi(a.c_str());
	sizeF += b;
	fishMassa.at(t) = to_string(sizeF);
	string s;
	int m = fishMassa.size();
	for (int i = 0; i < m - 1; i++)
	{
		s += fishMassa.at(i) + "\n";
	}
	WriteInFileZ("fishMasa.txt", s); 
	string str = "f" + to_string(t) + ".png";
	return str;
}

void Maps::catchFishController() {
	schedule([&](float) {
		if (Rod && TochkaWhite) {
			Vec2 posRod = Rod->getPosition() + Vec2(0, Rod->getContentSize().height / 2);
			if (posRod.distance(TochkaWhite->getPosition()) < Jus::getWidth() / 100.f * 1) {
				onCatchFish();
				unschedule("controll_catch");
			}
		}
	}, 1.0f / 60, "controll_catch");
}

void Maps::onLeaveFish() {
	stopAnimations();
	TochkaWhite->removeFromParent();
	TochkaWhite = nullptr;
	drawLine->removeFromParent();
	drawLine = nullptr;
	isActive = false;
	log("FUCKING FISHING!!!");
	FinishFalse();
}

void Maps::FinishFalse()
{
	outFish = Sprite::create("outFishFalse.png");
	outFish->setPosition(Jus::getCenter());
	addChild(outFish, 10);

	string str = helpWord.at(16);
	auto label = Label::createWithTTF(str, "fonts/arial.ttf", 30);
	label->setColor(Color3B::WHITE);
	label->setPosition(Jus::getCenter());
	addChild(label, 11);

	outFishOk = Button::create("outFishOk.png");
	//outFishOk->setPosition(Vec2(610,275));
	outFishOk->setPosition(Jus::getDisplayPoint(0.610,0.275));
	addChild(outFishOk, 11);
	outFishOk->addClickEventListener(CC_CALLBACK_1(Maps::buttonClickOutFishOk, this));

}

void Maps::buttonClickOutFishOk(Ref *ref)
{
	L--;
	string str = to_string(L);
	//WriteInFileZ(W, str);
	_director->replaceScene(Maps::createScene());
}

void Maps::startAnimationSwimmer() {
	Vec2 finishPos = Rod->getPosition() + Vec2(0, Rod->getContentSize().height / 2);
	auto moveSwimmer = MoveTo::create(finishPos.distance(TochkaWhite->getPosition()) / 8, finishPos);
	TochkaWhite->runAction(moveSwimmer);

}

void Maps::onFishTake() {
	
	startAnimationSwimmer();

}

void Maps::StartProcesTime()
{
	float time = getRandTimeFloat();
	//time = 3.0f;
	scheduleOnce([=](float dt) {
		if (CountFishingRod % 2 == 0)
		{
			cocos2d::log("Call scheduller [delay %f]", dt);
			StartMusicEffect();
			isActive = true;
			FishingRod->setVisible(false);
			Eat->setVisible(false);
			TypeF = TypeFish();
			sizeF = SizeFish();
			OptionsCatchFish();
			log("Type %s", TypeF.c_str());
			log("size %d", sizeF);
			onFishStart();
		}
		else
		{
			cocos2d::log("Poxyi [delay %f]", dt);
			ES = true;
		}
		
		
	}, time, "unique_name");

}

void Maps::OptionsCatchFish()
{
	if (sizeF < 10001) { FFF = 0.45; }
	if (sizeF < 5000) { FFF = 0.5; }
	if (sizeF < 2000) { FFF = 0.6; }
	if (sizeF < 1000) { FFF = 0.7; }
	if (sizeF < 200) { FFF = 0.9; }
}

float Maps::getRandTimeFloat()
{
	float t = cocos2d::random(5.0f, 20.0f);
	log("t = %f", t);
	return t;
}

string Maps::TypeFish()
{
	ReadWithFileFishLure();
	int count = FishLure.size();
	int ram = cocos2d::random(0, count-2);
	string Type = FishLure.at(ram);
	return Type;
}

int Maps::SizeFish()
{
	int massa(0);
	pV = &luggageForFishing;
	int rood = To_Massa(pV, 1);
	int coil = To_Massa(pV, 2);
	int line = To_Massa(pV, 3);
	int hook = To_Massa(pV, 4);

	if ((rood <= coil) && (rood <= line) && (rood <= hook)) { massa = rood; }
	if ((coil <= rood) && (coil <= line) && (coil <= hook)) { massa = coil; }
	if ((line <= coil) && (line <= rood) && (line <= hook)) { massa = line; }
	if ((hook <= coil) && (hook <= line) && (hook <= rood)) { massa = hook; }

	int t = cocos2d::random(100, massa);
	return t;	
}

int Maps::To_Massa(vector<string> *vec, int type)
{
	int massa = 0;
	int n1(0), n2(0);
	vector<string> V = *vec;
	switch (type)
	{
	case 1: n1 = 0; n2 = 11;
		break;
	case 2: n1 = 12; n2 = 23;
		break;
	case 3: n1 = 24; n2 = 35;
		break;
	case 4: n1 = 36; n2 = 47;
		break;
	default: 
		break;
	}

	int k = 0;

	for (int i = n1; i < n2; i++)
	{
		if (V.at(type) == helpPredmet.at(i) ) 
		{
			if (k == 0) { massa = 500; break; }
			if (k == 1) { massa = 800; break;}
			if (k == 2) { massa = 1000; break;}
			if (k == 3) { massa = 1500; break;}
			if (k == 4) { massa = 2000; break;}
			if (k == 5) { massa = 2500; break;}
			if (k == 6) { massa = 4000; break;}
			if (k == 7) { massa = 5000; break;}
			if (k == 8) { massa = 6000; break;}
			if (k == 9) { massa = 7000; break;}
			if (k == 10) { massa = 10000; break;}
		}
		k++;
	}
	return massa;
}

//------------------------------------------FILE-----------------------------------------------------
vector<string> Maps::ReturnVectorWriteTheLine(const char* text)
{
	const char* ReadFileText = text;
	vector<string> result;
	string line;

	while (*ReadFileText)
	{
		if (*ReadFileText != '\n')
			line += *ReadFileText;
		else if (!line.empty()) {
			result.push_back(line);
			line.clear();
		}

		++ReadFileText;
	}

	if (!line.empty()) {
		result.push_back(line);
		line.clear();
	}
	return result;
}

void Maps::ReadWithFile(string str, vector<string> *vec)
{
	string way = FileUtils::getInstance()->getWritablePath();
	way += str;

	ifstream fileFishingEat(way);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	*vec = ReturnVectorWriteTheLine(buffer);
	way = FileUtils::getInstance()->getWritablePath();
	delete[]buffer;
}

void Maps::ReadWithFileFishLure()
{
	getTOPLure();
	pathFileLure = FileUtils::getInstance()->getWritablePath();
	pathFileLure += WW;
	
	ifstream fileFishingEat(pathFileLure);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	FishLure = ReturnVectorWriteTheLine(buffer);
	pathFileLure = FileUtils::getInstance()->getWritablePath();
	delete[]buffer;
}

void Maps::FOutTextFishEat(string text, string type, int textSize, int x, int y)
{
	//log("Uot text  %s", text.c_str());
	auto label = Label::createWithTTF(text, type, textSize);
	label->setColor(Color3B::BLACK);
	label->setPosition(x, y);
	OutTextFishingEat.push_back(label);
	addChild(*OutTextFishingEat.rbegin(), 4);
}



//------------------------------------------MOUSE----------------------------------------------------
void Maps::initMouse() {
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [&](Touch *t, Event *) -> bool { mousePress(convertToNodeSpace(t->getLocation())); return true;};
	//listener->onTouchMoved = [&](Touch *t, Event *) -> void { mouseMove(convertToNodeSpace(t->getLocation())); };
	//listener->onTouchEnded = [&](Touch *t, Event *) -> void { mouseEnd(convertToNodeSpace(t->getLocation())); };

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void Maps::mousePress(Vec2 touch) {
	const float maxDist = Jus::getSize().height * 0.3F;
	const float minDist = Jus::getSize().height * 0.05F;
	const Vec2  destination = Rod->getPosition() + Vec2(0, Rod->getContentSize().height / 2);
	const float dist = touch.distance(destination);

	if (OneTochka == true) {
		if (dist < maxDist && dist >= minDist) {
			TochkaWhite = Sprite::create("TochkaP.png");
			TochkaWhite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
			TochkaWhite->setPosition(touch);
			addChild(TochkaWhite, 3);
			OneTochka = false;
			StartProcesTime();
		}
		else if (dist < minDist) {
			//якщо дистанція менша за мінімальну
		}
		else {
			//якщо дистанція білша за максимальну
		}
	}
	else
	{
		log("TakeRood");
		ES = true;
	}
}






