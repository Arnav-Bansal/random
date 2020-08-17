#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <limits>
using namespace std;

int game=1;
int turn=0;
int n=0;
int gb[101]={};

int players[10]={};
//10 + i for players
//2 for surprise

void setob()
{
    gb[12]=2; gb[43]=2; gb[67]=2; gb[81]=2; gb[30]=2; gb[97]=2;
    for(int i=0; i<10; i++)
    {
        gb[players[i]]= 10 + i;
    }
}
void printgb()
{
    system("cls");
    setob();
    for(int i=100; i>0; i--)
    {
        if((i)%10 == 0){cout<<endl;}                  //end of 10
        if(!gb[i]){cout<<"."<<" "; continue;}           //empty cell
        if(gb[i]==2){cout<<"@ "; continue;}             //surprise cell
        cout<<char(gb[i]%10 + 'A')<<" ";                     //player cell
    }
    cout<<"\n";
}

void roll()
{
    int temp;
    cin>>temp;
    srand(time(0));
    temp=rand()%9;
    temp++;
    if(temp>6){temp=6;}

    int a=players[turn];
    gb[players[turn]]=0;                     //setting initial position 0
    players[turn] += temp;                  //updating pos
    cout<<"The dice showed "<<temp<<" ";
    while(temp==6)
    {
        temp=rand()%9; temp++;
        if(temp>6){temp=6;}
        players[turn] += temp;
        cout<<temp<<" ";
    }
    cout<<"\n";
    if(players[turn]>100){players[turn] = a;}
    if(players[turn]==100){cout<<"Player "<< char('A' + turn)<<" wins!\n"; game--;}

    if(players[turn] - a > 17){
        cout<<"Alas! Turn cancelled!\n";
        players[turn] = a;
    }
    if(gb[players[turn]]==2){
        cout<<"You have hit a surprise milestone! Press 0 to generate your new number!\n";
        int h; cin>>h;
        h=rand() % 100;
        players[turn]=h;
        cout<<"Your new number is "<<h<<" ! Good luck\n";
    }
    gb[players[turn]] = 10 + turn;       //setting new pos

}
int main(){
    cout<<"Welcome to  the famous snakes and ladders game with a twist! \n Here there are some suprise cells, denoted by @ \n When you reach them, they will randomly output a number and you'll go there.\n";
    cout<<"Enter the number of player: ";
    cin>>n;     game=n-1;
    if(n<2){cout<<"players very less!"; exit(0);}
    cout<<"Lets begin\n\n";
    while(game){
        if(players[turn] == 100){turn = (turn+1)%n; continue;}
        printgb();
        cout<<"Its the turn of player "<<char(turn + 'A')<<". Press 0 to roll the dice.\n";
        roll();
        turn =(turn+1)%n;
        cout<<"Press 0 for next turn and to update the gameboard\n";
        int j;
        cin>>j;
    }
}
