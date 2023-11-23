#pragma once
#include "Answer.h"
#include "RepoQuestions.h"
class RepoAnswer:public Subject {
private:
	vector<Answer> answers;
	string filename;
	RepoQuestion& repoQ;
public:
	RepoAnswer(RepoQuestion& repoQ, string filename) :repoQ{ repoQ },filename { filename } {
		readFromFile();
	}

	~RepoAnswer() {};

	vector<Answer> getAll();
	void readFromFile();
	void writeToFile();

	void addAnswer(string text, string name, int questionId);
};