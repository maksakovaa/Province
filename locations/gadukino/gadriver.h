#ifndef GADRIVER_H
#define GADRIVER_H

#include "../location.h"

class Game;

class Gadriver: public Location
{
public:
    Gadriver(Game* ptr);
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
    Game* root;
};

#endif // GADRIVER_H
