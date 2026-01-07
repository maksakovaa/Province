#ifndef GRANDMAHELP_H
#define GRANDMAHELP_H

#include "../event.h"
class EventHandler;

class GrandmaHelp: public Event
{
public:
    GrandmaHelp(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void fnGrandmaHelping();
private:
    EventHandler* root;
};

#endif // GRANDMAHELP_H
