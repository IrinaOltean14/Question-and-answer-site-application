#pragma once
#include <string>
#include <fstream>
using namespace std;

class User {
private:
	string name;
public:
	User() {};
	User(string name) :name{ name } {};
	~User() {}

	string getName();

	friend istream& operator>>(istream& is, User& u);
	friend ostream& operator<<(ostream& os, User& u);
};