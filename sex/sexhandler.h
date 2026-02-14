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
    void dd_anus(int dick1, int dick2, QString name1, QString name2, int protection = 0);
    void rand_cum(int min = 0);
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
    void dp_cum();
        void dd_vagina(int dick1, int dick2, QString name1, QString name2, int protection = 0);
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
