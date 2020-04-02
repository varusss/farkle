#pragma once
#include <vector>
#include <cassert>
#include <cstdlib>
#include "die.h"
using std::vector;
using std::cout;
using std::endl;

class Table {
    private:
        vector<Die> table_die_vec;
         unsigned int wager;
         unsigned int current_score_of_turn;
         unsigned int max_score;
    public:
    Table();
    //Table(vector<unsigned int> table_dice, unsigned int new_wager, unsigned int new_current_score);
    Die getDie(int dieIndex);
    vector<Die> getDiceVec();
    void setWager(unsigned int new_wager);
    void setCurrentScore(unsigned int new_score);
    void setVecOfDice(vector<Die> new_dice);
    void setMaxScore(unsigned int new_max_score);
    unsigned int getWager();
    unsigned int getScore();
    unsigned int getMaxScore();
    
}; 