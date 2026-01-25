#ifndef SEXHANDLER_H
#define SEXHANDLER_H

#include <QObject>
#include <QVBoxLayout>
#include "selfplay.h"
#include "sex.h"

class Game;

class SexHandler: public QObject
{
    Q_OBJECT
    friend SelfPlay; friend Sex;
public:
    SexHandler(Game* ptr);
    void selfPlayStart();
    void cum(QString target);
    void sexStart();
    void analStart(ToolType type = tDick);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
    void sex_cum();
    void blow_job();
    void anal_cum();
    void fnswallow();
    void dp_start();
    void double_penetration();
    QString sextToysBlock(int arg);
private:
    void updParams();
    void setGape(Body holeType, int horny, int dick, int silavag);
private:
    // Render* m_render;
    Game* root;
    SelfPlay* m_selfplay;
    Sex* m_sex;
    // QVBoxLayout* m_actions;
};

#endif // SEXHANDLER_H
