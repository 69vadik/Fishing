#include "Shop.h"

Scene* Shop::createScene()
{
	return Shop::create();
}

bool Shop::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto menuImage = Sprite::create("FontShop.jpg");
	menuImage->setPosition(visibleSize / 2);
	addChild(menuImage, 0);

	ButtonMRood();
	ButtonMLure();
	ButtonMLine();
	ButtonMHook();
	ButtonMCoil();
	path += "MRood.txt";
	ReadWithFile();
	exampleLabelMenu();
	ReadWithFileMoney();
	ReadWithFileHelpWord();
	outTextMoney();
	ReadWithFileHelpPredmet();
	ReadIntLure("intBread.txt", Ibread , Tbread);
	ReadIntLure("intCorn.txt", Icorn, Tcorn);
	ReadIntLure("intDough.txt", Idough, Tdough);
	ReadIntLure("intFish.txt", Ifish, Tfish);
	ReadIntLure("intMeat.txt", Imeat, Tmeat);
	ReadIntLure("intOparish.txt", Ioparish, Toparish);
	ReadIntLure("intPerlovka.txt", Iperlovka, Tperlovka);
	ReadIntLure("intTvister.txt", Itvister, Ttvister);
	ReadIntLure("intWorm.txt", Iworm, Tworm);
	InitExit();

	return true;
}

void Shop::InitExit()
{
	Exit = Button::create("exit.png");
	//Exit->setPosition(Vec2(780, 120));
	Exit->setPosition(Jus::getDisplayPoint(0.780,0.120));
	addChild(Exit, 5);
	Exit->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickExit, this));
}

void Shop::buttonClickExit(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Main_Menu::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}


void Shop::ButtonMRood()
{
	MRood = Button::create("MRood.png");
	//MRood->setPosition(Vec2(275, 470));
	MRood->setPosition(Jus::getDisplayPoint(0.275,0.470));
	addChild(MRood, 1);
	MRood->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickMRood, this));
}

void Shop::buttonClickMRood(Ref *ref) {
	typeShop = typeMRood;
		Count = 12;
		m->removeFromParent();
		path += "MRood.txt";
		FileForWrite.clear();
		ReadWithFile();
		exampleLabelMenu();
}

void Shop::ButtonMLure()
{
	MLure = Button::create("MLure.png");
	//MLure->setPosition(Vec2(275, 410));
	MLure->setPosition(Jus::getDisplayPoint(0.275,0.410));
	addChild(MLure, 1);
	MLure->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickMLure, this));
}

void Shop::buttonClickMLure(Ref *ref) {
	typeShop = typeMLure;
	Count = 9;
	m->removeFromParent();
	path += "MLure.txt";
	FileForWrite.clear();
	ReadWithFile();
	exampleLabelMenu(); 
}

void Shop::ButtonMLine()
{
	MLine = Button::create("MLine.png");
	//MLine->setPosition(Vec2(275, 350));
	MLine->setPosition(Jus::getDisplayPoint(0.275,0.350));
	addChild(MLine, 1);
	MLine->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickMLine, this));
}

void Shop::buttonClickMLine(Ref *ref) {	
	typeShop = typeMLine;
		Count = 12;
		m->removeFromParent();
		path += "MLine.txt";
		FileForWrite.clear();
		ReadWithFile();
		exampleLabelMenu();	
}

void Shop::ButtonMCoil()
{
	MCoil = Button::create("MCoil.png");
	//MCoil->setPosition(Vec2(275, 290));
	MCoil->setPosition(Jus::getDisplayPoint(0.275,0.290));
	addChild(MCoil, 1);
	MCoil->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickMCoil, this));
}

void Shop::buttonClickMCoil(Ref *ref) {
	typeShop = typeMCoil;
		Count = 12;
		m->removeFromParent();
		path += "MCoil.txt";
		FileForWrite.clear();
		ReadWithFile();
		exampleLabelMenu();
}

