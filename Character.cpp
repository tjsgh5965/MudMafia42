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

string mainJob[] = { "���Ǿ�", "����", "�ǻ�", "����", "����",
"�縳Ž��", "������" };

string subJob[] = { "������", "�����ΰ�" };

string Character::printJob() {
	if (this->job > 0) return mainJob[this->job - 1];
	else return subJob[-(this->job) - 1];
}

void Character::memoPrint(vector<Character> v) {
	for (int i = 0; i < MEMBER; i++)
	{
		cout << i + 1 << "�� : ";
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
			cout << "������ ����� �����ϼ��� : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				cout << select << "���� ���Ǿ�";
				if (v[select - 1].job == 1) {
					cout << "�Դϴ�." << endl;
					this->writeJob[select - 1] = 1;
					this->noChange[select - 1] = true;
				}
				else {
					cout << "�� �ƴմϴ�." << endl;
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