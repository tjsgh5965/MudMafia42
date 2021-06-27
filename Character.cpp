#include "Character.h"

int cin_set()
{
	if (!cin)
	{
		cin.clear();
		cin.ignore(999, '\n');
		return 0;
	}
	return 1;
}

#define cset cin_set();

string mainJob[] = { "마피아", "경찰", "의사", "기자", "군인",
"사립탐정", "마술사" };

string subJob[] = { "스파이", "짐승인간" };

string Character::printJob() {
	if (this->job > 0) return mainJob[this->job - 1];
	else return subJob[-(this->job) - 1];
}

void Character::memoPrint(vector<Character> v) {
	for (int i = 0; i < MEMBER; i++)
	{
		cout << i + 1 << "픽 : ";
		if (this->writeJob[i] == 0) cout << "?" << endl;
		else cout << v[i].printJob() << endl;
	}
}

void Character::useSkill(vector<Character> v, int member) {
	int select = 0;
	switch (this->job)
	{
	case 1:
		break;

	case 2:
		while (true)
		{
			cout << "조사할 사람을 선택하세요 : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				cout << select << "님은 마피아";
				if (v[select - 1].job == 1) {
					cout << "입니다." << endl;
					this->writeJob[select - 1] = 1;
					this->noChange[select - 1] = true;
				}
				else {
					cout << "가 아닙니다." << endl;
				}
				break;
			}
			else cset;
		}
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;

	default:
		break;
	}
}