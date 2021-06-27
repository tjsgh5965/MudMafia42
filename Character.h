#pragma once
#include "memo.h"

#define pause system("pause>null");
#define cls system("cls");

#define MEMBER 8

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

class Character : public memo
{
public:
	int job = 0;
	
	Character(int job) : memo(MEMBER) {
		this->job = job;
	}

	string printJob();

	void memoPrint(vector<Character> v);
	void useSkill(vector<Character> v, int member);
};

