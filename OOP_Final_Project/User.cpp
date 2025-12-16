#include "User.h"
#include <iostream>
#include <stdexcept>
using namespace std;

User::User() : userID(0), name(""), email("") {}

User::~User() {}

void User::updateProfile()
{
    try
    {
        string newName, newEmail;

        cout << "Enter Updated Name: ";
        cin.ignore();
        getline(cin, newName);
        if (newName.empty())
            throw invalid_argument("Name cannot be empty.");

        cout << "Enter Updated Email: ";
        getline(cin, newEmail);
        if (newEmail.empty())
            throw invalid_argument("Email cannot be empty.");

        name = newName;
        email = newEmail;

        cout << "Profile updated successfully." << endl;
    }
    catch (exception& e)
    {
        cerr << "Error updating profile: " << e.what() << endl;
    }
}

string User::getName() 
{
    return name;
}

void User::setName(string n)
{
    name = n;
}

int User::getUserID()
{
    return userID;
}

void User::setUserID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("User ID must be positive.");
        userID = id;
    }
    catch (exception& e)
    {
        cerr << "Error setting user ID: " << e.what() << endl;
    }
}

string User::getEmail()
{
    return email;
}

void User::setEmail(string e)
{
    email = e;
}
