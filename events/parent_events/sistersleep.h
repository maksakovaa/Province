#ifndef SISTERSLEEP_H
#define SISTERSLEEP_H

#include "../event.h"
class Game;

class SisterSleep: public Event
{
public:
    SisterSleep(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void sisboyQW_prycaress();
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
};

#endif // SISTERSLEEP_H
