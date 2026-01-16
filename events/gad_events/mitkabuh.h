#ifndef MITKABUH_H
#define MITKABUH_H

class EventHandler;
#include "../event.h"

class MitkaBuh : public Event
{
public:
    MitkaBuh(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void setMitka();
    void setVasyan();
    void setKolyamba();
    inline void checkMitkaSex();
    inline void sexDepOnMesec();
    void mitkaBlowJob1();
    void mitkaBlowJob2();
    void mitkaBlowJob3();
    void mitkaBlowJob4();
    void mitkaBlowJob5();
    void mitkaBlowJob6();
    void doubleBlowJob1();
    void mitkaVag1();
    void mitkaVag2();
    void mitkaAnal1();
    void mitkaDepOnMesec1();
    void mitkaDepOnMesec2();
    void mitkaDepOnMesec3();
    void mitkaDepOnMesec4();
    void mitkaCum1();
    void mitkaCum2();
    void mitkaCum3();
    void mitkaCum4();
    void mitkaCum5();
    void mitkaCum6();
    void kolyaBlowJob1();
    void kolyaBlowJob2();
    void kolyaAnal1();
    void kolyaAnal2();
    void kolyaAnal3();
    void kolyaAnal4();
    void vasyaBlowJob1();
    void vasyaBlowJob2();
    void vasyaBlowJob3();
    void vasyaVag1();
    void vasyaVag2();
private:
    EventHandler* root;
    int order{0};
    int mirapiss;
};

#endif // MITKABUH_H
