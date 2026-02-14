#ifndef SISTER_H
#define SISTER_H

#include "../event.h"
class Game;

class Sister: public Event
{
public:
    Sister(Game* ptr);
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
    QString sisBoyDayText;
};

#endif // SISTER_H
