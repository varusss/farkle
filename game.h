#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include "die.h"
#include "player.h"
#include "table.h"
#include "scoreboard.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Game {
    private:
        Table table;
        Scoreboard scoreboard;
        vector<Player> players;

    public:
        Game();
        void printScoreboard(vector<Player> players);
        int prompt(const int flag);
        void startGame();
        unsigned int retrieveBet();
        void takeBets(int bet);
        void gameOver();
        void startRolling();
        unsigned int cal_score(vector<int> rolls);
};