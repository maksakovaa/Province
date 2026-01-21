#ifndef FAMILY_H
#define FAMILY_H

#include "../event.h"

class EventHandler;

class Family: public Event
{
public:
    Family(EventHandler* parent);
    void start(QString arg = 0) override;
private:
    void checkTrip();
    void mother_sheduler();
    void father_sheduler();
    void sister_sheduler();
    void brother_sheduler();
    void mother_act();
    void father_act();
    void brother_act();
    void sister_act();
    QString media(int id);
    QString str(int id);
    EventHandler* root;
};

#endif // FAMILY_H
