#ifndef GADFOREST_EVENT_H
#define GADFOREST_EVENT_H

#include "../event.h"
class EventHandler;

class GadforestEvent: public Event
{
public:
    GadforestEvent(EventHandler* ptr): root(ptr){}
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void search();
    void clothes1();
    void clothes2();
    void gadforest_lost_start();
    void gopforest_mitka();
    void gopforest_kolyamba();
    void gopforest_vasyan();
    void gopforest_2boys();
    void gopforest_3boys();
    void nude_event();
    void mushroom_pickers1();
    void mushroom_pickers2();
    void mushroom_pickers3();
    void mushroom();
    void billberry();
    void basket();
    void picnic();
    void forest_hanters();
    void forest_road();
    void swamp_road();
    void lost();
    void relax();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void makeActBtn(QString action, QString actName);
private:
    EventHandler* root;
};

#endif
