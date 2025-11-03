#ifndef CCALKO_H
#define CCALKO_H

#include "player.h"
#include <QObject>

class CC_Alko: public QObject
{
    Q_OBJECT
public:
    CC_Alko() = default;
    void setPlayerPtr(Player* ptr);
    void anti_hangover();
    void alkoAbstain();
signals:
    void sigIncreaseRiscs(int value);
public slots:
    void slotDataInitAlko();
    void slotHangOver();
    void slotCheckAlkoBlock(int& value);
    void slotAlkoholism();
private:
    int getVAlco(Addiction param);
    void setVAlco(Addiction param, int value);
    void updVAlco(Addiction param, int value);
    int getVStatus(Status param);
    void updVStatus(Status param, int value);
    void setVStatus(Status param, int value);
    Player* m_player;
    // int m_max_hangoverDay{0};
    // int m_alkoholism{0};
    // int m_hangoverDay{0};
    // int m_alkoAbstainDay{0};
    // int m_alkoAbstainCount{0};
    // int m_hangVneshAlko{0};
    // int m_lenghangoverday{0};
};

#endif
