#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "die.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Player {
    private:
        string name;
        unsigned int score;
        unsigned int money;
        unsigned int bet;
        vector<Die> dice;
    public:
        Player(string new_name, unsigned int new_score, unsigned int new_money, unsigned int new_bet, vector<Die> new_dice);
        void setScore(int added_value);
        void setName(string s);
        void setMoney(int new_money);
        void setBet(int new_bet);
       	void setDice(vector<Die> new_dice);
		unsigned int getScore();
        unsigned int getBet();
        unsigned int getMoney();
        string getName();
		Die getDie(int i);     
		vector<Die> getDiceSet();
};
