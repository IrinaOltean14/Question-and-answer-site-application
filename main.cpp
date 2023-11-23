#include "Questions.h"
#include <QtWidgets/QApplication>
#include "RepoUser.h"
#include "RepoQuestions.h"
#include "RepoAnswer.h"
#include "Search.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    RepoUser repoUser{ "Users.txt" };
    RepoQuestion repoQ{ "Questions.txt" };
    RepoAnswer repoA{ repoQ,"Answers.txt" };
    
    
    for (auto user : repoUser.getAll()) {
        Questions* w = new Questions{repoA,repoQ, user};
        w->setWindowTitle(QString::fromStdString(user.getName())); 
        w->show();
        Search* a = new Search{ repoA,repoQ,user };
        a->setWindowTitle(QString::fromStdString(user.getName()));
        a->show();
    }
    return a.exec();
}
