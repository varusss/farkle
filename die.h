#pragma once
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
using std::vector;
//using std::cout;
using std::endl;
using std::string;
class Die {
	const unsigned int SIDES;
	vector<double> weight;
	vector<int> vec;
	unsigned int last_roll;
	string name;
	bool cheat = false;
	public:
	Die(); //Create a fair die
	Die(vector<double> new_weights, int new_sides, string new_name); //Create a cheater die
	int get_roll(); //Return the last value rolled
	void roll(); //Set the die to a random value
	string getName();
	Die operator=(const Die& rhs);
};
