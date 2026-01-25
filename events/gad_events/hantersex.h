#ifndef HANTERSEX_H
#define HANTERSEX_H

#include "../event.h"
class Game;

class HanterSex: public Event
{
public:
    HanterSex(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void doubleloveOral1();
    void doubleloveOralCum1();
    void doubleloveOral12();
    void doubleloveOralCum12();
    void doubleloveOralCum12_1();
    void doubleloveOralCum12_2();
    void doubleloveOral2();
    void doubleloveOralCum2();
    void doubleloveDog112();
    void doubleloveDogCum112_1();
    void doubleloveDogCum112_2();
    void doubleloveDog212();
    void doubleloveDogCum212_1();
    void doubleloveDogCum212_2();
    void doubleloveSide12();
    void doubleloveSideCum12_1();
    void doubleloveSideCum12_2();
    void doubleloveSide2();
    void doubleloveSideCum2();
    void doubleloveCow1();
    void doubleloveCowCum1();
    void doubleloveCow112();
    void doubleloveCowCum112_1();
    void doubleloveCowCum112_2();
    void doubleloveCow212();
    void doubleloveCowCum212_1();
    void doubleloveCowCum212_2();

    void sluthomeSTART();
    void sluthomeORAL1();
    void sluthomeORAL2();
    void sluthomeORAL3();
    void sluthomeORAL4();
    void sluthomeOralCum1();
    void sluthomeOralCum2();
    void sluthomeOralCum3();
    void sluthomeOralCum4();
    void sluthomeTanga();
    void sluthomeAnalDog1();
    void sluthomeAnalDog2();
    void sluthomeAnalDogCum1();
    void sluthomeAnalDogCum2();
    void sluthomeAnalCow1();
    void sluthomeAnalCow2();
    void sluthomeAnalCowCum1();
    void sluthomeAnalCowCum2();
    void sluthomeAnalSide1();
    void sluthomeAnalSide2();
    void sluthomeAnalSideCum1();
    void sluthomeAnalSideCum2();

    void hantergrOi();
    void hantersgrOasi();
    void hantersgrVaOsi();
    void hantersgrVOsi();
    void hantersgrVaO();
    void hantersgrVaOi();
    void hantersgrVsOai();
    void hantersgrVOai();
    void hantersgrVsOi();
    void hantersgrVsO();
    void hantersgrViOas();
    void hantersgrViO();
    void hantersgrVsOia();
    void hantersgrVsOi1();
    void hantersgrVaOis();
    void hantersgrVaOs();
    void hantersgrVO();
    void hantersgrV2aOsi();
    void hantersgrV2aOs();
    void hantersgrDPVaAiOs();
    void hantersgrDPVaAOs();
    void hantersgrAiOsa();
    void hantersgrAiO();
    void hantersgrO3();
    void hantersgrEND();
    void hantersgrAOsa();
    void hantersgr2VaOi();
    void hantersgr2VOi();
    void hantersgr2VO();
    void hantersgr2ViOa();
    void hantersgr2ViO();
    void hantersgr2VsO();
    void hantersgr2VaOs();
    void hantersgr2VaO();
    void hantersgr2AiOs();
    void hantersgr2AOs();
    void hantersgr2AiO();
    void hantersgr2AOi();
    void hantersgr2AsO();
    void hantersgr2DPVaAs();
    void hantersgr2DPVaA();
    void hantersgrO2();
    void hantersgr1Va();
    void hantersgr1Ai();
    void hantersgr1Aa();
    void hantersgr1As();
    void hantersgrO1();
    void hantersexfaint();

    QString str(int id);
    QString act(int id);
    QString media(int id);
    void actions1();
    void actions2();
    void actions3();
    void actions4();
    void actions5();
    inline void resetCounters();
    inline void checkHantSex();
    inline void checkBoyAsex();
    inline void checkBoyAsexA();
    inline void checkBoyBsex();
    inline void checkBoyBsexA();
    inline void checkBoyCsex();
    inline void checkBoyCsexA();
    inline void setAIMV();
    inline void setSIKV();
    inline void setIgor();
    inline void setIgor2();
    inline void setSergei();
    inline void setSergei2();
    inline void setAndrei();
    inline void setMitka();
    inline void setVasyan();
    inline void setKolyamba();
private:
    Game* root;
    int hantsexa;
    int hantsexb;
    int boyAsex;
    int boyBsex;
    int boyCsex;
    int boyAsexA;
    int boyBsexA;
    int boyCsexA;
};

#endif // HANTERSEX_H
