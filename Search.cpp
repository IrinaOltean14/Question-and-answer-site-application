#include "Search.h"
#include <algorithm>
Search::Search(RepoAnswer& repoA,RepoQuestion& repoQ, User& user, QWidget *parent)
	: QWidget(parent), repoQ{ repoQ }, user{ user }, repoA{repoA}
{
	ui.setupUi(this);
	connectSignalsAndSlots();
}

Search::~Search()
{}


void Search::connectSignalsAndSlots() {
	QObject::connect(this->ui.searchlineEdit, &QLineEdit::textChanged, this, &Search::searchQuestion);
}

void Search::searchQuestion() {
	this->ui.searchlistWidget->clear();
	if (!this->ui.searchlineEdit->text().isEmpty()) {
		string text = this->ui.searchlineEdit->text().toStdString();

		int min = 9999999;
		int current;
		Question question;
		for (auto q : this->repoQ.getAll())
			if (q.getText().find(text) != string::npos) {
				current = q.getText().size() / text.size();
				if (current < min) {
					min = current;
					question = q;
				}
			}
		if (min != 9999999)
			this->ui.searchlistWidget->addItem(QString::fromStdString(question.toString()));
		vector<Answer> answers;
		for (auto a : this->repoA.getAll())
			if (a.getQueestion() == question.getId())
				answers.push_back(a);
		sort(answers.begin(), answers.end(), [](Answer a, Answer b) {return a.getVotes() > b.getVotes(); });
		int index = 0;
		for (auto a : answers) {
			this->ui.searchlistWidget->addItem(QString::fromStdString(a.toString()));
			index++;
			if (index == 3)
				break;
		}
	}
	
}