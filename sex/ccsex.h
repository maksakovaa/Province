#ifndef CCSEX_H
#define CCSEX_H

#include <QObject>
#include "../player/enums.h"

class Game;

class CCSex: public QObject
{
    Q_OBJECT
public:
    CCSex(Game* ptr);
    void ability(Body holeType, int value = 0);
    QString sextToysBlock(int arg);
    int getVaginaDampness();
    int calc_rubb(QString holeType);
    void antiRubbing();
    int getVagDamp();
public slots:
    void slotCalcRubbing();
    void slotVagGelTouch();
    void slotDecRubbing(Body holeType);
    void slotSexCorrector();
    void slotSetGape(Body holeType, int horny, int dick, int silavag);
private:
    Game* root;
    int m_global_level_sex{0};
    int m_vag_corrector{0};
    int m_anal_corrector{0};
};

#endif // CCSEX_H
