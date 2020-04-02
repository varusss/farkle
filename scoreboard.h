#pragma once
#include <vector>
#include "player.h"
using std::vector;

class Scoreboard {
    private: 
        vector<unsigned int> player_scoreboard; 
    public:
        Scoreboard();
        Scoreboard(int num_of_players);
        void print(vector<Player> &players);
        void updateScore(int added_value, int index_of_player);
};
