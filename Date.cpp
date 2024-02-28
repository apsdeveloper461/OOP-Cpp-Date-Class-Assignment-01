#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
/////////////////////////////////////////// Private Function ////////////////////////////////// 
// used in Increemnet or decrement operator over loading argument pass is the slection of (incr/decr) as(1/0)
void Date::manipulate(bool selection)
{
    if (selection) //check increment / decrement (1 for increment so run this condition)
    {
        if (day == DayOfMonth[month - 1]) //check the day is last day of month or not 
        {
            if (month == 12) //if last month and last day then move to next year
            {
                year++;
                month = 1;
                day = 1;
            }
            else //else move next month only
            {
                month++;
                day = 1;
            }
        }else  //if not last day of month simply increament in the day
            day++;
    }else{ //execute if selection is 0
        if (day == 1)  //if day is first of the month
        {
            if (month == 1) //and month is also 1 , then go to previous year
            {
                year--;
                month = 12;
                day = DayOfMonth[month-1];
            }
            else //Other wise simply decrease the month
            {
                month--;
                day = DayOfMonth[month-1];
            }
        }else  // else decrease the day
            day--;
    }
}
/////////////////////////////////////////// Constructor's /////////////////////////////////////////////////////
// In this constructor firstly Store the default Date (1/1/2000) and then store the enter argument, If the data in argument is invalid then previous Default date is remain as same
Date::Date(int y, int m, int d)
{
     this->day = 1;
     this->month = 1;
     this->year = 2000;
     // Call for set the value.
     setDate(y, m, d);
}
// Make a Default Constructor
Date::Date()
{
     this->day = 1;
     this->month = 1;
     this->year = 2000;
}
 ////////////////////////////////////////////////// Function setter & Getter /////////////////////////////////////
// Set the Date
void Date::setDate(int y, int m, int d)
{
     if (m > 12 && m < 1)
     { // Here check month is valid or not
          cout << "Invalid Month(Select correct Month)";
     }
     else
     {
          if (m == 2 && y % 4 == 0)
               DayOfMonth[1] = 29; // check leap year and set the second month days according to it
          else
               DayOfMonth[1] = 28;

          // Check enter the number is lie in month
          if (d > DayOfMonth[m - 1] || d < 1)
               cout << "Invalid Month the folowing month has " << DayOfMonth[m - 1];
          else
          { // check al validation and set Data , If the any data is wrong Previous data is maintain
               this->day = d;
               this->month = m;
               this->year = y;
          }
     }
}
// Print Date
string Date::printDate() const
{
     string date = "";
     date += to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);
     date += "\n" + NameOfMonth[this->month - 1] + " " + to_string(this->day) + " , " + to_string(year);
     date += "\n" + to_string(this->day) + " " + NameOfMonth[this->month - 1] + " " + to_string(this->year);
     return date;
}
/////////////////////////////////////////////// Operator OVerload /////////////////////////////////////////
Date& Date ::operator++()
{
    if(year%4==0) DayOfMonth[1]=29; //Check year is loop
    else DayOfMonth[1]=28;
    manipulate(1);
    return *this;
}
Date Date ::operator++(int)
{
     if(year%4==0) DayOfMonth[1]=29;
    else DayOfMonth[1]=28;
    Date temp(year,month,day);
    manipulate(1);
    return temp;
}
Date& Date ::operator--()
{
     if(year%4==0) DayOfMonth[1]=29;
    else DayOfMonth[1]=28;
    manipulate(0);
    return *this;
}
Date Date ::operator--(int)
{
     if(year%4==0) DayOfMonth[1]=29;
    else DayOfMonth[1]=28;
    Date temp(year,month,day);
    manipulate(0);
    return temp;
}
//Subttraction
int Date:: operator-(Date &date){
    int days=0;
    // We created temp Object Date because we increment the object for checking condition and difference b/w date. and Not change the exact value of date object passing in argument.....   
    Date temp(date.year,date.month,date.day);
    if(temp.year > this->year || temp.month > this->month || temp.day > this->day ){
       
        do{
           temp--;
            days++;
            if(temp.year == this->year && temp.month == this->month && temp.day == this->day ) break;
        }while(true);
        
    }else{
         do{
           temp++;
            days++;
            if(temp.year == this->year && temp.month == this->month && temp.day == this->day ) break;
        }while(true);
    }
    return days;
}
////////////////////////////////////////// Friend FUnction ////////////////////////////////////

ostream &operator<<(ostream &out, const Date &d)
{
     out << d.NameOfMonth[d.month - 1] << " " << (d.day) << " , " << d.year;
}
istream &operator>>(istream &in, Date &date){
     int y, m, d;
     //We use do while loop for validation....
     do //For year...
     {
          cout << "\n --> Enter the Year ::";
          in >> y;
          if (y < 1)
               cout << "\nYear Must be greater then 0";
          else
               break;
     } while (true);
     do
     {
          cout << "--> Enter the month of the (" << y << "):: ";
          in >> m;
          // Validation For month
          if (m > 12 || m < 1)
               cout << "Invalid month !\n";
          else
               break;
     } while (true);
     ////////////////////// For Leap Year //////////////////////
     if (m == 2 && y % 4 == 0)
          date.DayOfMonth[1] = 29; // check leap year and set the second month days according to it
     else
          date.DayOfMonth[1] = 28;
     do
     {
          cout << "-->Enter the day of the (" << date.NameOfMonth[m - 1] << "):: ";
          in >> d;
          // Validation for day of respect month
          if (d > date.DayOfMonth[m - 1] || d < 1)
               cout << "Invalid Day ! slect from (1 to " << date.DayOfMonth[m - 1] << ")\n";
          else{// here all validation is done and store data in date object...
               // set the new Values
               date.day = d;
               date.month = m;
               date.year = y;
               break;
          }
     } while (true);   
}