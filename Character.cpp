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

void Character::memoPrint(vector<Character> &v) {
	
	for (int i = 0; i < MEMBER; i++)
	{
		cout << i + 1 << "�� : ";
		if (this->writeJob[i] == 0) cout << "?"; else cout << v[i].printJob();

		if (v[i].death) cout << " (���)";
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
			cout << "Ư���Դϴ�! " << i + 1 << "���� " << v[i].printJob() << "(��)��� �ҽ��Դϴ�!\n";
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
			cout << "ó���� ����� �����ϼ��� : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				v[select - 1].death = true;
				break;
			}
			else cset;
		}
		break;

	case 2: // ����
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

	case 4: // ����
		if (!this->isUseSkill) {
			while (true)
			{
				cout << "������ ����� �����ϼ��� : ";
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

	case -1: // ������
		while (true)
		{
			cout << "������ ����� �����ϼ��� : ";
			cin >> select;
			if (select >= 1 && select <= member) {
				cout << select << "���� ������ " << v[select - 1].printJob() << " �Դϴ�.\n";
				if (v[select - 1].job == 1) { // ���ǾƸ� ����
					cout << "�����߽��ϴ�.\n";
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