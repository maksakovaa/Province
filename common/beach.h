#ifndef BEACH_H
#define BEACH_H

#include <QString>
#include <QObject>
#include "../items/cloth.h"

class LocationHandler;

class Beach: public QObject
{
    Q_OBJECT
public:
    Beach(LocationHandler* ptr);
    void check_people();
    void walk();
    void undress(int arg = 0);
    void wearswimsuit();
    void nude();
    void getDressed(int arg = 0);
    void swim();
    void sunbathe(int isCream = 0);
    void cream();
private slots:
    void actionHandler(QString action);
private:
    void storeClothes();
    void makeActBtn(QString action,QString actName);
    QString str(int id);
    QString act(int id);
    LocationHandler* root;
    Cloth* cloth = nullptr;
    Cloth* panties = nullptr;
    Cloth* stock = nullptr;
};

#endif // BEACH_H
