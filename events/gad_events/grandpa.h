#ifndef GRANDPA_H
#define GRANDPA_H

#include "../event.h"
class Game;

class Grandpa: public Event
{
public:
    Grandpa(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    Game* root;
};

#endif // GRANDPA_H
