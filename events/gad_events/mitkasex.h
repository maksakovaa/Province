#ifndef MITKASEX_H
#define MITKASEX_H

#include "../event.h"
class Game;

class MitkaSex: public Event
{
public:
    MitkaSex(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    //Два парня vs ГГ
    void gadSexOral2();
    void gadSexOralCum2_1();
    void gadSexOralCum2_2();
    void gadSexHandsCum2();
    void gadSexDog2();
    void gadSexDogCum2_1();
    void gadSexDogCum2_2();
    void gadSexCow2();
    void gadSexCowCum2_1();
    void gadSexCowCum2_2();
    void gadSexStan2();
    void gadSexStanCum2_1();
    void gadSexStanCum2_2();
    //Один парень vs ГГ
    void gadSexOral1();
    void gadSexOralCum1();
    void gadSexSideVag1();
    void gadSexSideVagCum1();
    void gadSexMisVag1();
    void gadSexDogVag1();
    void gadSexCowVag1();
    void gadSexCowVagCum1();
    void gadSexDogAnal1();
    void gadSexDogAnalCum1();
    void gadSexCowAnal1();
    void gadSexHandsCum1();
    //Один парень vs ГГ и Мира
    void forestSexOral1_1();
    void forestSexOral1_2();
    void forestSexOral1_3();
    void forestSexOralCum1_1();
    void forestSexSide1_1();
    void forestSexSideCum1_1();
    void forestSexSide1_2();
    void forestSexCow1_1();
    void forestSexCowCum1_1();
    void forestSexCow1_2();
    void forestCowKiss1_1();
    void forestSexCowCum1_2();
    void forestSexCowOral1_1();
    void forestSexDog1_1();
    void forestSexDogCum1_1();
    void forestSexDog1_2();
    void forestSexDogCum1_2();
    void forestSexDog1_3();
    void forestSexDogCum1_3();
    //Два парня vs ГГ и Мира
    void forestSexOral2_1();
    void forestSexDog2_1();
    void forestSexDog2_2();
    void forestSexSide2_1();
    void forestSexOralCum2_1();
    void forestSexRelax2();
    void forestSexSide2_2();
    void forestSexSide2_3();
    void forestSexCow2_1();
    void forestSexOralMira2_1();
    void forestSexOralCumMira2_1();
    void forestSexDogMira2_1();
    void forestSexCowMira2_1();
    //!Три парня vs ГГ и Мира
    void forestSexRelax();
    void forestSexOral3_1();
    void forestSexOral3_2();
    void forestSexOral3_3();
    void forestSexVag3();
    void forestSexAnal3_1();
    void forestSexAnal3_2();
    void forestSexAnal3_3();
    void forestSexCum3_1();
    void forestSexCum3_2();
    void forestSexCum3_3();
    void forestSexRelaxMira();
    void forestSexDPMira3();
    void forestSexCowMira3();
    void forestSexCowMira2();
    void forestSexSideMira2();
    void forestSexMisMira2();
    void forestSexDogMira2();
    void forestSexCowMira1();
    void forestSexDogVMira1();
    void forestSexDogAMira1();
    void forestSexThroatMira1();
    void forestSexOralMira1();
    void forestSexCumMira1();
    void forestSexCumMira2();
    void forestSexCumMira3();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    QString textsexhanter[11];
    QString boy[3];
    int boySilavag[3];
    int boyDick[3];
    void setMitka();
    void setVasyan();
    void setKolyamba();
private:
    Game* root;
    int boyAsex;
    int boyAsexa;
    int boyAhorny;
    int boyBsex;
    int boyBsexa;
    int boyBhorny;
    int boyBcum;
    int boyCsex;
    int boyCsexa;
    int boyChorny;
    int mitboysex;
    int mitboysexrand;
    int hantsexa;
    int mirarand;
};

#endif // MITKASEX_H
