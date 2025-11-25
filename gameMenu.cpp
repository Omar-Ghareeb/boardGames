#include "gameMenu.h"
using namespace std;
int main(){

    vector<string> games={"Infinity_Tic","SUS","Word","Memory_XO" , "Obstacles Tic Tac Toe" };
    cout<<"choose a game"<<'\n';
    for (int i = 0; i < games.size(); i++)
    {
        cout<<i+1<<" "<<games[i]<<'\n';
    }
    cout<<"0 to exit\n";
    int pick;
    cin>>pick;
    switch (pick)
    {
    case 0:
        break;
    case 1:
        runInfinity();
        break;
    case 2:
        runSUS();
        break;
    case 3:
        runInObstacles();
        break;
    case 4:
        runWord();
        break;
    case 5:
        runMemoryXO();
        break;
    default:
        cout<<"try again"<<'\n';
        break;
    }
    return 0;
}