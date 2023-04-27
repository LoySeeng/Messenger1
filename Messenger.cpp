#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

void page1();
void page2(string);

map<string, string> users;

struct chat {
    string sender;
    string receiver;
    char mess[50][100];
    int num_of_message = 0;
};

class Base {
public:
    map<string, chat> SMS;
    void chat_on(string, string, char*);
    void mailbox(string);
};

void Base::chat_on(string uname, string recipient, char* message) {
    int flag = 0;
    SMS[recipient].sender = uname;
    SMS[recipient].receiver = recipient;
    map<string, string>::iterator account;
    for (account = users.begin(); account != users.end(); account++) {
        if (account->first == recipient) {
            flag++;
        }
    }
    if (flag == 0) {
        cout << "Sorry! User is not found. Try one more time." << endl;
        page2(uname);
    }
    char cuname[20];
    for (int i = 0; i < (uname.length() + 1); i++) {

        cuname[i] = uname[i];
    }
    // ↓ functions for copying a block of information about a message from sender to recipient's mailbox 
    strcpy_s(SMS[recipient].mess[SMS[recipient].num_of_message], cuname);
    strcat_s(SMS[recipient].mess[SMS[recipient].num_of_message], ":  ");
    strcat_s(SMS[recipient].mess[SMS[recipient].num_of_message], message);
    SMS[recipient].num_of_message++;
}

void Base::mailbox(string uname) {
    cout << "\n \t Welcome to your mailbox, " << uname << "\n" << endl;
    cout << "Here is all received messages:" << endl;
    for (int i = 0; i <= SMS[uname].num_of_message; i++) {
        puts(SMS[uname].mess[i]);
        cout << "\a \n" << endl;
    }
}


void page1() {
    int flag = 0;
    int choice;

    cout << "\t \n \n Welcome to the Messenger '666'! \n" << endl;

    while (1) {
        cout << "\nWhat do you want to do:" << endl;
        cout << "1 - Sign Up, 2 - Sign In, 3 - Run away \n" << endl;
        cin >> choice;
        cout << "\n";
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
                for (account = users.begin(); account != users.end(); account++) {
                    if (account->first == username) {
                        cout << "Sorry! This login is occupied. Please, try another one." << endl;                        
                        break;
                    }
                    else {
                        users[username] = pass;
                        break;
                    }
                }
            }
            break;
        }
        case 2: {
            string log_username;
            string log_pass;
            cout << "Enter your login: ";
            cin >> log_username;
            cout << "Enter your password: ";;
            cin >> log_pass;
           
            map<string, string>::iterator account;
            for (account = users.begin(); account != users.end(); account++) {
                if (account->first == log_username && account->second == log_pass) {
                    cout << "\n WELCOME, " << log_username << "!! You have logged in successfully. \n";

                    flag = 1;
                    page2(log_username);
                    break;
                }
            }
            if (flag == 0) {
                cout << "Someting has gone wrong. Probably login or password is incorrect. Please, try again." << endl;                
                break;
            }
            break;
        }
        case 3: {
            system("cls");
            cout << "\nYou could never run away... Just kidding. Goodbye, User!" << endl;
            exit(666);
            break;
        }
        default: {
            cout << "Please, choose a number between 1 - 3" << endl;
            break;
        }
        }
        if (flag == 1) {
            break;
        }
    }
}

map<string, Base> list;

void page2(string uname) {
    system("cls");

    int choice2;
    int choice4;

    do {
        cout << "\n \n \n \n \t \t \t Welcome, " << uname << "! \n" << endl;
        cout << "What do you want to do:\n" << endl;
        cout << "1 - Check mailbox \n2 - Send a message to the person \n3 - Send a message to everyone \n4 - Log Out \n" << endl;

        cin >> choice2;
        switch (choice2) {
        case 1: {
            list[uname].mailbox(uname);
            break;
        }
        case 2: {
            cout << "\nWho do you want to send a message to? To ";
            string reciepient;
            cin >> reciepient;
            char message[100];
            cout << "\nEnter your message: \n" << endl;
            cout << "\t";
            cin.ignore();
            cin.getline(message, 100);
            list[reciepient].chat_on(uname, reciepient, message);
            cout << "\nYour message has been sent successfully" << endl;
            break;
        }
        case 3: {
            vector<string> recivers;
            map<string, string>::iterator account;
            vector<string>::iterator Irec;

            cout << "\nBe careful! This message will be sent to everyone. \n" << endl;
            do {
                int flag = 0;
                string reciepient;
                cout << "\nEnter reciepient: ";
                cin >> reciepient;

                for (account = users.begin(); account != users.end(); account++) {
                    if (account->first == reciepient) {
                        flag++;
                    }
                }
                if (flag == 0) {
                    cout << "\nRecipient is not found! Please, try again." << endl;
                }
                recivers.push_back(reciepient);
                cout << "\nDo you want to add more recipients? 1 - Yes, 2 - No\n";
                cin >> choice4;
                if (choice4 != 1 && choice4 != 2) {
                    cout << "There were just to options: 1 and 2. Let's start over." << endl;
                }
            } while (choice4 != 2);
            char message[100];
            cout << "\nEnter your message:" << endl;
            cout << "\t";
            cin.ignore();
            cin.getline(message, 100);
            for (Irec = recivers.begin(); Irec != recivers.end(); Irec++) {
                 list[*Irec].chat_on(uname, *Irec, message);
            }
            cout << "\nYour message has been sent successfully to everyone, which you have choosen" << endl;
            break;
        }
        case 4: {
            system("cls");
            cout << "You have been logged out" << endl;
            page1();
            break;
        }
        default: {
            cout << "Please, choose a number between 1 - 4" << endl;
            break;
        }
        }
    } while (choice2 != 4);
}


int main()
{
    page1();
    return 0;
}