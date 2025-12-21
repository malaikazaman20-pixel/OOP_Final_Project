#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    ~Date();

    void setDate(int d, int m, int y);
    void show();

    int getDay();
    int getMonth();
    int getYear();
};

#endif
