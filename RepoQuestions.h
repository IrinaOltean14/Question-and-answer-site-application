#pragma once
#include "Question.h"
#include "Observer.h"
class RepoQuestion:public Subject {
private:
	vector<Question> questions;
	string filename;
public:
	RepoQuestion(string filename) :filename{ filename } {
		readFromFile();
	}
	~RepoQuestion() {}

	vector<Question>& getAll();
	void addQuestion(string text, string name);

	void readFromFile();
	void writeToFile();
};