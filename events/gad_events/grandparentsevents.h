#ifndef GRANDPARENTSEVENTS_H
#define GRANDPARENTSEVENTS_H

#include "../event.h"
class Game;

class GrandparentsEvents: public Event
{
public:
    GrandparentsEvents(Game* ptr);
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

#endif // GRANDPARENTSEVENTS_H
