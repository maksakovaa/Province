#ifndef ANDREIHANTER_H
#define ANDREIHANTER_H

#include "../event.h"
class EventHandler;

class AndreiHanter: public Event
{
public:
    AndreiHanter(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
};

#endif // ANDREIHANTER_H
