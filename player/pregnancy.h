#ifndef PREGNANCY_H
#define PREGNANCY_H

#include <QObject>
#include "enums.h"

class Pregnancy: public QObject
{
    Q_OBJECT
public:
    Pregnancy(QWidget* ptr);
    bool isEstrus();
    bool isMesec();
    bool isPregnancy();
    int getPregValue();
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
    QWidget* root;
    int getVBody(Body param);
    int getVStatus(Status param);
    int getVSkill(Skills skil);
    void updVBody(Body param, int value);
    void updVStatus(Status param, int value);
    void updVSkill(Skills skil, int value);
    void setVStatus(Status param,int val);
    void initPregData();
    int& vPreg(PregVar param);
    int getQuantityof(Items id);
    void useItem(Items id,int count);

    int m_vag_estrus{13};
    int m_Arr_Estrus[15];
};

#endif