void Shop::ButtonMHook()
{
	MHook = Button::create("MHook.png");
	//MHook->setPosition(Vec2(275, 230));
	MHook->setPosition(Jus::getDisplayPoint(0.275,0.230));
	addChild(MHook, 1);
	MHook->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickMHook, this));
}

void Shop::buttonClickMHook(Ref *ref) {
	typeShop = typeMHook;
		Count = 12;
		m->removeFromParent();
		path += "MHook.txt";
		FileForWrite.clear();
		ReadWithFile();
		exampleLabelMenu();
}

void Shop::outTextMoney()
{
	string wordShop = HelpWord.at(0);
	mon = to_string(Money);
	wordShop = wordShop + "\n\n "+ HelpWord.at(1)+ "\n " + mon + HelpWord.at(2);
	labelouttext = Label::createWithTTF(wordShop, "fonts/arial.ttf", 20);
	labelouttext->setColor(Color3B::BLACK);
	//labelouttext->setPosition(260, 150);
	labelouttext->setPosition(Jus::getDisplayPoint(0.260,0.150));
	addChild(labelouttext, 3);
}

//------------------------------------------FILE-----------------------------------------------------
vector<string> Shop::ReturnVectorWriteTheLine(const char* text)
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

void Shop::ReadWithFile()
{

	ifstream fileFishingEat(path);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	FileForWrite = ReturnVectorWriteTheLine(buffer);
	path = FileUtils::getInstance()->getWritablePath();
	delete[]buffer;
}

void Shop::ReadWithFileHelpWord()
{
	pathHelpWord += "helpWord.txt";

	ifstream fileFishingEat(pathHelpWord);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	HelpWord = ReturnVectorWriteTheLine(buffer);
	pathHelpWord = FileUtils::getInstance()->getWritablePath();
	delete[]buffer;
}

void Shop::ReadWithFileHelpPredmet()
{
	pathHelpPredmet += "helpPredmet.txt";

	ifstream fileFishingEat(pathHelpPredmet);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	HelpPredmet = ReturnVectorWriteTheLine(buffer);
	pathHelpPredmet = FileUtils::getInstance()->getWritablePath();
	delete[]buffer;
}

void Shop::ReadWithFileMoney()
{
	pathMoney += "MONEY.txt";
	ifstream file(pathMoney);
	file >> Money;
	file.close();
	pathMoney = FileUtils::getInstance()->getWritablePath();
	log("Money = %d", Money);
}


