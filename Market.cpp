#include "Market.h"
#include "Main_Menu.h"
using namespace std;

Scene* Market::createScene()
{
	return Market::create();
}

bool Market::init()
{ 
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto menuImage = Sprite::create("FontShop.jpg");
	menuImage->setPosition(visibleSize / 2);
	addChild(menuImage, 0);

	InitPriceOfFish();
	InitSellFish();
	OutTextNameMarket();
	pV = &textFish;
	ReadWithFile("FishTrue.txt", pV);
	OutTextFish();
	InitExit();
	
	return true;
}

void Market::InitExit()
{
	Exit = Button::create("exit.png");
	//Exit->setPosition(Vec2(250, 120));
	Exit->setPosition(Jus::getDisplayPoint(0.250,0.120));
	addChild(Exit, 5);
	Exit->addClickEventListener(CC_CALLBACK_1(Market::buttonClickExit, this));
}

void Market::buttonClickExit(Ref *ref)
{
	auto director = Director::getInstance();
	auto scene = Main_Menu::create();
	auto transition = TransitionCrossFade::create(1, scene);
	director->replaceScene(transition);
}

void Market::InitPriceOfFish()
{
	PriceOfFish = Button::create("Component_PriceOfFish.png");
	//PriceOfFish->setPosition(Vec2(252, 380));
	PriceOfFish->setPosition(Jus::getDisplayPoint(0.252,0.380));
	addChild(PriceOfFish, 1);
	PriceOfFish->addClickEventListener(CC_CALLBACK_1(Market::buttonClickPriceOfFish, this));
}

void Market::InitSellFish()
{
	SellFish = Button::create("Component_SellFish.png");
	//SellFish->setPosition(Vec2(252, 280));
	SellFish->setPosition(Jus::getDisplayPoint(0.252,0.280));
	addChild(SellFish, 1);
	SellFish->addClickEventListener(CC_CALLBACK_1(Market::buttonClickSellFish, this));
}

void Market::OutTextNameMarket()
{
	TextNameMarket = Sprite::create("TextNameMarket.png");
	//TextNameMarket->setPosition(Vec2(255,460));
	TextNameMarket->setPosition(Jus::getDisplayPoint(0.255,0.460));
	addChild(TextNameMarket, 1);
}

void Market::buttonClickPriceOfFish(Ref *ref) {
	for (vector<string>::size_type i = 0; i < OutTextLabel.size(); i++)
	{
		OutTextLabel.at(i)->setVisible(true);
	}
	if (B == true)
	{
		L->setVisible(false);
		L = nullptr;
		B = false;
	}
}

void Market::buttonClickSellFish(Ref *ref) {
	if (B == false)
	{
		for (vector<string>::size_type i = 0; i < OutTextLabel.size(); i++)
		{
			OutTextLabel.at(i)->setVisible(false);
		}
		pV = &Fish;
		ReadWithFile("Fish.txt", pV);
		pV = &FishMasa;
		ReadWithFile("fishMasa.txt", pV);
		pV = &HawMachMoney;
		ReadWithFile("HawMachMoney.txt", pV);
		pV = &helpWord;
		ReadWithFile("helpWord.txt", pV);
		pV = nullptr;
		sellFishWithFile();
		OutTextSellFish();
		B = true;
	}
}

void Market::OutTextSellFish()
{
	string str;
	int size = OutVector.size();
	for (int i = 0; i < size; i++)
	{
		str += OutVector.at(i) + "\n";
	}
	L = Label::createWithTTF(str, "fonts/arial.ttf", 18);
	L->setColor(Color3B::BLACK);
	L->setPosition(Jus::getDisplayPoint(0.55, 0.5));
	addChild(L, 4);

	clearFile();
}

void Market::clearFile()
{
	string str;
	for (int i = 0; i < 33; i++)
	{
		str += "0\n";
	}
	
	string s = FileUtils::getInstance()->getWritablePath();
	s += "fishMasa.txt";
	ofstream file(s, ios_base::trunc);
	file << str;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
	Fish.clear();
	FishMasa.clear();
	HawMachMoney.clear();
	OutVector.clear();
	helpWord.clear();
}

void Market::sellFishWithFile()
{
	int FinishPrise = 0;
	for (int i = 0; i < 33; i++)
	{
		string str = FishMasa.at(i);
		int integer = atoi(str.c_str());
		if (integer > 0)
		{
			integer = ((integer * atoi(HawMachMoney.at(i).c_str()))/1000);
			string text = Fish.at(i) + "   " + FishMasa.at(i) + helpWord.at(17) + "  -  " + helpWord.at(23) + "  " + to_string(integer) + helpWord.at(2);
			OutVector.push_back(text);
			FinishPrise += integer;
		}
	}
	string s = helpWord.at(24) + "  " + to_string(FinishPrise) + helpWord.at(2);
	OutVector.push_back(s);
	WriteInMoney("MONEY.txt", FinishPrise);
}

void Market::WriteInMoney(string str , int integer)
{
	string mon = ReadWithMoney();
	string s = FileUtils::getInstance()->getWritablePath();
	s += str;
	integer += atoi(mon.c_str());
	ofstream file(s, ios_base::trunc);
	file << to_string(integer);
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
}

string Market::ReadWithMoney()
{
	string s = FileUtils::getInstance()->getWritablePath();
	s += "MONEY.txt";
	string str;
	ifstream file(s);
	file >> str;
	file.close();
	s = FileUtils::getInstance()->getWritablePath();
	return str;
}



//------------------------------------------FILE-----------------------------------------------------
vector<string> Market::ReturnVectorWriteTheLine(const char* text)
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

void Market::ReadWithFile(string str, vector<string> *vec)
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

void Market::OutTextFish()
{
	int x = 0, j = 0, k = 0;
	for (vector<string>::size_type i = 0; i < textFish.size(); i++)
	{
		helpOut(textFish.at(i), 17, 450+j , 450-x);
		x += 20;
		k++;
		if (k == 16) { j = 250; x = 0; }
	}

}

void Market::helpOut(string str, int size , int n, int y)
{
	auto label = Label::createWithTTF(str, "fonts/arial.ttf", size);
	label->setColor(Color3B::BLACK);
	label->setPosition(n, y);
	OutTextLabel.push_back(label);
	addChild(*OutTextLabel.rbegin(), 4);
}

