#pragma once
#include "memo.h"

#define pause system("pause>null");
#define cls system("cls");

#define MEMBER 8

using namespace std;

// 1 : ���Ǿ�
// 2 : ����
// 3 : �ǻ�
// 4 : ����
// 5 : ����
// 6 : �縳Ž��
// 7 : ������
// 
// -1 : ������
// -2 : �����ΰ�

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

