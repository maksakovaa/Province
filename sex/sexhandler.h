#ifndef SEXHANDLER_H
#define SEXHANDLER_H

#include <QObject>
#include <QVBoxLayout>
#include "../render.h"
#include "selfplay.h"
#include "sex.h"

class SexHandler: public QObject
{
    Q_OBJECT
    friend SelfPlay; friend Sex;
public:
    SexHandler(Render* ptr, QWidget* parent = nullptr, QVBoxLayout* actions = nullptr);
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
    void double_penetration();
private:
    void updParams();
    void setGape(Body holeType, int horny, int dick, int silavag);
    void updVSC(SC param, int val);
    void updVBody(Body param, int val);
    void updVStatus(Status param, int val);
    void updVSexVar(SexVar param,int val);
    void incTime(int min);
    void setVSexVar(SexVar param, int val);
    void setVStatus(Status param, int val);
    void setVBody(Body param, int val);
    void changeLoc(LocId locId, int min);
    void useItem(Items id, int count);
    void chanceOfPreg();
    int getVStatus(Status param);
    int getVSexVar(SexVar param);
    int getVBody(Body param);
    int getItemCount(Items id);
    int getVAddict(Addiction param);
    int getVSC(SC param);
    LocId getCurLoc();
    LocId getPrevLoc();
    QString getBoyName();
    QString getBoy2Name();
    QString getLipTalk();
    QString getLipTalk2();
    QString getLipTalk3();
    QString getAnusTipe();
    QString getAnusTipe2();
    bool condomDefense();
private:
    Render* m_render;
    QWidget* root;
    SelfPlay* m_selfplay;
    Sex* m_sex;
    QVBoxLayout* m_actions;
};

#endif // SEXHANDLER_H
