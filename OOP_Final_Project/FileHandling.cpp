#include "FileHandling.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

FileHandling::FileHandling()
{
    fileName = "data.txt";
}

FileHandling::FileHandling(string fname)
{
    if (fname.empty())
        throw invalid_argument("File name cannot be empty.");
    fileName = fname;
}

FileHandling::~FileHandling() {}

void FileHandling::saveData(string& data)
{
    try
    {
        ofstream outFile(fileName, ios::out); 
        outFile << data;
        outFile.close();
        cout << "Data saved successfully." << endl;
    }
    catch (exception& e)
    {
        cerr << "Save error: " << e.what() << endl;
    }
}

void FileHandling::readData()
{
    try
    {
        ifstream inFile(fileName);
        string line;
        cout << "---- File Content ----" << endl;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
    }
    catch (exception& e)
    {
        cerr << "Read error: " << e.what() << endl;
    }
}

void FileHandling::appendData(string& data)
{
    try
    {
        ofstream outFile(fileName, ios::app);
        outFile << data;
        outFile.close();
        cout << "Data appended successfully." << endl;
    }
    catch (exception& e)
    {
        cerr << "Append error: " << e.what() << endl;
    }
}

void FileHandling::clearFile()
{
    try
    {
        ofstream outFile(fileName, ios::trunc); 
        outFile.close();
        cout << "File cleared successfully." << endl;
    }
    catch (exception& e)
    {
        cerr << "Clear file error: " << e.what() << endl;
    }
}
