#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
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
        
    public:
        Player(string new_name, unsigned int new_score, unsigned int new_money, unsigned int new_bet);
        void setScore(int added_value);
        void setName(string s);
        void setPlayerMoney(int new_money);
        void setBet(int new_bet);
        unsigned int getScore();
        unsigned int getBet();
        unsigned int getMoney();
        string getName();
        
};