//------------------------------------------------------------------------------------
void Shop::exampleLabelMenu()
{
	MenuItemLabel *label[12];

	if (Count == 12)
	{
		auto lb0 = Label::createWithTTF(FileForWrite.at(0), "fonts/arial.ttf", 18);
		lb0->setTextColor(Color4B::BLACK);
		label[0] = MenuItemLabel::create(lb0, [this](Ref *ref) { Click_lbl0(); });

		auto lb1 = Label::createWithTTF(FileForWrite.at(1), "fonts/arial.ttf", 18);
		lb1->setTextColor(Color4B::BLACK);
		label[1] = MenuItemLabel::create(lb1, [this](Ref *ref) { Click_lbl1(); });

		auto lb2 = Label::createWithTTF(FileForWrite.at(2), "fonts/arial.ttf", 18);
		lb2->setTextColor(Color4B::BLACK);
		label[2] = MenuItemLabel::create(lb2, [this](Ref *ref) { Click_lbl2(); });

		auto lb3 = Label::createWithTTF(FileForWrite.at(3), "fonts/arial.ttf", 18);
		lb3->setTextColor(Color4B::BLACK);
		label[3] = MenuItemLabel::create(lb3, [this](Ref *ref) { Click_lbl3(); });

		auto lb4 = Label::createWithTTF(FileForWrite.at(4), "fonts/arial.ttf", 18);
		lb4->setTextColor(Color4B::BLACK);
		label[4] = MenuItemLabel::create(lb4, [this](Ref *ref) { Click_lbl4(); });

		auto lb5 = Label::createWithTTF(FileForWrite.at(5), "fonts/arial.ttf", 18);
		lb5->setTextColor(Color4B::BLACK);
		label[5] = MenuItemLabel::create(lb5, [this](Ref *ref) { Click_lbl5(); });

		auto lb6 = Label::createWithTTF(FileForWrite.at(6), "fonts/arial.ttf", 18);
		lb6->setTextColor(Color4B::BLACK);
		label[6] = MenuItemLabel::create(lb6, [this](Ref *ref) { Click_lbl6(); });

		auto lb7 = Label::createWithTTF(FileForWrite.at(7), "fonts/arial.ttf", 18);
		lb7->setTextColor(Color4B::BLACK);
		label[7] = MenuItemLabel::create(lb7, [this](Ref *ref) { Click_lbl7(); });

		auto lb8 = Label::createWithTTF(FileForWrite.at(8), "fonts/arial.ttf", 18);
		lb8->setTextColor(Color4B::BLACK);
		label[8] = MenuItemLabel::create(lb8, [this](Ref *ref) { Click_lbl8(); });

		auto lb9 = Label::createWithTTF(FileForWrite.at(9), "fonts/arial.ttf", 18);
		lb9->setTextColor(Color4B::BLACK);
		label[9] = MenuItemLabel::create(lb9, [this](Ref *ref) { Click_lbl9(); });

		auto lb10 = Label::createWithTTF(FileForWrite.at(10), "fonts/arial.ttf", 18);
		lb10->setTextColor(Color4B::BLACK);
		label[10] = MenuItemLabel::create(lb10, [this](Ref *ref) { Click_lbl10(); });

		auto lb11 = Label::createWithTTF(FileForWrite.at(11), "fonts/arial.ttf", 18);
		lb11->setTextColor(Color4B::BLACK);
		label[11] = MenuItemLabel::create(lb11, [this](Ref *ref) { Click_lbl11(); });
	}
	if (Count == 9)
	{
		auto lb0 = Label::createWithTTF(FileForWrite.at(0), "fonts/arial.ttf", 20);
		lb0->setTextColor(Color4B::BLACK);
		label[0] = MenuItemLabel::create(lb0, [this](Ref *ref) { Click_lbl0(); });

		auto lb1 = Label::createWithTTF(FileForWrite.at(1), "fonts/arial.ttf", 20);
		lb1->setTextColor(Color4B::BLACK);
		label[1] = MenuItemLabel::create(lb1, [this](Ref *ref) { Click_lbl1(); });

		auto lb2 = Label::createWithTTF(FileForWrite.at(2), "fonts/arial.ttf", 20);
		lb2->setTextColor(Color4B::BLACK);
		label[2] = MenuItemLabel::create(lb2, [this](Ref *ref) { Click_lbl2(); });

		auto lb3 = Label::createWithTTF(FileForWrite.at(3), "fonts/arial.ttf", 20);
		lb3->setTextColor(Color4B::BLACK);
		label[3] = MenuItemLabel::create(lb3, [this](Ref *ref) { Click_lbl3(); });

		auto lb4 = Label::createWithTTF(FileForWrite.at(4), "fonts/arial.ttf", 20);
		lb4->setTextColor(Color4B::BLACK);
		label[4] = MenuItemLabel::create(lb4, [this](Ref *ref) { Click_lbl4(); });

		auto lb5 = Label::createWithTTF(FileForWrite.at(5), "fonts/arial.ttf", 20);
		lb5->setTextColor(Color4B::BLACK);
		label[5] = MenuItemLabel::create(lb5, [this](Ref *ref) { Click_lbl5(); });

		auto lb6 = Label::createWithTTF(FileForWrite.at(6), "fonts/arial.ttf", 20);
		lb6->setTextColor(Color4B::BLACK);
		label[6] = MenuItemLabel::create(lb6, [this](Ref *ref) { Click_lbl6(); });

		auto lb7 = Label::createWithTTF(FileForWrite.at(7), "fonts/arial.ttf", 20);
		lb7->setTextColor(Color4B::BLACK);
		label[7] = MenuItemLabel::create(lb7, [this](Ref *ref) { Click_lbl7(); });

		auto lb8 = Label::createWithTTF(FileForWrite.at(8), "fonts/arial.ttf", 20);
		lb8->setTextColor(Color4B::BLACK);
		label[8] = MenuItemLabel::create(lb8, [this](Ref *ref) { Click_lbl8(); });

		auto lb9 = Label::createWithTTF(FileForWrite.at(9), "fonts/arial.ttf", 20);
		lb9->setTextColor(Color4B::BLACK);
		label[9] = MenuItemLabel::create(lb9, [this](Ref *ref) { Click_lbl9(); });
	}
	
	if (Count == 12)
	{
		m = Menu::create(label[0], label[1], label[2], label[3], label[4], label[5], label[6], label[7], label[8], label[9], label[10], label[11], nullptr);
	}
	if (Count == 9)
	{
		m = Menu::create(label[0], label[1], label[2], label[3], label[4], label[5], label[6], label[7], label[8], label[9], nullptr);
	}
	
	m->alignItemsVerticallyWithPadding(10);
	//m->setPosition(Vec2( 600 , 300));
	m->setPosition(Jus::getDisplayPoint(0.600, 0.300));
	addChild(m, 4);

}

