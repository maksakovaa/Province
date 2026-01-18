#ifndef MITKA_H
#define MITKA_H

#include "../event.h"
class EventHandler;

class Mitka: public Event
{
    Q_OBJECT
public:
    Mitka(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int tmp;
};

#endif // MITKA_H
