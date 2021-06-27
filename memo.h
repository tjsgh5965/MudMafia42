#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

class memo
{
public:
	
	int* writeJob = 0;
	bool* noChange;

	memo(int member) {
		this->writeJob = new int[member];
		this->noChange = new bool[member];

		for (int i = 0; i < member; i++)
		{
			this->noChange[i] = false;
			this->writeJob[i] = 0;
		}
	}

};

