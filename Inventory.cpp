#include "Inventory.h"
#include "Main_Menu.h"

Scene* Inventory::createScene()
{
	return Inventory::create();
}

bool Inventory::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto menuImage = Sprite::create("FontShop.jpg");
	menuImage->setPosition(visibleSize / 2);
	addChild(menuImage, 0);

	OutInvName();
	OutInvRood();
	OutInvCoil();
	OutInvLine();
	OutInvHook();
	OutInvLure();
	OutInvComplect();
	pV = &helpWord;
	ReadWithFile("helpWord.txt", pV);
	pV = &luggageForFishing;
	ReadWithFile("luggageForFishing.txt", pV);
	pV = &helpPredmet;
	ReadWithFile("helpPredmet.txt", pV);
	pV = &InvTypeVector;
	ReadWithFile("luggageForShopRood.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
	InitExit();

	return true;
}

void Inventory::InitExit()
{
	Exit = Button::create("exit.png");
	//Exit->setPosition(Vec2(780, 470));
	Exit->setPosition(Jus::getDisplayPoint(0.780,0.470));
	addChild(Exit, 5);
	Exit->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickExit, this));
}

void Inventory::buttonClickExit(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Main_Menu::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}

void Inventory::OutInvName()
{
	InvName = Sprite::create("InvName.png");
	//InvName->setPosition(Vec2(500, 460));
	InvName->setPosition(Jus::getDisplayPoint(0.500,0.460));
	addChild(InvName, 1);
}

void Inventory::OutInvRood()
{
	InvRood = Button::create("InvRood.png");
	//InvRood->setPosition(Vec2(252, 400));
	InvRood->setPosition(Jus::getDisplayPoint(0.252,0.400));
	addChild(InvRood, 1);
	InvRood->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvRood, this));
}

void Inventory::buttonClickInvRood(Ref *ref)
{
	typeInv = typeInvRood;
	m->removeFromParent();
	InvTypeVector.clear();
	pV = &InvTypeVector;	
	ReadWithFile("luggageForShopRood.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

void Inventory::OutInvCoil()
{
	InvCoil = Button::create("InvCoil.png");
	//InvCoil->setPosition(Vec2(252, 300));
	InvCoil->setPosition(Jus::getDisplayPoint(0.252,0.300));
	addChild(InvCoil, 1);
	InvCoil->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvCoil, this));
}

void Inventory::buttonClickInvCoil(Ref *ref)
{
	typeInv = typeInvCoil;
	m->removeFromParent();
	InvTypeVector.clear();
	pV = &InvTypeVector;
	ReadWithFile("luggageForShopCoil.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

void Inventory::OutInvLine()
{
	InvLine = Button::create("InvLine.png");
	//InvLine->setPosition(Vec2(252, 200));
	InvLine->setPosition(Jus::getDisplayPoint(0.252,0.200));
	addChild(InvLine, 1);
	InvLine->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvLine, this));
}

void Inventory::buttonClickInvLine(Ref *ref)
{
	typeInv = typeInvLine;
	m->removeFromParent();
	InvTypeVector.clear();
	pV = &InvTypeVector;
	ReadWithFile("luggageForShopLine.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

void Inventory::OutInvHook()
{
	InvHook = Button::create("InvHook.png");
	//InvHook->setPosition(Vec2(770, 400));
	InvHook->setPosition(Jus::getDisplayPoint(0.770,0.400));
	addChild(InvHook, 1);
	InvHook->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvHook, this));
}

void Inventory::buttonClickInvHook(Ref *ref)
{
	typeInv = typeInvHook;
	m->removeFromParent();
	InvTypeVector.clear();
	pV = &InvTypeVector;
	ReadWithFile("luggageForShopHook.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

void Inventory::OutInvLure()
{
	InvLure = Button::create("InvLure.png");
	//InvLure->setPosition(Vec2(770, 300));
	InvLure->setPosition(Jus::getDisplayPoint(0.770,0.300));
	addChild(InvLure, 1);
	InvLure->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvLure, this));
}

