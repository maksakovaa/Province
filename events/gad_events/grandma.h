#ifndef GRANDMA_H
#define GRANDMA_H

#include "../event.h"
class Game;

class Grandma: public Event
{
public:
    Grandma(Game* ptr);
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

#endif // GRANDMA_H
