#include<iostream>
using namespace std;

int users[100];
int usrdata[100];
int nxtusr = 0;
int session;

void login()
{
    int reglog;
    int pass = 0;
    int idishnik;
    cout << "Login or Register?" << endl;
    cout << "1: Login 2:Register" << endl;
    cin >> reglog;
    if(reglog == 1)
    {
       cout << "Enter your password (only numbers plz): ";
       cin >> pass;
       cout << "\nEnter your ID: ";
       cin >> idishnik;
       if(pass == users[idishnik])
       {
          cout << "You logined";
          session = idishnik;
       }
       else {
          cout << "Wrong password or ID." << endl;
          login();
       }
    } 
    else {
       cout << "Enter your new password: ";
       cin >> pass;
       users[nxtusr] = pass;
       cout << "You registered, please login" << endl;
       cout << "Your id is " << nxtusr << endl;
       nxtusr++;
       login();
    }
}

int main()
{
    int chosik;
    login();
    while(true)
    {
       cout << "\nWelcome, " << session << endl;
       cout << "Money is " << usrdata[session] << endl;
       cout << "1: Write manes" << endl;
       cout << "2: Exit" << endl;
       cin >> chosik;
       switch (chosik)
       {   
          case 1:
              cout << "Enter a number ";
              cin >> usrdata[session];
          break;
          case 2:
              login();
       }
    }
    return 0;
}
