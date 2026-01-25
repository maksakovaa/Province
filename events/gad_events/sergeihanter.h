#ifndef SERGEIHANTER_H
#define SERGEIHANTER

#include "../event.h"
class Game;

class SergeiHanter: public Event
{
public:
    SergeiHanter(Game* ptr);
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
    QString boy;
    int dicksize;
    int sexskill;
    int harakBoy;
    int boyAge;
};

#endif // SergeiHanter_H
