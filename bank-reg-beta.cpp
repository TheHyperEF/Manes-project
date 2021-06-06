#include<iostream>
#include<string.h>
#include"interface.h"
#include"menus.h"
#include"mathgame.h"
using namespace std;

int users[100];
string usernames[100];
int usrdata[100];
int nxtusr = 2;
int session; 
int wonmoney=0;

void devtools();

void setup();

int tranzactions();

//interface display;


int login(int user)
{
    int reglog;
    int pass;
    int idishnik;
    if(user == 0)
    {
    	session = user;
    }
    else {
    	display.showMenu(Login, 2, "Login menu");
    	cin >> reglog;
    	if(reglog == 0)
    	{	
       		display.showMessage("Enter your ID");
		cin >> idishnik;
		display.showMessage("Enter your password: ");
       		cin >> pass;
       		if(pass == users[idishnik])
       		{	
          		display.showMessage("You logined");
          		session = idishnik;
			return 0;
		}
       		else {
         	display.showMessage("Wrong password or ID.");
          	login(1);
       		}
	}
    	else 
    	{
       		display.showMessage("What's your name? ");
			cin >> usernames[nxtusr];
		    display.showMessage("Type your new password");
       		cin >> pass;
       		users[nxtusr] = pass;
       		display.showMessage("You are registered. ID:", nxtusr);
       		nxtusr++;
       		login(1);
    	}
    }
    return 0;
}

int main()
{
    int chosik;
    setup();
    login(1);
    while(true)
    {
       /*cout << "\nWelcome, " << session << endl;
       cout << "Money is " << usrdata[session] << endl;
       cout << "1: Tranzactions" << endl;
       cout << "2: Games (coming soon)" << endl;
       cout << "5: Exit" << endl;
       cout << "7: Dev-tools" << endl;
	   */
	   display.showMenu(MainMenu, 4, "Main menu of Manes 1.8 E:", usrdata[session], usernames[session]);
       cin >> chosik;
       switch (chosik)
       {   
          case 0:
              tranzactions();
          break;
		  case 1:
		 	  wonmoney = mathgame();
			  usrdata[session]=usrdata[session]+wonmoney;
		  	  break;
          case 2:
              login(1);
	  break;
	  case 3:
	      devtools();
       }
    }
    return 0;
}

void devtools()
{
	int choose;
	if(session == 1)
	{
		display.showMenu(DevMenu, 2, "Development menu");
		cin >> choose;
		switch (choose) 
		{
			case 0:
				int chid;
				display.showMessage("User ID");
				cin >> chid;
				if(users[chid] == 0)
				{
					display.showMessage("That user is doesn't exist");
				}
				else {
					int amountmanes;
					display.showMessage("How much?");
					cin >> amountmanes;
					usrdata[chid] = amountmanes;
					display.showMessage("Success!");
				}
			break;
			case 1:
			//display.showMessage("Current version do not support this");
			cout << "Number    Name     Money     Password" << endl;
			for(int i=0; i<100; i++){
				cout << i << ": " << usernames[i] << "      " << usrdata[i] << "      " << users[i] << endl;
			}
			break;	
		}
	}
}

int tranzactions()
{
	int choose;
	int chuser;
	int amount;
	display.showMenu(actionMenu, 2, "Actions");
	cin >> choose;
	switch (choose)
	{
		case 0:
			display.showMessage("Type a user ID");
			cin >> chuser;
			if(users[chuser] == 0)
			{
				display.showMessage("Couldn't find this user!");
				return 1;
			}
			else {
				display.showMessage("How much you want to transfer?");
				cin >> amount;
				if(amount >= usrdata[session])
				{
					display.showMessage("Not enough money");
				}
				else {
					usrdata[chuser] = usrdata[chuser] + amount;
					usrdata[session] = usrdata[session] - amount;
					return 0;
				}
			}
		break;
		case 1:
			display.showMessage("Current version doesn't support this");
		break;
	}
	return 0;
}

void setup()
{
	usernames[1] = "Developer";
	users[1] = 5724;
}

