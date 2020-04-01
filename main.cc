//Write your last name and your partner's name here
#include <iostream>
#include "die.h"
#include "player.h"
using namespace std;

int cal_score(vector<int> rolls);

int main() {
	system("clear");
	srand(time(0));

	cout << "FARKLE" << endl;
	int playerNum = 0;
	vector<Player> playerList;

	while (playerNum < 7) {
		Player playerTemp("",0,0,0,{});
		cout << "====================\n";
		string name;
		cout << "5 people max\n";
		cout << "Please enter a name for player " << playerNum +1<< ": (q to quit)" << endl;
		cin.clear();
		cin >> name;
		if (name == "q" and playerNum > 1) break;
		if (!isalpha(name[0])){
			cout << "Invalid name\n";
			continue;
		}
		playerTemp.setName(name);
		cout << "Please enter an amount of money you want to start out with (must be more than 5)\n";
		while (true) {
			int money;
			cin.clear();
			cin >> money;
			if (money < 5 or money >5000) {
				cout << "Invalid number.\n";
				continue;
			}
			else {
				playerTemp.setPlayerMoney(money);
				break;
			}
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
		playerList.push_back(playerTemp);
		playerNum++;
	}
	
	while (true) {
		system("clear");
		cout <<"+++++++++++++\n";
		for (Player p :playerList) {
			cout << "Player: " << p.getName() << endl;
		}
		cout <<"+++++++++++++\n";
		for (Player p :playerList){
			vector<int> rolls;
			int score =0;
			cout << "=====================\n";
			cout << p.getName() << " turn:" << endl;
			cout << "How much money do you want to wager?\n"; //TODO: impliment the actual gambling
			int wager;
			cin >> wager;
			for (int i =0; i < 6; i++){
				Die temp = p.getDie(i);
				temp.roll();
				cout << i + 1<< ".Rolled: " << temp.get_roll() << endl;
				rolls.push_back(temp.get_roll());
			}
			score = cal_score(rolls);
			cout << "Score: " << score << endl;
			if (!score) {
				cout << "Farkled!\n";
				continue;
			}
			while (true) {
				cout << "Do you want to keep the dice(k) or bank the point(b)? \n";
				cin.clear();
				char c;
				cin >> c;
				if (c == 'k') {
					cout << "Which dice do you want to keep?(1-6, 0 to roll)\n";
					while (true){
						vector<int> choice;
						int i;
						cin.clear();
						cin >> i;
						if (i <0 or i >6) {
							cout << "Invalid Choice\n";
							continue;
						}
						if (i == 0) {
							for (size_t i =0; i < choice.size(); i++){
								Die d = p.getDie(choice[i]);
								d.roll();
								rolls[choice[i]] = d.get_roll();
							}
							cout << "New Rolls: \n";
							for (size_t i = 0; i < rolls.size(); i++)
								cout << i+1 << ".Rolled: " << rolls[i] << endl;
							score = cal_score(rolls);
							cout << "Score: " << score << endl;
							break;
						}
						choice.push_back(i);
					}
				}
				else if (c == 'b') break;
				else {
					cout << "Invalid Choice\n";
					break;
				}
			}
		}
		//break;
	}
}

int cal_score(vector<int> rolls){
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

	for (int i : count) cout << i << "\t";
	cout << endl;

	bool triple = false;
	for (size_t i =0; i<count.size(); i++){
		cout << score << "\t";
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
	cout << endl;
	return score;
}

