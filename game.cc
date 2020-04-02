#include <iostream>
#include "game.h"

using namespace std;

enum GameFlags {InitiateGame, KeepPlaying};

Game::Game() {
    Game::startGame();
}

unsigned int Game::retrieveBet() {
    system("clear");
    unsigned int retval;
    while (true) {
        retval = 0;
        cout << "How much money do you want to wager? \n\t> "; //TODO: impliment the actual gambling
        cin >> retval; if (!cin or retval < 1) {cout << "Invalid input! Try again.\n"; cin.clear();}
        break;
    }
    return retval;
}

void Game::printScoreboard(vector<Player> players) {
    scoreboard.print(players);
}
int Game::prompt(const int flag) {
    if (flag == InitiateGame) {
        system("clear");
	    srand(time(0));

        cout << "================================" << endl
             << "=            FARKLE            =" << endl
             << "================================" << endl << endl;

        int playerNum = 0;
        while (players.size() != 2) {
            string name;
            unsigned int money;
            cout << "Please enter a name for player " << playerNum + 1 << ": (q to quit)" << endl << "\t> ";
            cin >> name; if (name == "q" or name == "quit") break;
            if (!isalpha(name[0])) {cout << "Invalid name!\n"; continue;}
            while (1) {
                money = 0; 
                cout << "Please enter an amount of money you want to start out with (must be between 5 and 5000)" << endl << "\t> ";
                cin >> money; if (!cin or money < 5 or money > 5000) {cout << "Invalid input! Try again.\n"; cin.clear(); continue;}
                break;
            }

            vector<Die> selected_dice;
            cout << "Choose 6 Dice\n\t";
            cout << "1.Normal Die\n\t";
            cout << "2.Biased die\n\t";
            cout << "3.Ci Die\n\t";
            cout << "4.Die of Misfortune\n\t";
            cout << "5.Even Number Die\n\t";
            cout << "6.Fer Die\n\t";
            cout << "7.Heavenly Kingdom Die\n\t";
            cout << "8.Holy Trinity Die\n\t";
            cout << "9.Lu Die\n\t";
            cout << "10.Lucky Die\n\t";
            cout << "11.Lucky playing Die\n\t";
            cout << "12.Odd die\n\t";
            cout << "13.Shrinking Playing Die\n\t";
            cout << "14.Strip Die\n\t";
            cout << "15.Unpopular Die" << endl;
            int dice =0;
            while (selected_dice.size() != 6){
                cin.clear();
                cin >> dice;
                if (!cin or dice < 1 or dice >15) {
                    cout << "Invalid choice\n";
                    continue;
                }
                cout << "You chose: " << table.getDie()
                selected_dice.push_back(table.getDie(dice));
            }
                /*
                if (dice == 1){ //normal die
                    //Die temp;
                    //selected_dice.push_back(temp);
                    selected_dice.push_back(table.getDie(dice));
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
                */
             
            
            unsigned int wager = 0;
            unsigned int score = 0;
            players.push_back(Player{name,score,money,wager,selected_dice});
            playerNum++;
            system("clear");
        }
    }

    if (flag == KeepPlaying) {
        cout << "Would you like to play again? (Y) or (N) \n\t> ";
        string s;
        cin >> s;
        if (s.size() && toupper(s.at(0)) == 'Y') return 1;
        else
            return 0;
    }
    return 1;
}

void Game::takeBets(int bet) {
    for (auto p : players) {
        table.setWager(bet); //update wager on table 
        p.setMoney(bet*-1); // take money from them and place on table.
        //cout << p.getBet() << endl;
    }
}

void Game::startGame() {
    // Get players name, desired starting money, initial bet, and desired dice
    prompt(InitiateGame);
    while (1){
        // Start repetitive flow 
        unsigned int wager = Game::retrieveBet();
        Game::takeBets(wager);


        //Game::startRolling() //TODO
        for (Player p : players) {
            if (p.getMoney() <= 0) {
                cout << "Player " << p.getName() << " ran out of money! GAME OVER!\n";
                Game::gameOver();
            }
        }
        if (prompt(KeepPlaying)) continue;
        else
            Game::gameOver();
    }
    

}

void Game::gameOver() {
    cout << "Thanks for playing!\n";
    exit(0);
}