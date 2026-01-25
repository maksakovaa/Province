#ifndef ANDREIHANTER_H
#define ANDREIHANTER_H

#include "../event.h"
class Game;

class AndreiHanter: public Event
{
public:
    AndreiHanter(Game* ptr);
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

#endif // ANDREIHANTER_H
