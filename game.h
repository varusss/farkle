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
        void printScoreboard(players);
}