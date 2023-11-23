#pragma once

#include <QtWidgets/QWidget>
#include "ui_Questions.h"
#include "User.h"
#include "RepoQuestions.h"
#include "RepoAnswer.h"
#include "Observer.h"
class Questions : public QWidget, public Observer
{
    Q_OBJECT

public:
    Questions(RepoAnswer& repoA,RepoQuestion& repoQ, User& user,QWidget *parent = nullptr);
    ~Questions();

private:
    Ui::QuestionsClass ui;
    User& user;
    RepoQuestion& repoQ;
    RepoAnswer& repoA;
    void populate();
    virtual void update() override;
    void connectSignalsAndSlots();
    void addQuestion();
    void showAnswers();
    void addAnswer();
};
