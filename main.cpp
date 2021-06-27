#include "Character.h"

int subJobCount = 2;
int specialJobCount = 4;

int dayCount = 0;
bool isNight = false;

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

	// 직업 섞기
	int idx1, idx2, temp;
	for (int i = 0; i < memberCount * 2; i++)
	{
		idx1 = randNum(0, memberCount - 1);
		idx2 = randNum(0, memberCount - 1);
		swap(v[idx1], v[idx2]);
	}

	return v;
}

void Debug(vector<Character> v) {
	for (int i = 0; i < v.size(); i++)
		cout << i + 1 << "픽 : " << v[i].printJob() << endl;
	cout << "\n\n";
}

int main() {
	
	vector<Character> v = raffleJob(MEMBER);
	int myPick = randNum(0, MEMBER - 1);
	Character me = v[myPick];

	//Debug(v);

	cout << "당신의 직업은 " << me.printJob() << "입니다.\n\n";
	me.writeJob[myPick] = me.job;

	while (true)
	{
		isNight = !isNight;
		cout <<endl << ((isNight) ? "밤이 되었습니다." : "낮이 되었습니다.") << "\n\n";
		me.memoPrint(v);
		if (isNight) {
			dayCount++;
			me.useSkill(v, MEMBER);
		}
		else pause;
	}

	return 0;
}