void Inventory::buttonClickInvLure(Ref *ref)
{
	typeInv = typeInvLure;
	m->removeFromParent();
	InvTypeVector.clear();
	ClearLureNull();
	pV = &InvTypeVector;
	ReadWithFile("luggageForShopLure.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

void Inventory::ClearLureNull()
{
	pV = &luggageForShopLure;
	ReadWithFile("luggageForShopLure.txt", pV);
	pV = nullptr;

	string way = "0";
	vector <string> vec;

	int size = luggageForShopLure.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (luggageForShopLure.at(i) == helpPredmet.at(48)) { way = "intBread.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(49)) { way = "intWorm.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(50)) { way = "intCorn.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(51)) { way = "intDough.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(52)) { way = "intFish.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(53)) { way = "intMeat.txt";   }
		if (luggageForShopLure.at(i) == helpPredmet.at(54)) { way = "intOparish.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(55)) { way = "intPerlovka.txt";  }
		if (luggageForShopLure.at(i) == helpPredmet.at(56)) { way = "intTvister.txt"; }
		if (way == "0")
		{
			log("nixera");
		}
		else 
		{
			pV = &vec;
			ReadWithFile(way, pV);
			pV = nullptr;
			if (atoi(vec.at(0).c_str()) <= 0)
			{
				luggageForShopLure.at(i) = "delete";
			}
			vec.clear();
		}
		
	}
	//vector<int> vec2;
	string str;
	for (int i = 0; i < size - 1; i++)
	{
		if (luggageForShopLure.at(i) == "delete")
		{
			log("delete");
		}
		else
		{
			str += luggageForShopLure.at(i) + "\n";
		}
	}
	WriteluggageForFishing("luggageForShopLure.txt", str);

}

void Inventory::OutInvComplect()
{
	InvComplect = Button::create("InvComplect.png");
	//InvComplect->setPosition(Vec2(770, 200));
	InvComplect->setPosition(Jus::getDisplayPoint(0.770,0.200));
	addChild(InvComplect, 1);
	InvComplect->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickInvComplect, this));
}

void Inventory::buttonClickInvComplect(Ref *ref)
{
	typeInv = typeInvComplect;
	m->removeFromParent();
	InvTypeVector.clear();
	pV = &InvTypeVector;
	ReadWithFile("luggageForFishing.txt", pV);
	pV = nullptr;
	exampleLabelMenu();
}

//------------------------------------------FILE-----------------------------------------------------
vector<string> Inventory::ReturnVectorWriteTheLine(const char* text)
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

void Inventory::ReadWithFile(string str, vector<string> *vec)
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


void Inventory::exampleLabelMenu()
{
	int count = InvTypeVector.size();
	vector<MenuItemLabel*> vec;
	vec.resize(count);
	
	for (int i = 1; i < count; i++)
	{
		auto lb0 = Label::createWithTTF(InvTypeVector.at(i), "fonts/arial.ttf", 18);
		lb0->setTextColor(Color4B::BLACK);
		int k = i - 1;
		if (typeInv == typeInvComplect)
		{
			vec.at(k) = MenuItemLabel::create(lb0, [this](Ref *ref) { Click_lblComplect(); });
		}
		else {
			vec.at(k) = MenuItemLabel::create(lb0, [=](Ref *ref) { Click_lbl0(i); });
		}
		
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
	//m->setPosition(Vec2(500, 300));
	m->setPosition(Jus::getDisplayPoint(0.500,0.300));
	addChild(m, 2);

}

void Inventory::Click_lblComplect()
{
	log("No");
}

void Inventory::Click_lbl0(int i)
{
	exectly = Sprite::create("exectlyBuy.png");
	//exectly->setPosition(500, 300);
	exectly->setPosition(Jus::getDisplayPoint(0.500, 0.300));
	addChild(exectly, 5);

	exectlyNo = Button::create("exectlyBuyNo.png");
	//exectlyNo->setPosition(Vec2(350, 215));
	exectlyNo->setPosition(Jus::getDisplayPoint(0.350,0.215));
	addChild(exectlyNo, 5);
	exectlyNo->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickExectlyNo, this));

	exectlyYes = Button::create("exectlyBuyYes.png");
	//exectlyYes->setPosition(Vec2(650, 215));
	exectlyYes->setPosition(Jus::getDisplayPoint(0.650,0.215));
	addChild(exectlyYes, 5);
	exectlyYes->addClickEventListener(CC_CALLBACK_1(Inventory::buttonClickExectlyYes, this));

	stroka = InvTypeVector.at(i);

	if (typeInv == typeInvLure)
	{
		pPredmet = &helpPredmet;
		ReadWithFile("helpPredmet.txt", pPredmet);
		if (stroka == helpPredmet.at(48)) nnn = ReadIntLure("intBread.txt"); 
		if (stroka == helpPredmet.at(49)) nnn = ReadIntLure("intWorm.txt");
		if (stroka == helpPredmet.at(50)) nnn = ReadIntLure("intCorn.txt");
		if (stroka == helpPredmet.at(51)) nnn = ReadIntLure("intDough.txt");
		if (stroka == helpPredmet.at(52)) nnn = ReadIntLure("intFish.txt");
		if (stroka == helpPredmet.at(53)) nnn = ReadIntLure("intMeat.txt");
		if (stroka == helpPredmet.at(54)) nnn = ReadIntLure("intOparish.txt");
		if (stroka == helpPredmet.at(55)) nnn = ReadIntLure("intPerlovka.txt");
		if (stroka == helpPredmet.at(56)) nnn = ReadIntLure("intTvister.txt");

		string str = "     " + helpWord.at(14) + "\n" + helpWord.at(15) + "\n" + "      "+ helpWord.at(12) + stroka + 
			"\n      " + helpWord.at(13) + to_string(nnn) ;
		exectlylabel = Label::createWithTTF(str, "fonts/arial.ttf", 24);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500, 0.300));
		addChild(exectlylabel, 6);
	}
	else {
		string str = "     " + helpWord.at(14) + "\n" + helpWord.at(15);
		exectlylabel = Label::createWithTTF(str, "fonts/arial.ttf", 24);
		exectlylabel->setColor(Color3B::BLACK);
		//exectlylabel->setPosition(500, 300);
		exectlylabel->setPosition(Jus::getDisplayPoint(0.500, 0.300));
		addChild(exectlylabel, 6);
	}
}

