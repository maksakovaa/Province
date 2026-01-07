#ifndef GRANDPA_H
#define GRANDPA_H

#include "../event.h"
class EventHandler;

class Grandpa: public Event
{
public:
    Grandpa(EventHandler* ptr);
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

#endif // GRANDPA_H
