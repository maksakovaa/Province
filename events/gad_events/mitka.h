#ifndef MITKA_H
#define MITKA_H

#include "../event.h"
#include <QObject>

class EventHandler;

class Mitka: public Event
{
    Q_OBJECT
public:
    Mitka(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int tmp;
};

#endif // MITKA_H
