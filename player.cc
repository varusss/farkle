#include "player.h"
#include <cassert> 
using namespace std;

Player::Player(string new_name, unsigned int new_score = 0, unsigned int new_money = 0, unsigned int new_bet = 0) {
    name = new_name; score = new_score; money = new_money; bet = new_bet;
}

void Player::setScore(int added_value) {score = score + added_value;}
void Player::setName(string s) {name = s;}
void Player::setPlayerMoney(int new_money) {money = money + new_money;}
void Player::setBet(int new_bet) {bet = bet + new_bet;}
unsigned int Player::getScore() {return score;}
unsigned int Player::getBet() {return bet;}
unsigned int Player::getMoney() {return money;}
string Player::getName() {return name;}



