#ifndef MIRASEX_H
#define MIRASEX_H

#include "../event.h"
class EventHandler;

class MiraSex: public Event
{
public:
    MiraSex(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void miralick_first();
    void mirakiss();
    void foreplay();
    void miralick_start();
    void lickmira_first();
    void lickmira_start();
    void horny_talk();
    void miralick_orgasm();
    void lickmira_mis1();
    void lickmira_mis2();
    void pose69_1();
    void pose69_2();
    void miralick_stand1();
    void miralick_stand2();
    void miralick_dog();
    void mirafinger();
    void mirafinger_dog();
    void end();
    void checkMiraSex();
private:
    EventHandler* root;
    int you_orgasm;
};

#endif // MIRASEX_H
