#include "Question.h"
#include <sstream>

string Question::getText() {
	return this->text;
}

int Question::getId() {
	return this->id;
}

string Question::toString() {
	return to_string(this->id) + " | " + this->text + " | " + this->name;
}

void Question::incrementAsnwers() {
	this->answers++;
}

vector<string> Question::tokenize(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string> result;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Question& q) {
	string line;
	getline(is, line);
	if (line.empty())
		return is;
	vector<string> tokens = q.tokenize(line, ',');
	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.name = tokens[2];
	return is;
}

ostream& operator<<(ostream& os, Question& q) {
	os << to_string(q.id) + "," + q.text + "," + q.name;
	return os;
}