#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

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

class Character
{
public:
	int job = 0;
	
	Character(int job) {
		this->job = job;
	}

	string printJob();
};

