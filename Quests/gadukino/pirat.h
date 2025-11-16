#ifndef PIRAT_H
#define PIRAT_H

#include <QString>
#include "../quest.h"
enum Stage
{
    stage0,
};

class PiratQuest: public Quest
{
public:
    PiratQuest(QuestHandler* ptr);
    void start() override;
public slots:
    void slotActHandler(QString act) override;
private:
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

    void initDefault();
    void initStrings();
    void getStrings(QString path, QString arr[]);
    QString& getStr(int id);
    QString& getEvStr(int id);
    QString& getSexStr(int id);
    int pir_pirat;
    int pirat;
    int know_no_pirat;
    int pir_pirat_search;
    int pir_piratfriend;
    int pir_piratsuka;
    int pir_pirat_sex;
    int pir_piratknow;
    int pir_piratHorny;
    int pir_DogHJ{0};
    int pir_DogBJ{0};
    int pir_DogVag{0};
    int pir_DogAnal{0};
    int pir_pir_zoo{0};
    int pir_zoo{0};
    int pir_stroking{0};
    int piratlick{0};
    int piratlickass{0};
    int grandpa_ingadsarai{0}; // temp
    int grandma_ingadsarai{0}; // temp
    int grandparents_ingadsarai{0}; //temp
    QString str[16];
    QString evStrings[27];
    QString sexStrings[95];
};

#endif
