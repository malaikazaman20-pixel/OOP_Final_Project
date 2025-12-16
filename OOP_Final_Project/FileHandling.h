#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <string>
using namespace std;

class FileHandling
{
protected:
    string fileName;

public:
    FileHandling();
    FileHandling(string fname);
    ~FileHandling();

    void saveData(string& data);
    void readData();
    void appendData(string& data);
    void clearFile();
};

#endif