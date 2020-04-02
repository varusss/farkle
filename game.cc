#include <iostream>
#include "game.h"

using namespace std;

enum GameFlags {StartOfGame, };

Game::Game() {};
void Game::printScoreboard(const vector<Player> &players) {
    scoreboard.print(players);
}
void Game::prompt(const int flag) {
    if (flag == StartOfGame) {
        system("clear");
	    srand(time(0));

        cout << "===================="
             << "=      FARKLE      ="
             << "====================" << endl << endl;

        int playerNum = 0;
        while (players.size() != 2) {
            string name;
            int money;
            cout << "Please enter a name for player " << playerNum + 1 << ": (q to quit)" << endl << "\t>";
            cin >> name; if (name == "q" or name == "quit") break;
            if (!isalpha(name[0])) {cout << "Invalid name!\n"; continue;}
            while (1) {
                money = 0; 
                cout << "Please enter an amount of money you want to start out with (must be between 5 and 5000)" << endl << "\t>";
                cin >> money; if (!cin or money < 5 or money > 5000) {cout << "Invalid input! Try again.\n"; cin.clear(); continue;}
            }

            vector<Die> selected_dice;
            cout << "Choose 6 Dice\n";
            cout << "1.Normal Die\n";
            cout << "2.Biased die\n";
            cout << "3.Ci Die\n";
            cout << "4.Die of Misfortune\n";
            cout << "5.Even Number Die\n";
            cout << "6.Fer Die\n";
            cout << "7.Heavenly Kingdom Die\n";
            cout << "8.Holy Trinity Die\n";
            cout << "9.Lu Die\n";
            cout << "10.Lucky Die\n";
            cout << "11.Lucky playing Die\n";
            cout << "12.Odd die\n";
            cout << "13.Shrinking Playing Die\n";
            cout << "14.Strip Die\n";
            cout << "15.Unpopular Die\n";
            int dice =0;
            while (true){
                cin.clear();
                cin >> dice;
                if (!cin or dice < 1 or dice >15) {
                    cout << "Invalid choice\n";
                    continue;
                }
                if (dice == 1){ //normal die
                    Die temp;
                    selected_dice.push_back(temp);
                }
                else if (dice == 2) { //biased die
                    Die temp({.20,.30,.10,.10,.10,.20},6, "Biased Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 3 or dice ==6 or dice == 9){ //ci, fer, and lu die
                    string s;
                    if (dice == 3) s = "Ci Die";
                    else if (dice == 6) s = "Fer Die";
                    else s = "Lu Die";
                    Die temp({.1,.1,.1,.1,.1,.5},6, s);
                    selected_dice.push_back(temp);
                }
                else if (dice == 4){ //misfortune
                    Die temp({.05,.19,.19,.19,.19,.19},6, "Die of Misfortune");
                    selected_dice.push_back(temp);
                }
                else if (dice == 5){ //even number
                    Die temp({.10,.233,.10,.233,.10,.233},6, "Even Number Die");
                    selected_dice.push_back(temp);
                }
                else if (dice ==7){ //heavenly kingdom
                    Die temp({.35,.10,.10,.10,.10,.25},6, "Heavenly Kingdom Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 8){ //holy trinity
                    Die temp({.12,.12,.40,.12,.12,.12},6, "Holy Trinity Die");
                    selected_dice.push_back(temp);
                }
                else if (dice ==10) {//lucky die
                    Die temp({.30,.14,.14,.14,.14,.14},6, "Lucky Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 11){ //lucky playing die
                    Die temp({.50,.10,.10,.10,.10,.10},6, "Lucky Playing Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 12){ //odd dice
                    Die temp({.233,.10,.233,.10,.233,.10},6, "Odd Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 13){ //Shrinking playing die
                    Die temp({.20,.15,.15,.15,.15,.20},6, "Shrinking playing Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 14){ //strip die
                    Die temp({.20,.15,.15,.15,.15,.20},6, "Strip Die");
                    selected_dice.push_back(temp);
                }
                else if (dice == 15){ //unpopular die 
                    Die temp({.20,.20,.30,.10,.10,.10},6, "Unpopular Die");
                    selected_dice.push_back(temp);
                }	
                if (selected_dice.size() == 6) {
                    playerTemp.setDice(selected_dice);
                    break;
                }
            }
            
            int wager;
            system("clear");
            while (true) {
                wager = 0;
                cout << "How much money do you want to wager? You have " << money << " dollars to wager.\n"; //TODO: impliment the actual gambling
                cin >> wager; if (!cin or wager > money or wager < 1) {cout << "Invalid input! Try again.\n"; cin.clear();}
                }
            players.push_back(Player{name,0,money,wager});
        }
    }

    /*
    if (flag == ) {

    }
    if (flag == )
    */
}
void Game::startGame() {
    prompt(StartOfGame);


}