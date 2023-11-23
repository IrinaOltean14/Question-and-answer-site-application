#pragma once
#include "User.h"
#include <vector>

class RepoUser {
private:
	vector<User> users;
	string filename;
public:
	RepoUser(string filename) :filename{ filename } {
		readFromFile();
	}
	~RepoUser() {}

	void readFromFile();
	vector<User> getAll();
};