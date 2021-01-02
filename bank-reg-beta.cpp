#include<iostream>
using namespace std;

int users[100];
int usrdata[100];
int nxtusr = 2;
int session; 

void devtools();

void setup();

int tranzactions();

int login(int user)
{
    int reglog;
    int pass = 0;
    int idishnik;
    if(user == 0)
    {
    	session = user;
    }
    else {
    	cout << "Login or Register?" << endl;
    	cout << "1: Login 2:Register" << endl;
    	cin >> reglog;
    	if(reglog == 1)
    	{	
       		cout << "\nEnter your ID: ";
		cin >> idishnik;
		cout << "Enter your password (only numbers plz): ";
       		cin >> pass;
       		if(pass == users[idishnik])
       		{	
          		cout << "You logined";
          		session = idishnik;
			return 0;
		}
       		else {
         	cout << "Wrong password or ID." << endl;
          	login(1);
       		}
	}
    	else 
    	{
       		cout << "Enter your new password: ";
       		cin >> pass;
       		users[nxtusr] = pass;
       		cout << "You registered, please login" << endl;
       		cout << "Your id is " << nxtusr << endl;
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
       cout << "\nWelcome, " << session << endl;
       cout << "Money is " << usrdata[session] << endl;
       cout << "1: Tranzactions" << endl;
       cout << "2: Games (coming soon)" << endl;
       cout << "5: Exit" << endl;
       cout << "7: Dev-tools" << endl;
       cin >> chosik;
       switch (chosik)
       {   
          case 1:
              tranzactions();
          break;
          case 5:
              login(1);
	  break;
	  case 7:
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
		cout << "1: Write manes" << endl;
		cout << "2: Usr list" << endl;
		cin >> choose;
		switch (choose) 
		{
			case 1:
				int chid;
				cout << "Enter a usrID" << endl;
				cin >> chid;
				if(users[chid] == 0)
				{
					cout << "User doesn't exist" << endl;	
				}
				else {
					int amountmanes;
					cout << "Enter a nuber" << endl;
					cin >> amountmanes;
					usrdata[chid] = amountmanes;
					cout << "Sucess!" << endl;
				}
			break;
			case 2:
			cout << "This option in development" << endl;
			break;	
		}
	}
}

int tranzactions()
{
	int choose;
	int chuser;
	int amount;
	cout << "1: Send money" << endl;
	cout << "2: Take money" << endl;
	cout << "Enter a number: ";
	cin >> choose;
	switch (choose)
	{
		case 1:
			cout << "Enter a user ID: ";
			cin >> chuser;
			if(users[chuser] == 0)
			{
				cout << "User doesn't exist" << endl;
				return 1;
			}
			else {
				cout << "You want to transfer: ";
				cin >> amount;
				if(amount >= usrdata[session])
				{
					cout << "Not enough money" << endl; 
				}
				else {
					usrdata[chuser] = usrdata[chuser] + amount;
					usrdata[session] = usrdata[session] - amount;
					return 0;
				}
			}
		break;
		case 2:
			cout << "This function in development" << endl;
		break;
	}
	return 0;
}

void setup()
{
	users[1] = 5724;
}

