#ifndef SWAMPEVENTS_H
#define SWAMPEVENTS_H

#include "../event.h"
#include <QObject>

class EventHandler;

class SwampEvents: public Event
{
public:
    SwampEvents(EventHandler* ptr);
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

#endif // SWAMPEVENTS_H
