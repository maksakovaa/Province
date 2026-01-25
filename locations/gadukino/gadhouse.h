#ifndef GADHOUSE_H
#define GADHOUSE_H

#include "../location.h"

class Game;

class Gadhouse: public Location
{
    Q_OBJECT
public:
    Gadhouse(Game* ptr);
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
    QString media(int id);
private:
    Game* root;
};

#endif // GADHOUSE_H
