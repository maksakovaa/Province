#ifndef GRANDPARENTSEVENTS_H
#define GRANDPARENTSEVENTS_H

#include "../event.h"
class EventHandler;

class GrandparentsEvents: public Event
{
public:
    GrandparentsEvents(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
};

#endif // GRANDPARENTSEVENTS_H
