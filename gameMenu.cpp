#include "gameMenu.h"
using namespace std;

/**
 * @brief Main entry point for the Board Game Collection.
 * @details Displays a menu of available games and allows the user to select one to play.
 * Loops until the user chooses to exit.
 * @return 0 on successful execution.
 */
int main()
{
    bool flag = true;

    while (flag)
    {
        // List of available game titles
        vector<string> games = {"Infinity_Tic", "SUS", "Word", "Memory_XO", "Numerical_XO", "4x4_XO", "Pyramid_XO",
                                "Obstacles_XO", "Four in a row", "Five X Five tic tac toe", "Misere Tic Tac Toe", "Diamond Tic Tac Toe", "Ultimate tic tac toe"};

        cout << "choose a game" << '\n';

        // Display menu options
        for (int i = 0; i < games.size(); i++)
        {
            cout << i + 1 << " " << games[i] << '\n';
        }
        cout << "0 to exit\n";

        int pick;
        cin >> pick;

        // Handle user selection
        switch (pick)
        {
        case 0:
            flag = false; // Exit the loop
            break;
        case 1:
            runInfinity();
            break;
        case 2:
            runSUS();
            break;
        case 3:
            runWord();
            break;
        case 4:
            runMemoryXO();
            break;
        case 5:
            runNumerical();
            break;
        case 6:
            run4x4XO();
            break;
        case 7:
            runPyramidXO();
            break;
        case 8:
            runInObstacles();
            break;
        case 9:
            runFouInARow();
            break;
        case 10:
            run5X5();
            break;
        case 11:
            runMisere();
            break;
        case 12:
            runDiamond();
            break;
        case 13:
            runUltimate();
            break;
        default:
            cout << "try again" << '\n';
            break;
        }
    }
    return 0;
}