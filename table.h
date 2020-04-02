#pragma once
#include <vector>
#include <cassert>
#include <cstdlib>
using std::vector;
using std::cout;
using std::endl;

class Table {
    private:
        vector<Die> table_die_vec;
         unsigned int wager;
         unsigned int current_score_of_turn;
    public:
    Table();
    Table(vector<unsigned int> table_dice, unsigned int new_wager, unsigned int new_current_score);
    void setWager(unsigned int new_wager) {wager = new_wager;}
    void setCurrentScore(unsigned int new_score) {current_score_of_turn = new_score;}
    void setVecOfDice(vector<unsigned int> new_dice) {table_die_vec = new_dice;}
    unsigned int getWager() {return wager;}
    unsigned int getScore() {return current_score_of_turn;}
    unsigned int getDiceVec() {return table_die_vec;}



}; 