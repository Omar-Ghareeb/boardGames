#include "gameMenu.h"
using namespace std;
int main(){
    vector<string> games={"Infinity_Tic"};
    cout<<"choose a game"<<'\n';
    for (int i = 0; i < games.size(); i++)
    {
        cout<<i+1<<" "<<games[i]<<'\n';
    }
    cout<<"0 to exit";
    int pick;
    cin>>pick;
    switch (pick)
    {
    case 0:
        break;
    case 1:
        runInfinity();
        break;
    default:
        cout<<"try again"<<'\n';
        break;
    }
    return 0;
}