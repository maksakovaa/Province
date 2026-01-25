#ifndef GADBANA_H
#define GADBANA_H

#include "../location.h"

class Game;

class Gadbana: public Location
{
    Q_OBJECT
public:
    Gadbana(Game* ptr);
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
    void cleanMe();
    void undress();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    bool isCanPar();
private:
    Game* root;
};

#endif // GADBANA_H
