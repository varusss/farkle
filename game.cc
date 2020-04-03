#include <iostream>
#include <algorithm>
#include "game.h"

using namespace std;

enum GameFlags {InitiateGame, KeepPlaying};

Game::Game() {
    scoreboard = Scoreboard(2);
    Game::startGame();
}

unsigned int Game::retrieveBet() {
    //system("clear");
    cout << endl;
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
        while (1) {            
            unsigned int temp = 0;
            cout << "Please enter how many points you want to play to (suggested: any number between 1000-5000)\n\t> " << flush;
            cin >> temp; if (!cin or temp < 1000 or temp > 5000) {
                cout << "Invalid input! (Enter a number between 1000-5000\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
                } 
            table.setMaxScore(temp);
            break;
        }

        while (players.size() != 2) {
            string name;
            unsigned int money;
            cout << "Please enter a name for player " << playerNum + 1 << ": (q to quit)" << endl << "\t> ";
            cin >> name; if (name == "q" or name == "quit") break;
            if (!isalpha(name[0])) {cout << "Invalid name!\n"; continue;}
            while (1) {
                money = 0; 
                cout << "Please enter an amount of money you want to start out with (must be between 5 and 5000)" << endl << "\t> ";
                cin >> money; if (!cin or money < 5 or money > 5000) {
                    cout << "Invalid input! Try again.\n"; 
                    cin.clear(); 
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;}
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
                cin >> dice;
                if (!cin or dice < 1 or dice >15) {
                    cout << "Invalid choice\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                cout << "You chose: " << table.getDie(dice).getName() << endl;  
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
            cout << endl;
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
        Game::startRolling();

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

void Game::startRolling() {
    // TODO
    // Need:
    // Roll, scoreboard implementation, score calculation, 

    int turn = 0;
	while (true) {
		system("clear");
        scoreboard.print(players);
		/*cout <<"+++++++++++++++++++++++\n";
		for (Player &p :players) {
			cout << "Player: " << p.getName() << "\tScore: "<< p.getScore() << "\tMoney: " << p.getMoney() <<endl;// TODO: display score from table
		}
		cout <<"+++++++++++++++++++++++\n";
        */
		int index =0;
		for (Player &p :players){
			vector<int> rolls;
			unsigned int score =0;
			cout << "=====================\n";
			cout << p.getName() << "'s turn:" << endl;
			
			for (int i =0; i < 6; i++){
				Die temp = p.getDie(i);
				temp.roll();
				cout << i + 1<< ".Rolled: " << temp.get_roll() << endl;
				rolls.push_back(temp.get_roll());
			}
			score = Game::cal_score(rolls);
			cout << "Score: " << score << endl;
			if (!score and turn > 1) {
				cout << "Farkled!\n";
				cout << "Enter a letter to continue\n";
				string s;
				cin >> s;
				continue;
			}
			while (true) {
				score = 0;
				cout << "Do you want to keep the dice(k) or bank the point(b)? \n";
				cin.clear();
				char c;
				cin >> c;
				if (c == 'k') {
					cout << "Which dice do you want to keep?(1-6, 0 to roll)\n";	
					vector<Die> set = p.getDiceSet();
					vector<int> temp({0,1,2,3,4,5}); 
					while (true){
						int i;
						cin.clear();
						cin >> i;
						if (!cin or i <0 or i >6) {
							cout << "Invalid Choice\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							continue;
						}
						if (i == 0) {
							vector<int> newScore;
							cout << "New Rolls: \n";
							for (size_t i = 0; i < temp.size(); i++){
								set[temp[i]].roll();
								rolls[temp[i]]=set[temp[i]].get_roll();
								newScore.push_back(set[temp[i]].get_roll());
							}
							score = Game::cal_score(newScore);
							if (!score){
								for (int i : newScore) cout << "Rolled: " << i << endl;
								cout << "Farkled!\n";
								cout << "Enter a letter to continue\n";
								string s;
								cin >> s;
								continue;
							}

							for (size_t i =0; i <rolls.size(); i++) cout << i+1 << ".Rolled: " << rolls[i] << endl;
							score = Game::cal_score(rolls);
							cout << "Score: " << score << endl;
							break;
						}
						remove(temp.begin(), temp.end(), i-1);
					}
				}
				else if (c == 'b') {
					p.setScore(score);	
					scoreboard.updateScore(score,index);
					break;
				}
				else {
					cout << "Invalid Choice\n";
					continue;
				}
			}
			if (p.getScore() > table.getMaxScore()) {
				cout << p.getName() <<  " win" << endl; 
				break;
			}
			index++;
		}
		system("clear");
		cout << "---------------------------------\n";
		string name;
		for (Player &p: players) {
			cout << p.getScore() << endl;
			int max = 0;
			if (max < p.getScore()) {
				max = p.getScore();
				name = p.getName();
			}
		}
		cout << "Turn " << turn << " - " << name << " win!\n"; 
		cout << "Enter a letter to continue\n";
		cout << "---------------------------------\n";
		turn++;
		string temp;
		cin >> temp;
	}
}

unsigned int Game::cal_score(vector<int> rolls){
	int score = 0;
	vector<int> count(6);
	for (int i : rolls) {
		if (i == 1) count[0]++;
		if (i == 2) count[1]++;
		if (i == 3) count[2]++;
		if (i == 4) count[3]++;
		if (i == 5) count[4]++;
		if (i == 6) count[5]++;
	}
	bool triple = false;
	if ( rolls.size() == 6) {
		sort(rolls.begin(),rolls.end());
		bool straight= true;
		bool straight5 = true;
		for (size_t i = 0;i < rolls.size(); i++) {
			if (rolls[i] != i+1) {
				straight = false;
				break;
			}
		}
		if (straight) return 1500;
		for (size_t i = 0;i < rolls.size() -1; i++) {
			if (rolls[i] != i+1) {
				straight5 = false;
				break;
			}
		}
		if (straight5) return 1000;
	}
	for (size_t i =0; i<count.size(); i++){
		if (count[i] == 6){ // 6 of a kinds
			if (i==0 )score = 1000 *8;
			else score = (i+1) * 8 * 100;
			return score;
		}
		if (count[i] == 5){ // 5 of a kinds
			if (i==0) {
				score = 1000 *4;
				if (count[4]) score += 50;
			}
			else {
				score = (i+1) * 4 * 100;
				if (count[0]) score += 100;
				if (count[4]) score += 50;
			}
			return score;
		}
		if (count[i] == 4) { // 4 of a kind
			if (i==0) score = 1000 *2;
			else {
				score = (i+1) * 2 * 100;
				if (count[0]) score += 100;
				if (count[4]) score += 50;
			}
			return score;
		}
		if (count[i] == 3) {//3 of a kind
			if (triple == true) {
				score = 1200;
				return score;
			}
			else if (i == 0) score += 1000;
			else {
				score += (i+1) *100;
			}
			triple = true;
		}
	}
	if (count[0] >= 1 and count[0] < 3) score += 100 * count[0];
	if (count[4] >= 1 and count[4] < 3) score += 50 * count[4];
	return score;
}

void Game::gameOver() {
    cout << "Thanks for playing!\n";
    exit(0);
}
