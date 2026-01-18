#ifndef HANTERS_H
#define HANTERS_H

#include "../event.h"
class EventHandler;

class Hanters: public Event
{
public:
    Hanters(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void groupfaint();
    void groupORALend1();
    void groupORALs();
    void groupORALs1();
    void groupORALs1end();
    void groupORALa1end();
    void groupORALi();
    void groupORALi1();
    void groupORALi1end();
    void groupORALai();
    void groupORALai1();
    void groupORALas();
    void groupORALsi();
    void groupORALsi1();
    void groupORALasi();

    void groupOis();
    void groupOia();
    void groupOsa();
    void groupOsend();
    void groupOaend();
    void groupOiend();

    void groupAsOa();
    void groupAsO();
    void groupAOa();
    void groupAa();
    void groupAaEnd1();
    void groupAaEnd2();
    void groupAs();
    void groupAsEnd1();
    void groupAsEnd2();
    void groupAi();
    void groupAiEnd1();
    void groupAiEnd2();

    void groupVa();
    void groupVa1();
    void groupVa2();
    void groupVa2end();
    void groupVas();
    void groupVas1();
    void groupVi();
    void groupVi1();
    void groupVi2();
    void groupVi3();
    void groupVi3end();
    void groupVia();
    void groupVia1();
    void groupVis();
    void groupVis1();
    void groupVias();
    void groupVs();
    void groupVs1();
    void groupVs2();
    void groupVs2end();

    void groupVaOsHi();
    void groupVOsHi();
    void groupVaOHi();
    void groupVsOaHi();
    void groupVsOHi();
    void groupVsOi();
    void groupVOi();
    void groupVsO();
    void groupVOaHi();
    void groupViOa();
    void groupViO();
    void groupVaOs();
    void groupVOs();
    void groupVaO();

    void groupDPasi();
    void groupDPsi();
    void groupDPas();
    void groupDPai();
    void groupDPis();
    void groupDPia();

    void slutSTART();
    void slutEND();
    void slutORAL();
    void slutCOW();
    void slutHANDS();
    void slutTREE();
    void slutTREELEG();
    void slutLEG1();
    void slutLEG2();

    void hanters_talk();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void actions1();
    void actions2();
    void actions3();
    void actions4();
    void actions5();
    void actions6();
    void actions7();
    inline bool sexHanters();
    inline bool sexGopGuys();
    inline void resetCounters();
    inline void setAndrei();
    inline void setAndrei2();
    inline void setSergei();
    inline void setSergei2();
    inline void setIgor();
    inline void setIgor2();
    inline void setMitka();
    inline void setMitka2();
    inline void setKolyamba();
    inline void setKolyamba2();
    inline void setVasyan();
    inline void setVasyan2();
    inline void checkBoyAsex();
    inline void checkBoyBsex();
    inline void checkBoyCsex();
    inline void checkBoyAsexAnal();
    inline void checkBoyBsexAnal();
    inline void checkBoyCsexAnal();
private:
    EventHandler* root;
    int hantsexa;
    int hantsexb;

    int boyAsex;
    int boyAsexA;
    int boyBsex;
    int boyBsexA;
    int boyCsex;
    int boyCsexA;
};

#endif // HANTERS_H
