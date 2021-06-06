//#include"interface.h"
#include<iostream>
int a;
int b;
int c;
int userinput;
int youwon=0;


interface display;

int mathgame()
{
    int choose;
    display.showMessage("Enter a first number");
    cin >> a;
    display.showMessage("Enter a second number");
    cin >> b;
    c = a*b;
    display.showMessage("C = first x second. What is C?");
    cin >> userinput;
    if(userinput==c) {
        display.showMessage("Right!");
        youwon = youwon+1;
    }
    else {
        display.showMessage("Wrong.");
    }
    display.showMessage("Wanna play again? 1-Yes 0-No");
    cin >> choose;
    if(choose == 1){
        mathgame();
    }
    else {
        return(youwon);
    }
    return(0);
}