#ifndef DINMOTHER_H
#define DINMOTHER_H

#include "../event.h"
class Game;

class DinMother: public Event
{
public:
    DinMother(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void check_talktime();
    void talk();
    void clothes();
    void piercing();
    void hair();
    void virgin_check();
    void money_talk();
    void cloth_talk();
    void tampon_talk();
    void cum_talk();
    void worry();
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
    int i = 0;
};

#endif // DINMOTHER_H
