#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <vector>
#include "page1.h"
#include "Base.h"

map<string, Base> list;

void page2(string uname) { // проверить название строки
	cout << "Welcome" << uname << "!" << endl;
	int choice2;
	string recipient;
	map<string, string>::iterator account;
	do {
		cout << "What do you want to do:" << endl;
		cout << "1 - Check mailbox, 2 - Send a message to the person, 3 - Send a message to everyone, 4 - Exet" << endl;
		cin >> choice2;
		switch (choice2) {
		case 1: {
			list[uname].mailbox(uname);
			break;
		}
		case 2: {
			map<string, string>::iterator account;
			int flag = 0;

			cout << "Who do you want to send a message to?" << endl;
			string recipient;
			cin >> recipient;
			for (account = users.begin(); account != users.end(); account++) {
				if (account->first == recipient) {
					flag++;
					cout << "Enter your message:" << endl;
					cout << "\t";
					char message[100];
					cin.ignore();
					cin.getline(message, 100);
					list[recipient].chat_on(uname, recipient, message);
					cout << "Your message has been sent successfully" << endl;
				}
				else { // возможно вынести за for
					cout << "Recipient is not found! Please, try again." << endl;
				}
			}
			break;
		}
		case 3: {
			int flag = 0;

			cout << "Be careful! This message will be send to everyone." << endl;
			cout << "Do you want to continue? \n \t 1 - Yes, 2 - No" << endl;
			int choice3;
			cin >> choice3;
			switch (choice3) {
			case 1: {
				vector<string> reciver;
				map<string, string>::iterator account;
				vector<string>::iterator Irec;

				int flag = 0;
				string recipient;

				cout << "List of Users:" << endl;
				for (auto it = list.begin(); it != list.end(); ++it) {
					cout << "\t" << it->first << endl;
				}

				int choice4;
				do {
					cout << " \n Enter members of your group:";
					cin >> recipient;

					for (account = users.begin(); account != users.end(); account++) {
						if (account->first == recipient) {
							flag++;
						}
					}
					if (!flag) {
						cout << "Recipient is not found! Please, try again." << endl;
					}
					reciver.push_back(recipient);
					cout << "Do you want to add more members? 1 - Yes, 2 - No" << endl;
					cin >> choice4;
				} while (choice4 != 2);

				char message[100];
				cout << "Enter your message:" << endl;
				cin.ignore();
				cin.getline(message, 100);
				for (Irec = reciver.begin(); Irec != reciver.end(); Irec++) {
					list[*Irec].chat_on(uname, *Irec, message);
				}
			}
				  cout << "Your message has been sent successfully to everyone" << endl;
				  break;
			case 2:
				break;
			default:
				cout << "Something went wrong! Try again." << endl;
				break;
			}
		}
			  cin >> recipient;
			  for (account = users.begin(); account != users.end(); account++) {
				  if (account->first == recipient) {
					  flag++;
					  cout << "Enter your message:" << endl;
					  cout << "\t";
					  char message[100];
					  cin.ignore();
					  cin.getline(message, 100);
					  list[recipient].chat_on(uname, recipient, message);
					  cout << "Your message has been sent successfully" << endl;
				  }
				  else { // возможно вынести за for
					  cout << "Recipient is not found! Please, try again." << endl;
				  }
			  }
			  break;
		case 4: {
			system("cls");
			cout << "You have been logged out";
			page1();
		}
		default: {
			cout << "Something went wrong! Try again." << endl;
			break;
		}
		}
	} while (choice2 != 4);
}