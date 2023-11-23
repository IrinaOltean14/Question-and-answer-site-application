#pragma once
#include <string>
#include <vector>
using namespace std;

class Question {
private:
	int id{};
	string name;
	string text;
	int answers{};
public:
	Question() {}
	Question(int id, string name, string text):id{id}, name{name}, text{text}{}
	~Question() {}

	string toString();
	void incrementAsnwers();
	int getAnswers() {
		return this->answers;
	}
	int getId();
	string getText();

	vector<string> tokenize(string str, char delimiter);
	friend istream& operator>>(istream& is, Question& q);
	friend ostream& operator<<(ostream& os, Question& q);
};