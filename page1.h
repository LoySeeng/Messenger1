#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "page2.h"

void page1() {
    cout << "Welcome to the Messenger!" << endl;
    cout << "What do you want to do:" << endl;
    cout << "1 - Sign Up, 2 - Sign In, 3 - Exet" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        string username;
        string pass;

        cout << "Create your login: ";
        cin >> username;
        cout << "Create your password: ";
        cin >> pass;

        map<string, string>::iterator account;
        if (users.empty()) {
            users[username] = pass;
        }
        else {
            for (account = users.begin(); account != users.end(); account++)
                if (account->first == username) {
                    cout << "Sorry! This login is occupied. Please, try with another one." << endl;
                    break;
                }
                else {
                    users[username] = pass;
                    break;
                }
        }
        break;
    }
    case 2: {
        string log_username;
        string log_pass;

        cout << "Enter your login: ";
        cin >> log_username;
        cout << "Enter your password: ";
        cin >> log_pass;

        map<string, string>::iterator account;
        for (account = users.begin(); account != users.end(); account++) {
            if (account->first == log_username && account->second == log_pass) {
                cout << "Welcome " << log_username << "! You have logged on." << endl;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "Someting has gone wrong. Please try again.";
            break;
        }
        break;
    }
    default: // выставить случай другой цифры + добавить case for 3
        break;
    }
}