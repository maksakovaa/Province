#ifndef GADFORESTRELAX_H
#define GADFORESTRELAX_H

#include "../event.h"
class EventHandler;

class GadforestRelax: public Event
{
public:
    GadforestRelax(EventHandler* ptr);
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

#endif // GADFORESTRELAX_H
