#ifndef SISTERQW_H
#define SISTERQW_H

#include "../event.h"
class Game;

class SisterQW: public Event
{
public:
    SisterQW(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void sisboyQW_caress();
    void sisboyQWsee();
    void sisboyQW_bedroom();
    void sisboyQW_expel();
    void sisboytrio_prepeare();
    void sisboytrio_suck();
    void sisboytrio_sex();
    void sisboytrio_end();
    void sisboytrioQW_bedroom();
    void sisboyQW_party();
    void sisboy_dance();
    void sisboy_drink();
    void sisboy_sit();
    void sisboy_twoboy();
    void sisboy_annaFind();
    void sisboy_reks();
    void sisboy_Annakuch();
    void sisboy_Annatoilet();
    void sisboy_Annakom();

    void party_pre_conditions();
    void meet_sister();

    void incest_event1();
    void incest_event2();
    void incest_event3();
    void incest_event3sub();
    void incest_event4();
    void incest_event5();
    void incest_event5sub();
    void incest_event6();
    void incest_event6shop();
    void incest_event6sub();
    void incest_event7();
    void incest_event8();
    void incest_event8sub();
    void incest_event9();
    void incest_event10();
    void incest_event10sub();
    void incest_event11();

    void incest_mini1();
    void incest_mini2();

    void incest_dialog1();
    void incest_dialog2();
    void incest_dialog3();

    void incest_event12sub();
    void incest_event12();
    void incest_event14();

    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
};

#endif // SISTERQW_H
