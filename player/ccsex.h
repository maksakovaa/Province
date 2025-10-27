#ifndef CCSEX_H
#define CCSEX_H

#include <QObject>
#include "player.h"
#include "pregnancy.h"

class CCSex: public QObject
{
    Q_OBJECT
public:
    CCSex();
    void ability(Body holeType, int value = 0);
    QString sextToysBlock(int arg);
    void setPlayerPtr(Player* ptr);
    void setPregPtr(Pregnancy* ptr);
    int getVaginaDampness();
    int calc_rubb(QString holeType);
    void antiRubbing();
public slots:
    void slotCalcRubbing();
    void slotVagGelTouch();
    void slotDecRubbing(Body holeType);
    void slotSexCorrector();
    void slotGetVagDamp(int& value);
    void slotSetGape(Body holeType, int horny, int dick, int silavag);
private:
    int getVStatus(Status param);
    int getVBody(Body param);
    int getVSexVar(SexVar param);
    void updVStatus(Status param, int value);
    void updVBody(Body param, int value);
    void updVSexVar(SexVar param, int value);
    void setVSexVar(SexVar param, int value);
    void setVStatus(Status param, int value);
    Player* m_player;
    Pregnancy* m_reproductSys;
    int m_global_level_sex{0};
    int m_vag_corrector{0};
    int m_anal_corrector{0};
};

#endif // CCSEX_H
