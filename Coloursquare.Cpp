#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unistd.h>
using namespace std;

enum color{Red,Green,Blue,Yellow,Purple};

color generateRandomColor(){
    int randomNum=rand()%5;
    return static_cast<color>(randomNum);
}
string colorToString(color color){
    switch(color){
        case Red:
        return "Red";
        case Green:
        return "Green";
        case Blue:
        return "Blue";
        case Yellow:
        return "Yellow";
        case Purple:
        return "Purple";
        default:
        return "unknown";
    }
}
int main(){
    srand(time(0));
    color targetcolor=generateRandomColor();
    string guess;
    while(true){
    system("cls");
    cout<<"Welcome to the coloursquare game!"<<endl;
    cout<<"*********************************"<<endl;
    cout<<"Guess the color of square(Red,Green,Blue,Yellow,Purple)"<<endl;
    cout<<"Enter your guess:";
    cin>>guess;

    for (int i=0; i<guess.length(); ++i){
        guess[i]=tolower(guess[i]);
    }
    if (guess=="red" || guess=="green"|| guess=="blue" || guess=="Yellow" || guess=="purple"){
        color usercolor;
        if(guess =="red")
        usercolor=Red;
        else if(guess =="green")
        usercolor=Green;
        else if(guess=="blue")
        usercolor=Blue;
        else if(guess=="yellow")
        usercolor=Yellow;
        else if(guess=="purple")
        usercolor=Purple;  
    
    if (usercolor==targetcolor){
        cout<<endl;
        cout<<"congratulation Maverik got the correct guess.GOOD JOB!!!"<<endl;
        break;
    }
    else{
        cout<<"oops.Try again noob......"<<endl;
    }
    }
    else{
        cout<<"Invalid color you dumb.Please enter a valid color"<<endl;
    }
sleep(1000);
}//while
}//int