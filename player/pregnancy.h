#ifndef PREGNANCY_H
#define PREGNANCY_H

#include <QObject>
#include "enums.h"

class Game;

class Pregnancy: public QObject
{
    Q_OBJECT
public:
    Pregnancy(Game* ptr);
    bool isEstrus();
    bool isMesec();
    bool isPregnancy();
    void chanceOfPregnancy();
    bool condomDef();
    bool PregVisibility();
public slots:
    void slotMenstruus();
    void slotEstrus();
    void slotIncreaseRiscs(int value);
    void slotPregRecalc();
    void slotRiscsUpdate();
private:
    Game* root;
    void initPregData();
    int m_vag_estrus{13};
    int m_Arr_Estrus[15];
};

#endif
