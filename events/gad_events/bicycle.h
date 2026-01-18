#ifndef BICYCLE_H
#define BICYCLE_H


#include "../event.h"
class EventHandler;


class Bicycle: public Event
{
public:
    Bicycle(EventHandler* ptr);
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

#endif // BICYCLE_H
