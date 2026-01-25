#ifndef SWAMPHOUSE_H
#define SWAMPHOUSE_H

#include "../location.h"

class Game;

class SwampHouse: public Location
{
public:
    SwampHouse(Game* ptr);
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
    void dirtySwampHouse();
    void clothes_read_magazines();
private:
    Game* root;
};

#endif // SWAMPHOUSE_H
