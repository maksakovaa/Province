#ifndef SWAMPYARD_H
#define SWAMPYARD_H

#include "../location.h"

class Game;

class SwampYard: public Location
{
public:
    SwampYard(Game* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    int tmp;
    QString boy;
private:
    Game* root;
};

#endif // SWAMPYARD_H
