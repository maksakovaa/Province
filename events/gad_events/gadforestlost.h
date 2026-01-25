#ifndef GADFORESTLOST_H
#define GADFORESTLOST_H

#include "../event.h"
class Game;

class GadforestLost: public Event
{
public:
    GadforestLost(Game* ptr);
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

#endif // GADFORESTLOST_H