void Shop::Click_lbl0()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 500; 
			predmet = HelpPredmet.at(0);
		break;
	case 1: BuyWithShop = 500;
		predmet = HelpPredmet.at(12);
		break;
	case 2: BuyWithShop = 100;
		predmet = HelpPredmet.at(24);
		break;
	case 3: BuyWithShop = 30; Tbread += 10; WithIntToString = "10";
		predmet = HelpPredmet.at(48);
		break;
	case 4: BuyWithShop = 100;
		predmet = HelpPredmet.at(36);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl1()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 1500; 
		predmet = HelpPredmet.at(1);
		break;
	case 1: BuyWithShop = 1000;
		predmet = HelpPredmet.at(13);
		break;
	case 2: BuyWithShop = 500;
		predmet = HelpPredmet.at(25);
		break;
	case 3: BuyWithShop = 20; Tworm += 5; WithIntToString = "5";
		predmet = HelpPredmet.at(49);
		break;
	case 4: BuyWithShop = 200;
		predmet = HelpPredmet.at(37);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl2()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 2500;
		predmet = HelpPredmet.at(2);
		break;
	case 1: BuyWithShop = 1500;
		predmet = HelpPredmet.at(14);
		break;
	case 2: BuyWithShop = 700;
		predmet = HelpPredmet.at(26);
		break;
	case 3: BuyWithShop = 40; Tcorn += 10; WithIntToString = "10";
		predmet = HelpPredmet.at(50);
		break;
	case 4: BuyWithShop = 500; 
		predmet = HelpPredmet.at(38);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl3()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 3000;
		predmet = HelpPredmet.at(3);
		break;
	case 1: BuyWithShop = 2000;
		predmet = HelpPredmet.at(15);
		break;
	case 2: BuyWithShop = 800; 
		predmet = HelpPredmet.at(27);
		break;
	case 3: BuyWithShop = 50; Tdough += 10; WithIntToString = "10";
		predmet = HelpPredmet.at(51);
		break;
	case 4: BuyWithShop = 700;
		predmet = HelpPredmet.at(39);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl4()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 4000;
		predmet = HelpPredmet.at(4);
		break;
	case 1: BuyWithShop = 3000;
		predmet = HelpPredmet.at(16);
		break;
	case 2: BuyWithShop = 1000;
		predmet = HelpPredmet.at(28);
		break;
	case 3: BuyWithShop = 70;  Tfish += 5; WithIntToString = "5";
		predmet = HelpPredmet.at(52);
		break;
	case 4: BuyWithShop = 1000;
		predmet = HelpPredmet.at(40);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl5()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 5500;
		predmet = HelpPredmet.at(5);
		break;
	case 1: BuyWithShop = 5000;
		predmet = HelpPredmet.at(17);
		break;
	case 2: BuyWithShop = 1500; 
		predmet = HelpPredmet.at(29);
		break;
	case 3: BuyWithShop = 150; Tmeat += 10; WithIntToString = "10";
		predmet = HelpPredmet.at(53);
		break;
	case 4: BuyWithShop = 1500;
		predmet = HelpPredmet.at(41);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl6()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 6000;
		predmet = HelpPredmet.at(6);
		break;
	case 1: BuyWithShop = 7000;
		predmet = HelpPredmet.at(18);
		break;
	case 2: BuyWithShop = 2500;
		predmet = HelpPredmet.at(30);
		break;
	case 3: BuyWithShop = 60;  Toparish += 20; WithIntToString = "20";
		predmet = HelpPredmet.at(54);
		break;
	case 4: BuyWithShop = 2000;
		predmet = HelpPredmet.at(42);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl7()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 7000;
		predmet = HelpPredmet.at(7);
		break;
	case 1: BuyWithShop = 8000; 
		predmet = HelpPredmet.at(19);
		break;
	case 2: BuyWithShop = 3500; 
		predmet = HelpPredmet.at(31);
		break;
	case 3: BuyWithShop = 50;  Tperlovka += 15; WithIntToString = "15";
		predmet = HelpPredmet.at(55);
		break;
	case 4: BuyWithShop = 3000; 
		predmet = HelpPredmet.at(43);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl8()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 9000;
		predmet = HelpPredmet.at(8);
		break;
	case 1: BuyWithShop = 10000;
		predmet = HelpPredmet.at(20);
		break;
	case 2: BuyWithShop = 5000;
		predmet = HelpPredmet.at(32);
		break;
	case 3: BuyWithShop = 200; Ttvister += 1; WithIntToString = "1";
		predmet = HelpPredmet.at(56);
		break;
	case 4: BuyWithShop = 5000;
		predmet = HelpPredmet.at(44);
		break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl9()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 15000;
		predmet = HelpPredmet.at(9);
		break;
	case 1: BuyWithShop = 15000;
		predmet = HelpPredmet.at(21);
		break;
	case 2: BuyWithShop = 8000;
		predmet = HelpPredmet.at(33);
		break;
	//case 3: BuyWithShop = 30; break;
	case 4: BuyWithShop = 7000; 
		predmet = HelpPredmet.at(45);
		break;
	default: break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl10()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 30000;
		predmet = HelpPredmet.at(10);
		break;
	case 1: BuyWithShop = 20000;
		predmet = HelpPredmet.at(22);
		break;
	case 2: BuyWithShop = 10000;
		predmet = HelpPredmet.at(34);
		break;
	//case 3: BuyWithShop = 30; break;
	case 4: BuyWithShop = 10000;
		predmet = HelpPredmet.at(46);
		break;
	default: break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::Click_lbl11()
{
	switch (typeShop)
	{
	case 0: BuyWithShop = 40000;
		predmet = HelpPredmet.at(11);
		break;
	case 1: BuyWithShop = 30000;
		predmet = HelpPredmet.at(23);
		break;
	case 2: BuyWithShop = 15000;
		predmet = HelpPredmet.at(35);
		break;
	//case 3: BuyWithShop = 30; break;
	case 4: BuyWithShop = 15000;
		predmet = HelpPredmet.at(47);
		break;
	default: break;
	}
	BuyWithShopToInt = to_string(BuyWithShop);
	string str = HelpWord.at(3) + "\n   " + HelpWord.at(4) + "\n\n\n    " + HelpWord.at(5) + BuyWithShopToInt;
	exactlyBuy(str);
}

