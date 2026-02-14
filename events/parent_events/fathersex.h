#ifndef FATHERSEX_H
#define FATHERSEX_H

#include "../event.h"
class Game;

class FatherSex: public Event
{
public:
    FatherSex(Game* ptr);
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
};

#endif // FATHERSEX_H
