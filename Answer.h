#pragma once
#include <string>
#include <vector>
using namespace std;

class Answer {
private:
	int id{}, idQuestion{}, votes{};
	string name, text;
public:
	Answer() {};
	Answer(int id, int q, string name, string text, int votes) :id{ id }, idQuestion{ q }, name{ name }, text{ text }, votes{ votes } {}
	~Answer() {}

	int getQueestion();
	int getVotes();
	string toString();
	string getName();
	int getId() {
		return this->id;
	}

	vector<string> tokenize(string str, char delimiter);
	friend istream& operator>>(istream& is, Answer& a);
	friend ostream& operator<<(ostream& os, Answer& a);
};