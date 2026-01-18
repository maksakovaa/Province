#ifndef MEADOWEVENT_H
#define MEADOWEVENT_H

#include "../event.h"
class EventHandler;

class MeadowEvent: public Event
{
public:
    MeadowEvent(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    void mira_mitka();
    void mira_gang();
    void miragopQW11();
    void lesb_mira();
    void mira_lesb();
    void lesb_talk_mira1();
    void lesb_talk_mira2();
    void lesb_talk_mira3();
    void mira_lesb_talk1();
    void mira_lesb_talk2();
    void mira_lesb_talk3();
    void mira_lesb_talk4();
    void mirameadow();
private:
    EventHandler* root;
};

#endif // MEADOWEVENT_H
