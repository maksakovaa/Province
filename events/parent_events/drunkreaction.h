#ifndef DRUNKREACTION_H
#define DRUNKREACTION_H

#include "../event.h"
class Game;

class DrunkReaction: public Event
{
public:
    DrunkReaction(Game* ptr);
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

#endif // DRUNKREACTION_H
