#ifndef PIRAT_H
#define PIRAT_H

#include "../event.h"
class EventHandler;

class Pirat: public Event
{
public:
    Pirat(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString evStr(int id);
    QString sexStr(int id);
    QString media(int id);
    //pirat_events
    void pirat_search();
    void pirat_forced();
    void grandparentsIngadsarai();
    //pirat_sex
    void spurn();
    void stroking();
    void strokingHorny();
    void scream();
    void dogLick();
    void dogLickAss();
    void pirDogHJ();
    void pirDogBJ();
    void pirDogVag();
    void pirDogAnal();
    void lickingAss();
    void excite();
    //
    void pirPirat();
private:
    EventHandler* root;
};

#endif // PIRAT_H
