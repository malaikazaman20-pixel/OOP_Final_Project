#include "Communication.h"
#include <iostream>
using namespace std;

Communication::Communication()
{
    messageID = 0;
    sender = receiver = messageContent = "";
}

Communication::~Communication() {}

void Communication::sendMessage(const string& from, const string& to, const string& message)
{
    sender = from;
    receiver = to;
    messageContent = message;

    cout << "---- Message Sent ----" << endl;
    cout << "From: " << sender << endl;
    cout << "To: " << receiver << endl;
    cout << "Message: " << messageContent << endl;
    cout << "Time: ";
    timestamp.show();
}

void Communication::receiveMessage()
{
    cout << "---- Message Received ----" << endl;
    cout << "From: " << sender << endl;
    cout << "To: " << receiver << endl;
    cout << "Message: " << messageContent << endl;
    cout << "Time: ";
    timestamp.show();
}

void Communication::viewConversation()
{
    cout << "---- Conversation ----" << endl;
    cout << sender << " -> " << receiver << endl;
    cout << messageContent << endl;
    cout << "Time: ";
    timestamp.show();
}

void Communication::setMessageID(int id)
{
    messageID = id;
}

int Communication::getMessageID()
{
    return messageID;
}