void Shop::exactlyBuy(string str)
{
	if(Money < BuyWithShop)
	{
		exectly = Sprite::create("exectlyBuy.png");
		//exectly->setPosition(500, 300);
		exectly->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectly, 5);

		exectlyNo = Button::create("exectlyBuyNo.png");
		//exectlyNo->setPosition(Vec2(650, 215));
		exectlyNo->setPosition(Jus::getDisplayPoint(0.650,0.215));
		addChild(exectlyNo, 5);
		exectlyNo->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickExectlyNo, this));

		string strNo = HelpWord.at(6) + "\n\n" + HelpWord.at(7) + BuyWithShopToInt + "\n" + HelpWord.at(8) + mon ;
		exectlylabel = Label::createWithTTF(strNo, "fonts/arial.ttf", 24);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectlylabel, 6);
		helpExectly = true;
	}
	else {
		exectly = Sprite::create("exectlyBuy.png");
		//exectly->setPosition(500,300);
		exectly->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectly, 5);

		exectlyNo = Button::create("exectlyBuyNo.png");
		//exectlyNo->setPosition(Vec2(350, 215));
		exectlyNo->setPosition(Jus::getDisplayPoint(0.350,0.215));
		addChild(exectlyNo, 5);
		exectlyNo->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickExectlyNo, this));
	
		exectlyYes = Button::create("exectlyBuyYes.png");
		//exectlyYes->setPosition(Vec2(650, 215));
		exectlyYes->setPosition(Jus::getDisplayPoint(0.650,0.215));
		addChild(exectlyYes, 5);
		exectlyYes->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickExectlyYes, this));

	
		exectlylabel = Label::createWithTTF(str, "fonts/arial.ttf", 24);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectlylabel, 6);
		helpExectly = false;
	}
	
}

