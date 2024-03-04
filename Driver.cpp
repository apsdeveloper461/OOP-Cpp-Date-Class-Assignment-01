#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "Date.cpp"
using namespace std;

int main()
{
    char choice;
    int Break = false;
    Date D;
    do
    {
        /* code */

        cout << "\n\n|                  ---( Date System by Mehboob Alam )---                    |\n"
             << "|                                                                           |\n"
             << "|        (1). Set the Custom Date........                                   |\n"
             << "|        (2). Post Increment the Date.........                              |\n"
             << "|        (3). Pre Increment the Date.........                               |\n"
             << "|        (4). Post Decrement the Date.........                              |\n"
             << "|        (5). Pre Decrement the Date.........                               |\n"
             << "|        (6). Difference the Date B/w enter Date.......                     |\n"
             << "|        (7). Show the Date in All format......                             |\n"
             << "|        (8). Show the Date in format(April 18, 2010).....                  |\n"
             << "|        (9). Exit the Program..........                                    |\n"
             << "|___________________________________________________________________________|\n";
        do
        {
            cout << "   <===> Enter the Choice :: ( )\b\b";
            choice = getche();
            if (choice < '1' || choice > '9')
                cout << "\n      -- Invalid Choice. Select from 1 to 9\n";
            else
                break;
        } while (true);

        // Run according to choice
        switch (choice)
        {
        case '1':
            cin >> D;
            break;
        case '2':
        {
            cout << "\nBefore Post Increament :: " << D;
            cout << "\nAt the Time of Post Increament :: " << D++;
            cout << "\nAfter Post Increament :: " << D;
        }
        break;
        case '3':
        {
            cout << "\nBefore Post Increament :: " << D;
            cout << "\nAt the Time of Pre Increament :: " << ++D;
            cout << "\nAfter Pre Increament :: " << D;
        }
        break;
        case '4':
        {
            cout << "\nBefore Post Dcreament :: " << D;
            cout << "\nAt the Time of Post Decreament :: " << D--;
            cout << "\nAfter Post Decreament :: " << D;
        }
        break;
        case '5':
        {
            cout << "\nBefore Post Dcreament :: " << D;
            cout << "\nAt the Time of Pre Decreament :: " << --D;
            cout << "\nAfter Pre Decreament :: " << D;
        }
        break;
        case '6':
        {
            Date t;
            cin >> t;
            cout << "\nDays B/w ::" << D - t;
        }
        break;
        case '7':
            cout << endl << D.printDate();
            break;
        case '8':
            cout << endl
                 << D;
            break;
        default:
              Break=true;
            break;
        }
        cout <<"\n-->Enter any key to continue >>";
        getch();
    } while (!Break);

    return 0;
}
