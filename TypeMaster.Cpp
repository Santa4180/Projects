#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand (time(NULL));
    cout<<"Welcome to Type Master"<<endl;
    cout<<"......................"<<endl<<endl;

    cout<<"Enter the given sentence:"<<endl<<endl;
    string sentences[]={
        "Lose??? i dont lose.I win and thats my suckin job!!!","I am the one who knocks.","Oh captain, my captain.","The eyes chico,they never lie."
    };
    
    int total= sizeof(sentences)/sizeof(sentences);
    int random = rand()%total;
string selectedsentence=sentences[random];
    cout<<selectedsentence<<endl;

    time_t start=time(NULL);
    string input;
    getline(cin,input);

    time_t end = time(NULL);
    double timeused = difftime(end,start);

    int words=1;
    for(int i=0;i<input.length();i++){
    words ++;
}
double wpm=(words/timeused)*60;
cout<<"time elapsed"<<timeused<<"seconds"<<endl;
cout<<"your speed:"<<wpm<<"wpm"<<endl;
}