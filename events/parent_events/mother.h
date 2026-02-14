#ifndef MOTHER_H
#define MOTHER_H

#include "../event.h"
class Game;

class Mother: public Event
{
public:
    Mother(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
    int age;
};

#endif // MOTHER_H
