#include "Character.h"

string mainJob[] = { "���Ǿ�", "����", "�ǻ�", "����", "����",
"�縳Ž��", "������" };

string subJob[] = { "������", "�����ΰ�" };

string Character::printJob() {
	if (this->job > 0) return mainJob[this->job - 1];
	else return subJob[-(this->job) - 1];
}