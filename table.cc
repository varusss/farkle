#include <iostream>
#include "table.h"
using namespace std;

Table::Table() {
    //cout << "reaching?\n";
    table_die_vec.push_back(Die());
    table_die_vec.push_back({{.20,.30,.10,.10,.10,.20},6, "Biased Die"});
    table_die_vec.push_back({{.20,.30,.10,.10,.10,.20},6, "Ci Die"});
    table_die_vec.push_back({{.05,.19,.19,.19,.19,.19},6, "Die of Misfortune"});
    table_die_vec.push_back({{.10,.233,.10,.233,.10,.233},6, "Even Number Die"});
    table_die_vec.push_back({{.1,.1,.1,.1,.1,.5},6, "Fer Die"});
    table_die_vec.push_back({{.35,.10,.10,.10,.10,.25},6, "Heavenly Kingdom Die"});
    table_die_vec.push_back({{.12,.12,.40,.12,.12,.12},6, "Holy Trinity Die"});
    table_die_vec.push_back({{.1,.1,.1,.1,.1,.5},6, "Lu Die"});
    table_die_vec.push_back({{.30,.14,.14,.14,.14,.14},6, "Lucky Die"});
    table_die_vec.push_back({{.50,.10,.10,.10,.10,.10},6, "Lucky Playing Die"});
    table_die_vec.push_back({{.233,.10,.233,.10,.233,.10},6, "Odd Die"});
    table_die_vec.push_back({{.20,.15,.15,.15,.15,.20},6, "Shrinking playing Die"});
    table_die_vec.push_back({{.20,.15,.15,.15,.15,.20},6, "Strip Die"});
    table_die_vec.push_back({{.20,.20,.30,.10,.10,.10},6, "Unpopular Die"});
}

Die Table::getDie(int dieIndex) {return table_die_vec[dieIndex-1]; cout << table_die_vec.size() << endl;} // minus 1 because player is choosing 1-15
vector<Die> Table::getDiceVec() {return table_die_vec;}
void Table::setWager(unsigned int new_wager) {wager = wager + new_wager;}
void Table::setCurrentScore(unsigned int new_score) {current_score_of_turn = new_score;}
void Table::setVecOfDice(vector<Die> new_dice) {table_die_vec = new_dice;}
void Table::setMaxScore(unsigned int new_max_score) {max_score = new_max_score;}
unsigned int Table::getWager() {return wager;}
unsigned int Table::getScore() {return current_score_of_turn;}
unsigned int Table::getMaxScore() {return max_score;}