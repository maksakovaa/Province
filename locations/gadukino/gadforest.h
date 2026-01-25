#ifndef GADFOREST_H
#define GADFOREST_H

#include "../location.h"

class Game;
class GadforestEvent;

class Gadforest: public Location
{
    friend GadforestEvent;
public:
    Gadforest(Game* ptr);
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
private:
    Game* root;
};

#endif // GADFOREST_H
