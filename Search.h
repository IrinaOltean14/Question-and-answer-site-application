#pragma once

#include <QWidget>
#include "ui_Search.h"
#include "User.h"
#include "RepoQuestions.h"
#include "RepoAnswer.h"
class Search : public QWidget
{
	Q_OBJECT

public:
	Search(RepoAnswer& repoA,RepoQuestion& repoQ,User& user,QWidget *parent = nullptr);
	~Search();

private:
	Ui::SearchClass ui;
	User& user;
	RepoQuestion& repoQ;
	RepoAnswer& repoA;
	void connectSignalsAndSlots();
	void searchQuestion();
};
