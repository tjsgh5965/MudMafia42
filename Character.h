#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1 : 마피아
// 2 : 경찰
// 3 : 의사
// 4 : 기자
// 5 : 군인
// 6 : 사립탐정
// 7 : 마술사
// 
// -1 : 스파이
// -2 : 짐승인간

class Character
{
public:
	int job = 0;
	
	Character(int job) {
		this->job = job;
	}

	string printJob();
};