void Shop::buttonClickExectlyNo(Ref *ref)
{
	exectly->setVisible(false);
	exectly = nullptr;
	exectlyNo->setVisible(false);
	exectlyNo = nullptr;
	if (helpExectly == false)
	{
		exectlyYes->setVisible(false);
		exectlyYes = nullptr;
	}
	exectlylabel->setVisible(false);
	exectlylabel = nullptr;

	if (typeShop == typeMLure)
	{
		if (Tbread > Ibread) { Tbread -= 10; }
		if (Tworm > Iworm) { Tworm -= 5; }
		if (Tcorn > Icorn) { Tcorn -= 10; }
		if (Tdough > Idough) { Tdough -= 10; }
		if (Tfish > Ifish) { Tfish -= 5; }
		if (Tmeat > Imeat) { Tmeat -= 10; }
		if (Toparish > Ioparish) { Toparish -= 20; }
		if (Tperlovka > Iperlovka) { Tperlovka -= 15; }
		if (Ttvister > Itvister) { Ttvister -= 1; }
	}
}

void Shop::buttonClickExectlyYes(Ref *ref)
{
	exectly->setVisible(false);
	exectly = nullptr;
	exectlyNo->setVisible(false);
	exectlyNo = nullptr;
	exectlyYes->setVisible(false);
	exectlyYes = nullptr;
	exectlylabel->setVisible(false);
	exectlylabel = nullptr;

	bool s = true;
	switch (typeShop)
	{
	case 0:
		if (itIsInFile("luggageForShopRood.txt") == true)
		{
			writePredmet("luggageForShopRood.txt");
		}
		else s = false;
		break;
	case 1:
		if (itIsInFile("luggageForShopCoil.txt") == true)
		{
			writePredmet("luggageForShopCoil.txt");
		}
		else s = false;
		break;
	case 2:
		if (itIsInFile("luggageForShopLine.txt") == true)
		{
			writePredmet("luggageForShopLine.txt");
		}
		else s = false;
		break;
	case 3:
		if (itIsInFile("luggageForShopLure.txt") == true)
		{
			writePredmet("luggageForShopLure.txt");
		}
		else s = false;
		break;
	case 4:
		if (itIsInFile("luggageForShopHook.txt") == true)
		{
			writePredmet("luggageForShopHook.txt");
		}
		else s = false;
		break;
	}

	if (s == true)
	{
		Money = Money - BuyWithShop;

		labelouttext->setVisible(false);
		labelouttext = nullptr;
		outTextMoney();

		writeInFile();

		WriteIntLure("intBread.txt", Tbread);
		WriteIntLure("intCorn.txt",Tcorn);
		WriteIntLure("intDough.txt",Tdough);
		WriteIntLure("intFish.txt",Tfish);
		WriteIntLure("intMeat.txt",Tmeat);
		WriteIntLure("intOparish.txt",Toparish);
		WriteIntLure("intPerlovka.txt",Tperlovka);
		WriteIntLure("intTvister.txt",Ttvister);
		WriteIntLure("intWorm.txt",Tworm);
	}
	else youHaveItPredmet();
	

}

