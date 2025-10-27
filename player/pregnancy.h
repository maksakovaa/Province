#ifndef PREGNANCY_H
#define PREGNANCY_H

#include <QObject>
#include "bagform.h"
#include "player.h"

class Pregnancy: public QObject
{
    Q_OBJECT
public:
    Pregnancy();
    bool isEstrus();
    bool isMesec();
    bool isPregnancy();
    int getPregValue();
    void chanceOfPregnancy();
    bool condomDef();
    bool PregVisibility();
    void setPlayerPtr(Player* ptr);
    void setBagPtr(BagForm* ptr);
public slots:
    void slotMenstruus();
    void slotEstrus();
    void slotIncreaseRiscs(int value);
    void slotPregRecalc();
    void slotRiscsUpdate();
private:
    int getVBody(Body param);
    int getVStatus(Status param);
    int getVSkill(Skills skil);
    void updVBody(Body param, int value);
    void updVStatus(Status param, int value);
    void updVSkill(Skills skil, int value);
    Player* m_player;
    BagForm* m_bag;

    int status_mc_vagina;
    int m_mesecPregOdds;
    int m_withoutPregOdds;
    int m_againstPregOdds;
    int m_pregOdds;
    int m_pregRisc;
    int m_pregWeeks;
    int m_birthCtrlPills;
    int m_barrenness;
    int m_cikl{0};
    int m_pregAlko{0};
    int m_estrus;
    int m_vag_estrus{13};
    int m_Arr_Estrus[15];
};

#endif
