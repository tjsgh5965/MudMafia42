#include "Character.h"

int subJobCount = 2;
int specialJobCount = 4;

int randNum(int start, int end)
{
	random_device rd;
	std::mt19937 gen(rd());
	uniform_int_distribution<int> dis(start, end);
	return dis(gen);
}

vector<Character> raffleJob(int memberCount) {

	vector<int> specialJobList;

	for (int i = 0; i < specialJobCount; i++)
		specialJobList.emplace_back(i + 4);

	vector<Character> v;
	int mafiaCount = (memberCount < 8) ? 1 : 2;
	int specialCount = (memberCount < 5) ? 1 : (memberCount < 8) ? 2 : 3;
	bool subCount = (memberCount < 6) ? false : true;

	// 마피아 추가
	for (int i = 0; i < mafiaCount; i++)
		v.emplace_back(Character(1));
	// 경찰 추가
	v.emplace_back(Character(2));
	// 의사 추가
	v.emplace_back(Character(3));

	// 보조 추가
	if (subCount) v.emplace_back(Character(randNum(-subJobCount, -1)));

	// 특직 추가
	for (int i = 0; i < specialCount; i++) {
		int specialPick = randNum(0, specialJobList.size() - 1);
		vector<int>::iterator iter = specialJobList.begin() + specialPick;
		v.emplace_back(Character(specialJobList[specialPick]));
		specialJobList.erase(iter);
	}

	return v;
}

int main() {
	
	vector<Character> v = raffleJob(8);

	for (int i = 0; i < v.size(); i++)
		cout << i + 1 << "픽 : " << v[i].printJob() << endl;

	return 0;
}