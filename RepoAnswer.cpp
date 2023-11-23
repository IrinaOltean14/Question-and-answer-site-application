#include "RepoAnswer.h"
#include <fstream>
#include "RepoQuestions.h"
vector<Answer> RepoAnswer::getAll() {
	return this->answers;
}

void RepoAnswer::readFromFile() {
	ifstream f(this->filename);
	Answer q;
	while (f >> q) {
		this->answers.push_back(q);
		for (auto& question : this->repoQ.getAll())
			if (question.getId() == q.getQueestion())
				question.incrementAsnwers();
	}
	f.close();
}

void RepoAnswer::writeToFile() {
	ofstream f(this->filename);
	for (auto q : this->answers)
		f << q << endl;
	f.close();
}

void RepoAnswer::addAnswer(string text, string name, int questionId) {
	Answer q = this->answers.back();
	int id = q.getId();
	id++;
	this->answers.push_back(Answer(id, questionId, text, name,0));
	writeToFile();
	notify();
}