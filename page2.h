#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "page1.h"
#include "Base.h"

map<string, Base> list;

void page2(string uname) { // проверить название строки
	cout << "Welcome" << uname << "!" << endl;
	cout << "What do you want to do:" << endl;
	cout << "1 - Check mailbox, 2 - Send a message to a person, 3 - Send a message to everyone" << endl;
	int choice2;
	cin >> choice2;
	switch (choice2) { // заменить на цикл
	case 1: {
		list[uname].mailbox(uname);
		break;
	}
	case 2: {
		string 
	}
	case 3: {

	}
	default:
		break;
	}

}