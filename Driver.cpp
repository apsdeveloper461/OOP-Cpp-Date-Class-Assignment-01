#include<iostream>
#include<string>
#include "Date.cpp"
using namespace std;

int main(){
    // Date d;
    Date d1(2024,2,25);
    cout << d1 << endl;
    Date d2(2023,2,25);
    cout << d2;
    cout << "\nDays :: " << d1-d2;



    return 0;
}
