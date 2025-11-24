#include "gameMenu.h"
using namespace std;
int main(){
<<<<<<< HEAD
    vector<string> games={"Infinity_Tic" , "Obstacles Tic Tac Toe"};
=======
    vector<string> games={"Infinity_Tic","SUS"};
>>>>>>> origin/main
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
<<<<<<< HEAD
    case 3:
        runInObstacles();
=======
    case 2:
        runSUS();
>>>>>>> origin/main
        break;
    default:
        cout<<"try again"<<'\n';
        break;
    }
    return 0;
}