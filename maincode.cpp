#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

class Bank
{
    map<string, pair<string, double>> bank;
    string id;
    string password;

public:
    void start()
    {
        cout << "**********Welcome To Indi ATM**********" << endl
             << "***Please select the option from below according to your need***" << endl;
        char option;
        do
        {
            printIntroMenu();
            cin >> option;
            switch (option)
            {
            case 'l':
                login();
                break;
            case 'c':
            {
                create_new_account();
                break;
            }
            case 'q':
            {
                cout << "Thanks using Indi ATM!\n";
                break;
            }
            default:
            {
                cout << "Invalid option. Please select some other valid option.\n";
                break;
            }
            }
        } while (option != 'q');
    }
    void printIntroMenu()
    {
        cout << "Press 'l' for Login" << endl
             << "Press 'c' for Create New Account" << endl
             << "Press 'q' for Quit" << endl;
    }
    void printMainMenu()
    {
        cout << "Press 'd' for Deposit Money" << endl
             << "Press 'w' for Withdraw Money" << endl
             << "Press 'r' for Request Balance" << endl
             << "Press 'q' for quit" << endl;
    }
    void create_new_account()
    {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;
        bank[id] = make_pair(password, 0.0);
        cout << "Thank You! Your account has been created!\n";
    }

    void login()
    {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;
        if (bank.find(id) != bank.end() && bank[id].first == password)
        {
            cout << "Access Granted!\n";
            char option;
            do
            {
                printMainMenu();
                cin >> option;
                switch (option)
                {
                case 'd':
                {
                    double amount;
                    cout << "Amount of deposit: $";
                    cin >> amount;
                    bank[id].second += amount;
                    break;
                }
                case 'w':
                {
                    double amount;
                    cout << "Amount of withdrawal: $";
                    cin >> amount;
                    if (amount <= bank[id].second)
                    {
                        bank[id].second -= amount;
                    }
                    else
                    {
                        cout << "Insufficient balance.\n";
                    }
                    break;
                }
                case 'r':
                {
                    cout << "Your balance is $" << bank[id].second << ".\n";
                    break;
                }
                case 'q':
                {
                    cout << "Thanks for stopping by!\n";
                    break;
                }
                default:
                {
                    cout << "Invalid option. Please try again.\n";
                    break;
                }
                }
            } while (option != 'q');
        }
        else
        {
            cout << "******** LOGIN FAILED! ********\n";
        }
    }
};
int main()
{
    Bank obj;
    obj.start();
    return 0;
}
