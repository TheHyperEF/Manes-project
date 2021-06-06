#include<string.h>
#include<iostream>
using namespace std;

class interface
{
    private:
    void showLine(char symbol, int num);
    public:
    void showMessage(string info);
    void showMessage(string info, int data);

    void showMessageMultiline(string info[], int numOfElements);

    void showMenu(string info[], int numOfElements, string header);
    void showMenu(string info[], int numOfElements, string header, int data);
    void showMenu(string info[], int numOfElements, string header, int data, string usrname);

    void ErrData(int numOfError);
};

void interface::showLine(char symbol, int num)
{
    for(int i=0; i<num; i++)
    {
        cout << symbol;
    }
    cout << " " << endl;
}

void interface::showMessage(string info)
{
    cout << endl;
    showLine('@', 30);
    cout << info << endl;
    showLine('@', 30);
}

void interface::showMessage(string info, int data)
{
    cout << endl;
    showLine('@', 30);
    cout << info << data << endl;
    showLine('@', 30);
}

void interface::showMenu(string info[], int numOfElements, string header)
{
    cout << endl;
    cout << header << endl;
    interface::showLine('#', 30);
    for(int i=0; i < numOfElements; i++)
    {
        cout << i << ": " << info[i] << endl;
    }    
    interface::showLine('#', 30);
}

void interface::showMessageMultiline(string info[], int numOfElements)
{
    cout << endl;
    interface::showLine('#', 30);
    for(int i=0; i < numOfElements; i++)
    {
        cout << info[i] << endl;
    }    
    interface::showLine('#', 30);
}

void interface::showMenu(string info[], int numOfElements, string header, int data)
{
    cout << endl;
    cout << header << data << endl;
    interface::showLine('#', 30);
    for(int i=0; i < numOfElements; i++)
    {
        cout << i << ": " << info[i] << endl;
    }    
    interface::showLine('#', 30);
}

void interface::showMenu(string info[], int numOfElements, string header, int data, string usrname)
{
    cout << endl;
    cout << header << data << endl;
    cout << usrname << endl;
    interface::showLine('#', 30);
    for(int i=0; i < numOfElements; i++)
    {
        cout << i << ": " << info[i] << endl;
    }    
    interface::showLine('#', 30);
}