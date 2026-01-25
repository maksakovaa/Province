#ifndef MITKA_H
#define MITKA_H

#include "../event.h"
class Game;

class Mitka: public Event
{
    Q_OBJECT
public:
    Mitka(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    Game* root;
    int tmp;
};

#endif // MITKA_H
