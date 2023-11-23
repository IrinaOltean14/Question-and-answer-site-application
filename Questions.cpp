#include "Questions.h"
#include <algorithm>
#include <fstream>
#include <qmessagebox.h>
Questions::Questions(RepoAnswer& repoA,RepoQuestion& repoQ, User& user,QWidget *parent)
    : QWidget(parent), repoQ{repoQ}, user{user}, repoA{repoA}
{
    ui.setupUi(this);
    populate();
    this->repoQ.addObserver(this);
    this->repoA.addObserver(this);
    connectSignalsAndSlots();
    /*ofstream f("ceva.txt");
    f << this->user.getName();
    f.close();*/
}

Questions::~Questions()
{}

void Questions::populate() {
    this->ui.questionslistWidget->clear();
    vector<Question> questions = this->repoQ.getAll();
    sort(questions.begin(), questions.end(), [](Question& a, Question& b) {return a.getAnswers() > b.getAnswers(); });
    for (auto q : questions)
        this->ui.questionslistWidget->addItem(QString::fromStdString(q.toString()));
}

void Questions::update() {
    showAnswers();
    populate();
}

void Questions::connectSignalsAndSlots() {
    QObject::connect(this->ui.addpushButton, &QPushButton::clicked, this, &Questions::addQuestion);
    QObject::connect(this->ui.questionslistWidget, &QListWidget::itemSelectionChanged, this, &Questions::showAnswers);
    QObject::connect(this->ui.answerpushButton, &QPushButton::clicked, this, &Questions::addAnswer);
}

void Questions::addQuestion() {
    string text = this->ui.textlineEdit->text().toStdString();
    string name = this->windowTitle().toStdString();
    try {
        this->repoQ.addQuestion(text, name);
    }
    catch (const char* error) {
        QMessageBox* m = new QMessageBox{};
        m->setText(error);
        m->show();
    }
}

void Questions::showAnswers() {
    this->ui.answerslistWidget->clear();
    int index = this->ui.questionslistWidget->currentRow();
    vector<Question> questions = this->repoQ.getAll();
    sort(questions.begin(), questions.end(), [](Question& a, Question& b) {return a.getAnswers() > b.getAnswers(); });
    if (index >= 0 && index < questions.size()) {
        Question q = questions[index];
        string name = this->windowTitle().toStdString();
        int index1 = 0;
        for (auto a : this->repoA.getAll())
            if (q.getId() == a.getQueestion()) {
                this->ui.answerslistWidget->addItem(QString::fromStdString(a.toString()));
                if (a.getName() == name)
                    this->ui.answerslistWidget->item(index1)->setBackground(QBrush(Qt::yellow));
                index1++;
            }
    }
}


void Questions::addAnswer() {
    int index = this->ui.questionslistWidget->currentRow();
    vector<Question> questions = this->repoQ.getAll();
    sort(questions.begin(), questions.end(), [](Question& a, Question& b) {return a.getAnswers() > b.getAnswers(); });
    Question q = questions[index];
    string text = this->ui.answerlineEdit->text().toStdString();
    string name = this->windowTitle().toStdString();
    this->repoA.addAnswer(text, name, q.getId());
}