void Shop::writeInFile()
{
	pathMoney += "MONEY.txt";
	ofstream file(pathMoney, ios_base::trunc);
	file << Money;
	file.close();
	pathMoney = FileUtils::getInstance()->getWritablePath();
}

void Shop::writePredmet(string str)
{
	string qq = FileUtils::getInstance()->getWritablePath();
	qq += str;
	ofstream file(qq, ios_base::app);
	file << predmet << "\n";
	file.close();
}

bool Shop::itIsInFile(string str)
{
	string pp = FileUtils::getInstance()->getWritablePath();
	pp += str;

	vector<string> vv;

	ifstream fileFishingEat(pp);
	fileFishingEat.seekg(0, ios::end);
	size_t filesize = fileFishingEat.tellg();
	fileFishingEat.seekg(0);

	char* buffer = new char[filesize + 1];
	fileFishingEat.read(buffer, filesize);
	buffer[filesize] = '\0';

	vv = ReturnVectorWriteTheLine(buffer);
	delete[]buffer;

	// crok 2
	bool answer;
	int c = vv.size();
	for (int i = 0; i < c; i++)
	{
		if (vv.at(i) == predmet)
		{
			answer = false;
			break;
		}
		else answer = true;
	}
	vv.clear();
	pp.clear();

	return answer;
}

void Shop::youHaveItPredmet()
{
	exectly = Sprite::create("exectlyBuy.png");
	//exectly->setPosition(500, 300);
	exectly->setPosition(Jus::getDisplayPoint(0.500,0.300));
	addChild(exectly, 5);

	exectlyYes = Button::create("exectlyBuyYes.png");
	//exectlyYes->setPosition(Vec2(650, 215));
	exectlyYes->setPosition(Jus::getDisplayPoint(0.610,0.215));
	addChild(exectlyYes, 5);
	exectlyYes->addClickEventListener(CC_CALLBACK_1(Shop::buttonClickyouHaveItPredmet, this));

	if (typeShop == typeMLure)
	{
		string str = "      " + HelpWord.at(11) + "\n\n" + HelpWord.at(12) + predmet + "\n" + HelpWord.at(13) + WithIntToString;
		exectlylabel = Label::createWithTTF(str, "fonts/arial.ttf", 26);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectlylabel, 7);

		Money = Money - BuyWithShop;

		labelouttext->setVisible(false);
		labelouttext = nullptr;
		outTextMoney();

		writeInFile();

		WriteIntLure("intBread.txt", Tbread);
		WriteIntLure("intCorn.txt", Tcorn);
		WriteIntLure("intDough.txt", Tdough);
		WriteIntLure("intFish.txt", Tfish);
		WriteIntLure("intMeat.txt", Tmeat);
		WriteIntLure("intOparish.txt", Toparish);
		WriteIntLure("intPerlovka.txt", Tperlovka);
		WriteIntLure("intTvister.txt", Ttvister);
		WriteIntLure("intWorm.txt", Tworm);
	}
	else {
		string str = HelpWord.at(9) + "\n" + HelpWord.at(10);
		exectlylabel = Label::createWithTTF(str, "fonts/arial.ttf", 26);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500,0.300));
		addChild(exectlylabel, 7);
	}	
	
}

void Shop::buttonClickyouHaveItPredmet(Ref *ref)
{
	exectly->setVisible(false);
	exectly = nullptr;
	exectlyYes->setVisible(false);
	exectlyYes = nullptr;
	exectlylabel->setVisible(false);
	exectlylabel = nullptr;
}

void Shop::ReadIntLure(string str, int type, int TimeType)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	ifstream file(s);
	file >> type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
	TimeType = type;
}

void Shop::WriteIntLure(string str, int type)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	ofstream file(s, ios_base::trunc);
	file << type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
}