int Inventory::ReadIntLure(string str)
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

void Inventory::buttonClickExectlyNo(Ref *ref)
{
	exectly->setVisible(false);
	exectly = nullptr;
	exectlyNo->setVisible(false);
	exectlyNo = nullptr;
	exectlyYes->setVisible(false);
	exectlyYes = nullptr;
	exectlylabel->setVisible(false);
	exectlylabel = nullptr;

}

void Inventory::buttonClickExectlyYes(Ref *ref)
{
	exectly->setVisible(false);
	exectly = nullptr;
	exectlyNo->setVisible(false);
	exectlyNo = nullptr;
	exectlyYes->setVisible(false);
	exectlyYes = nullptr;
	exectlylabel->setVisible(false);
	exectlylabel = nullptr;

	switch (typeInv)
	{
	case 0: {luggageForFishing.at(1) = stroka;
		string str = luggageForFishing.at(0) + "\n" + luggageForFishing.at(1) + "\n" + luggageForFishing.at(2) + "\n" +
			luggageForFishing.at(3) + "\n" + luggageForFishing.at(4) + "\n" + luggageForFishing.at(5) + "\n";
		WriteluggageForFishing("luggageForFishing.txt", str);
		break; }
	case 1: {luggageForFishing.at(2) = stroka;
		string str = luggageForFishing.at(0) + "\n" + luggageForFishing.at(1) + "\n" + luggageForFishing.at(2) + "\n" +
			luggageForFishing.at(3) + "\n" + luggageForFishing.at(4) + "\n" + luggageForFishing.at(5) + "\n";
		WriteluggageForFishing("luggageForFishing.txt", str);
		break; }
	case 2: {luggageForFishing.at(3) = stroka;
		string str = luggageForFishing.at(0) + "\n" + luggageForFishing.at(1) + "\n" + luggageForFishing.at(2) + "\n" +
			luggageForFishing.at(3) + "\n" + luggageForFishing.at(4) + "\n" + luggageForFishing.at(5) + "\n";
		WriteluggageForFishing("luggageForFishing.txt", str);
		break; }
	case 3: {luggageForFishing.at(4) = stroka;
		string str = luggageForFishing.at(0) + "\n" + luggageForFishing.at(1) + "\n" + luggageForFishing.at(2) + "\n" +
			luggageForFishing.at(3) + "\n" + luggageForFishing.at(4) + "\n" + luggageForFishing.at(5) + "\n";
		WriteluggageForFishing("luggageForFishing.txt", str);
		break; }
	case 4: {luggageForFishing.at(5) = stroka;
		string str = luggageForFishing.at(0) + "\n" + luggageForFishing.at(1) + "\n" + luggageForFishing.at(2) + "\n" +
			luggageForFishing.at(3) + "\n" + luggageForFishing.at(4) + "\n" + luggageForFishing.at(5) + "\n";
		WriteluggageForFishing("luggageForFishing.txt", str);
		break; }
	default :
		break;
	}

}

void Inventory::WriteluggageForFishing(string str, string type)
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	ofstream file(s, ios_base::trunc);
	file << type;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
}
