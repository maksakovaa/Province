#ifndef GADUKINO_EVENTS_H
#define GADUKINO_EVENTS_H

#include "../event.h"
class EventHandler;

class GadukinoEvent: public Event
{
public:
    GadukinoEvent(EventHandler* parent): root(parent){}
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void gadsarai_check();
    void walk();
    void mira_apologise();
    void mitka_apologise();
    void gang_apologise();
    void gadrivergang();
    void gadukino_mitka();
    void gadukino_kolyamba();
    void gadukino_vasyan();
    void gadukino_2boys();
    void mira_mitka();
    void mira_kolyamba();
    void mira_vasyan();
    void mira_2boys();
    void mira_3boys();
    void go_home();
    void go_home_ender();
    void to_gadukino();
    void collection_point();
    void gadukino_back();
    void gadukino_nude();
    void gadukino_nude_end();
    void gadriver_nude();
    void gadriver_nude_end();
    void onlooker();
    void gadukino_onlooker();
    void gadukino_onlooker_woman();
    void gadukino_onlooker_man();
    void gadukino_end();
    void pack_things();
    void punishment();
    void absolution();
    void offense();
    void clearing_basket();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int i;
    int walki;
    int last_walk;
};


#endif // GADUKINO_EVENTS_H
