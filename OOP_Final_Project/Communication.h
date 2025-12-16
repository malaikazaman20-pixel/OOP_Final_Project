#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>
#include "Date.h"
using namespace std;

class Communication
{
protected:
    int messageID;
    string sender, receiver, messageContent;
    Date timestamp;

public:
    Communication();
    ~Communication();

    void sendMessage(const string& from, const string& to, const string& message);
    void receiveMessage();
    void viewConversation();

    void setMessageID(int id);
    int getMessageID();
};

#endif
