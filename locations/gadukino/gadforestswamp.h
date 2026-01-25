#ifndef GADFORESTSWAMP_H
#define GADFORESTSWAMP_H


#include "../location.h"

class Game;

class GadForestSwamp: public Location
{
public:
    GadForestSwamp(Game* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString act, QString actName);
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void swampClothes();
private:
    Game* root;
};

#endif // GADFORESTSWAMP_H
