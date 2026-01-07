#ifndef GRANDMA_H
#define GRANDMA_H

#include "../event.h"
class EventHandler;

class Grandma: public Event
{
public:
    Grandma(EventHandler* ptr);
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

#endif // GRANDMA_H
