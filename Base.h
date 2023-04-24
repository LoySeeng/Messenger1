#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

int flag;
map<string, string> user;

struct chat {
    int message_id;
    string sender;
    string receiver;
    char mess[20][100];
    int num_of_message = 0;
};

class Base {
public:
    map<string, chat> SMS;
    void mailbox(string);
    void chat_on(string, string, char*);
private:
    struct chat;
};


