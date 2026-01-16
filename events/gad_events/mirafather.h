#ifndef MIRAFATHER_H
#define MIRAFATHER_H

#include "../event.h"
class EventHandler;

class MiraFather: public Event
{
public:
    MiraFather(EventHandler* ptr);
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
    QString boy {"Афанасий"};
    int dickSize = 18;
    int sexSkill = 0;
    int harakBoy = 1;
};

#endif // MIRAFATHER_H
