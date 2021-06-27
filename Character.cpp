#include "Character.h"

string mainJob[] = { "마피아", "경찰", "의사", "기자", "군인",
"사립탐정", "마술사" };

string subJob[] = { "스파이", "짐승인간" };

string Character::printJob() {
	if (this->job > 0) return mainJob[this->job - 1];
	else return subJob[-(this->job) - 1];
}