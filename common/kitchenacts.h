#ifndef KITCHENACTS_H
#define KITCHENACTS_H

#include <QString>
#include <QObject>

class LocationHandler;

class KitchenActs: public QObject
{
    Q_OBJECT
public:
    KitchenActs(LocationHandler* ptr);
    void drink(QString napitokType);
    void drink_all();
    void eat(QString foodtype = "", QString image = "", QString text = "");
    void eat_full();
    void eat_diet();
    void lunch();
    void vitamin();
    void pills();
    void fatdel();
    void cookie();
    void all(int arg);
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    int vitaminday{0};
    int lekarday{0};
    LocationHandler* root;
};

#endif // KITCHENACTS_H
