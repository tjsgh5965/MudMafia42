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

void Character::memoPrint(vector<Character> &v) {
	
	for (int i = 0; i < MEMBER; i++)
	{
		cout << i + 1 << "픽 : ";
		if (this->writeJob[i] == 0) cout << "?"; else cout << v[i].printJob();

		if (v[i].death) cout << " (사망)";
		cout << endl;
	}
	cout << endl;
}

void Character::isMorning(vector<Character>& v) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].repoterTarget) {
			v[i].repoterTarget = false;
			this->isUseSkill = true;
			cout << "특종입니다! " << i + 1 << "님이 " << v[i].printJob() << "(이)라는 소식입니다!\n";
			this->writeJob[i] = v[i].job;
			this->noChange[i] = true;
			break;
		}
	}
}

void Character::useSkill(vector<Character> &v, int member) {
	int select = 0;
	switch (this->job)
	{
	case 1:
		while (true)
		{
			cout << "처형할 사람을 선택하세요 : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				v[select - 1].death = true;
				break;
			}
			else cset;
		}
		break;

	case 2: // 경찰
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

	case 4: // 기자
		if (!this->isUseSkill) {
			while (true)
			{
				cout << "취재할 사람을 선택하세요 : ";
				cin >> select;
				if (select >= 1 && select <= member) {
					v[select - 1].repoterTarget = true;
					break;
				}
				else cset;
			}
		}
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;

	case -1: // 스파이
		while (true)
		{
			cout << "조사할 사람을 선택하세요 : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				cout << select << "님의 직업은 " << v[select - 1].printJob() << " 입니다.\n";
				if (v[select - 1].job == 1) { // 마피아면 접선
					cout << "접선했습니다.\n";
					for (int i = 0; i < v.size(); i++){
						if (v[i].job == 1 && i != select - 1) {
							this->writeJob[i] = v[i].job;
							this->noChange[i] = true;

						}
					}
				}
				this->writeJob[select - 1] = v[select - 1].job;
				this->noChange[select - 1] = true;
				break;
			}
			else cset;
		}
		break;

	default:
		break;
	}
}