#include "User.h"

istream& operator>>(istream& is, User& u) {
	string line;
	getline(is, line);
	if (line.empty())
		return is;
	u.name = line;
	return is;
}

ostream& operator<<(ostream& os, User& u) {
	os << u.name;
	return os;
}

string User::getName() {
	return this->name;
}