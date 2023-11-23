#include "Answer.h"
#include <sstream>

int Answer::getQueestion() {
	return this->idQuestion;
}

string Answer::getName() {
	return this->name;
}

int Answer::getVotes() {
	return this->votes;
}

string Answer::toString() {
	return to_string(this->id) + " | " + to_string(this->idQuestion) + " | " + this->text + " | " + this->name + " | " + to_string(this->votes);
}

vector<string> Answer::tokenize(string str, char delimiter) {
	stringstream ss(str);
	string token;
	vector<string> result;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Answer& q) {
	string line;
	getline(is, line);
	if (line.empty())
		return is;
	vector<string> tokens = q.tokenize(line, ',');
	q.id = stoi(tokens[0]);
	q.idQuestion = stoi(tokens[1]);
	q.text = tokens[2];
	q.name = tokens[3];
	q.votes = stoi(tokens[4]);
	return is;

}

ostream& operator<<(ostream& os, Answer& q) {
	os << to_string(q.id) + "," + to_string(q.idQuestion) + ","+q.name+","+ q.text + "," + to_string(q.votes);
	return os;
}