#ifndef HANTERSLOVESEX_H
#define HANTERSLOVESEX_H

#include "../event.h"
class EventHandler;

class HantersLoveSex: public Event
{
public:
    HantersLoveSex(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void first_sex();
    void bj_common();
    void bj_common1(int h);
    void bj_common1_alt(int h);
    void bj_common2();
    void bj_common2_alt();
    void bj_common2_alt2();
    void bj_common2_alt3();
    void bj_common2_alt4();
    void bj_common2_alt5();
    void bj_common3(int h);
    void bj_common3_alt(int h);
    void bj_common3_alt2(int h);
    void bj_common4(int h);
    void bj_common4_alt(int h);

    void bj();
    void bj1();
    void bj2();
    void bj3();
    void bj4();
    void bj5();
    void bj6();
    void bj7();
    void bj8();
    void bj9();
    void bj10();
    void bj11();
    void bj12();
    void bj13();
    void bj14();
    void bj200();
    void bj_bonus1();
    void bj_bonus2();
    void bj_bonus3();
    void bj_bonus4();
    void bj_bonus5();
    void bj_bonus6();
    void bj_bonus7();
    void bj_bonus8();
    void bj_bonus11();
    void bj_bonus12();
    void bjH1();
    void bjH2();
    void bjH3();
    void bjH4();
    void bjH6();
    void bjH7();
    void bjH8();
    void bj_bonusH1();
    void bj_bonusH2();
    void bj_bonusH3();
    void bj_bonusH4();
    void bj_bonusH6();
    void bj_bonusH7();
    void bj_bonusH8();

    void sex_bell();
    void sex_bell_anal();
    void sex_bell_analH();
    void sex_bell_bonus1();
    void sex_bell_bonus();

    void sex_cow_bonus3();
    void sex_cow_bonus2();
    void sex_cow_bonus1();
    void sex_cow_bonus();
    void sex_cow();
    void sex_cow_analH();
    void sex_cow_anal2();
    void sex_cow_anal1();
    void sex_cow_anal();

    void sex_dog_analH();
    void sex_dog_anal();
    void sex_dog_bonus();
    void sex_dog_bonus1();
    void sex_dog_bonus2();
    void sex_dog();


    void sex_cum_common();
    void sex_cumface7();
    void sex_cumface6();
    void sex_cumface5();
    void sex_cumface4();
    void sex_cumface3();
    void sex_cumface2();
    void sex_cumface1();
    void sex_cum11();
    void sex_cum10();
    void sex_cum9();
    void sex_cum81();
    void sex_cum8();
    void sex_cum7();
    void sex_cum6();
    void sex_cum5();
    void sex_cum41();
    void sex_cum4();
    void sex_cum3();
    void sex_cum2();
    void sex_cum1();
    void sex_common1(int i, int j, int h);
    void sex_common2(int i, int j, int h);
    void sex_common3(int i, int j, int h);
    void sex_common4(int i, int j, int h);
    void sex_common5(int i, int j, int h);



    void sex_69();
    void sex_hand_bonus();
    void sex_hand();

    void sex_misionary();
    void sex_misionary_analH();
    void sex_misionary_anal();
    void sex_misionary_bonus2();
    void sex_misionary_bonus1();
    void sex_misionary_bonus();

    void sex_kuni_bonus();
    void sex_kuni();
    void sub();
    void resetCounters();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void setVideo(QString path);
private:
    EventHandler* root;
};

#endif // HANTERSLOVESEX_H
