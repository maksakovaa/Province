#ifndef BROTHER_H
#define BROTHER_H

#include "../event.h"
class Game;

class Brother: public Event
{
public:
    Brother(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void smalltalk(QString arg);
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
    int age;
};

#endif // BROTHER_H
