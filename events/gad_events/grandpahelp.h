#ifndef GRANDPAHELP_H
#define GRANDPAHELP_H

#include "../event.h"
class Game;

class GrandpaHelp: public Event
{
public:
    GrandpaHelp(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void fnGrandpaHelping();
    void genimage();
    void no_job_today();
private:
    Game* root;
};

#endif // GRANDPAHELP_H
