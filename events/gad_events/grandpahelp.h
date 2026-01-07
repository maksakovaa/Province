#ifndef GRANDPAHELP_H
#define GRANDPAHELP_H

#include "../event.h"
class EventHandler;

class GrandpaHelp: public Event
{
public:
    GrandpaHelp(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void fnGrandpaHelping();
    void genimage();
    void no_job_today();
private:
    EventHandler* root;
};

#endif // GRANDPAHELP_H
