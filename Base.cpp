#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "Base.h"
#include "page2.h"

using namespace std;

void Base::mailbox(string uname) {
	cout << "Welcome to your mailbox, " << uname << endl;
	cout << "Here is all your received messages:" << endl;
	for (int i = 0; i <= SMS[uname].num_of_message; i++) {
		puts(SMS[uname].mess[i]);
		cout << "/a" << endl;
		cout << "/n" << endl;
	}
}

void Base::chat_on(string uname, string recipient, char* message) {
	int flag = 0;
	SMS[recipient].sender = uname;
	SMS[recipient].receiver = recipient;
	
	map<string, string>::iterator account;
	for (account = users.begin(); account != users.end(); account++) {
		if (account->first == recipient) {
			flag++;
		}
		else { // вoзможно вынести за скобки for
			cout << "Sorry! User is not found. Try one more time" << endl;
			page2(uname);
		}
	}

	char nickname[20];
	for (int n = 0; nickname[n] != '\0'; n++) {
		nickname[n] = uname[n];
	}
	strcpy(SMS[recipient].mess[SMS[recipient].num_of_message], nickname);
	strcat(SMS[recipient].mess[SMS[recipient].num_of_message], ":  ");
	strcat(SMS[recipient].mess[SMS[recipient].num_of_message], message);
	SMS[recipient].num_of_message++;
}