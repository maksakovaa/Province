#ifndef MIROSLAVA_H
#define MIROSLAVA_H

#include "../event.h"
class Game;

class Miroslava: public Event
{
public:
    Miroslava(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void miraclothes();
    void mira_river();
    void miratalk();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    Game* root;
    int age;
};

#endif // MIROSLAVA_H
