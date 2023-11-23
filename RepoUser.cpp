#include "RepoUser.h"

void RepoUser::readFromFile() {
	ifstream f(this->filename);
	User u;
	while (f >> u)
		this->users.push_back(u);
	f.close();
}

vector<User> RepoUser::getAll() {
	return this->users;
}