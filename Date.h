#pragma once
// Blue print of Class Date
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
    void manipulate(bool); // for increament or decrement (zero for decrement and One for increment)
    static int DayOfMonth[12];
    static string NameOfMonth[12];

public:
    Date();
    Date(int y, int m, int d);
    void setDate(int y, int m, int d);
    string printDate() const;
    // Operator Overload
    Date operator++(int);
    Date &operator++();
    Date operator--(int);
    Date &operator--();
    int operator-(Date&);
    // freind function for cout and cin
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
};

    // Static Array to stored the information about name and Days in a month.
    int Date::DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string Date::NameOfMonth[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "Novmeber", "December"};

