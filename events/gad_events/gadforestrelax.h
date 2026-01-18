#ifndef GADFORESTRELAX_H
#define GADFORESTRELAX_H

#include "../event.h"
class EventHandler;

class GadforestRelax: public Event
{
public:
    GadforestRelax(EventHandler* ptr);
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

#endif // GADFORESTRELAX_H
