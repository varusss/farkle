#include "die.h"
#include <cassert>
#include <random>
#include <iostream>
using namespace std;

Die::Die() : SIDES(6), last_roll(0), name("Normal Dice") {
	for (unsigned int i = 0; i < SIDES; i++)
		weight.push_back(1.0/SIDES);
}

Die::Die(vector<double> new_weights, const int new_sides, string new_name) : SIDES(new_sides), last_roll(0), name(new_name){
	assert(new_sides >= 4);
	assert(new_weights.size() == SIDES);
	double sum = 0;
	for (unsigned int i = 0; i < SIDES; i++) {
		assert(new_weights[i] >= 0 && new_weights[i] <= 1);
		sum += new_weights[i];
		vec.push_back(new_weights[i] * 100);
		weight.push_back(new_weights[i]);
		cheat = true;
	}
	assert(sum > .99 && sum < 1.01);
}

int Die::get_roll() {
	assert(last_roll >= 1 && last_roll <= SIDES);
	return last_roll;
}

void Die::roll() {
	last_roll = rand()%SIDES +1;
	if (cheat) {
		discrete_distribution<int> d{vec.begin(), vec.end()};
		random_device device;
		last_roll = d(device) + 1;
	}
}

string Die::getName() { return name;}

Die Die::operator=(const Die& rhs){
	Die temp;
	temp.weight = rhs.weight;
	return temp;
}
