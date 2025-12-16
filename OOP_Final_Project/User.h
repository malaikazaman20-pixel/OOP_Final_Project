#pragma once
#include <string>
using namespace std;

class User
{
protected:
    int userID;
    string name;
    string email;

public:
    User();
    virtual ~User();

    virtual void updateProfile();
    virtual int viewProfile() = 0; // Pure virtual function

    string getName();
    void setName(string n);

    int getUserID();
    void setUserID(int id);

    string getEmail();
    void setEmail(string e);
};
