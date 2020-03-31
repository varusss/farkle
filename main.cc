//Write your last name and your partner's name here
#include <iostream>
#include "die.h"
using namespace std;

int main() {
	srand(time(0));
	
	vector<Die> selected_dice;
	cout << "Choose 5 Dice\n";
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
			Die temp({.20,.30,.10,.10,.10,.20},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 3 or dice ==6 or dice == 9){ //ci, fer, and lu die
			Die temp({.1,.1,.1,.1,.1,.5},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 4){ //misfortune
			Die temp({.05,.19,.19,.19,.19,.19},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 5){ //even number
			Die temp({.10,.233,.10,.233,.10,.233},6);
			selected_dice.push_back(temp);
		}
		else if (dice ==7){ //heavenly kingdom
			Die temp({.35,.10,.10,.10,.10,.25},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 8){ //holy trinity
			Die temp({.12,.12,.40,.12,.12,.12},6);
			selected_dice.push_back(temp);
		}
		else if (dice ==10) {//lucky die
			Die temp({.30,.14,.14,.14,.14,.14},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 11){ //lucky playing dice
			Die temp({.50,.10,.10,.10,.10,.10},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 12){ //odd dice
			Die temp({.233,.10,.233,.10,.233,.10},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 13){ //Shrinking playing die
			Die temp({.20,.15,.15,.15,.15,.20},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 14){ //strip die
			Die temp({.20,.15,.15,.15,.15,.20},6);
			selected_dice.push_back(temp);
		}
		else if (dice == 15){ //unpopular die 
			Die temp({.20,.20,.30,.10,.10,.10},6);
			selected_dice.push_back(temp);
		}	
		if (selected_dice.size() == 5) break;
	}
	for (size_t i=0; i<selected_dice.size(); i++){
		for (int j =0; j < 15; j++){
			selected_dice[i].roll();
			cout << selected_dice[i].get_roll() << "  ";
		}
		cout << endl;
	}

}
