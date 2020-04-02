#include "scoreboard.h"
using namespace std;

Scoreboard::Scoreboard() {player_scoreboard = {};}
Scoreboard::Scoreboard(int num_of_players) {player_scoreboard = vector<unsigned int> (6,0);}
void Scoreboard::print(vector<Player> &players) {
    cout << "===== SCOREBOARD =====" 
         << "======================" << endl;
    for (size_t i = 0; i < players.size(); i++) {
        cout <<  players[i].getName() 
        << ": " << player_scoreboard[i] << endl;
    }
}
void Scoreboard::updateScore(int added_value, int index_of_player) {
    player_scoreboard[index_of_player] += added_value;
}

