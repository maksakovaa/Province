#ifndef DINSISTER_H
#define DINSISTER_H

#include "../event.h"
class Game;

class DinSister: public Event
{
public:
    DinSister(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
    void check_talktime();
    void talk();
    void sex_stories();
    void piercing();
    void sister_show();
    void beach_events();

private slots:
    void actionHandler(QString action);
private:
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
    int i;
};

#endif // DINSISTER_H
