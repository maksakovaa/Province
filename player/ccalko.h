#ifndef CCALKO_H
#define CCALKO_H

#include "enums.h"
#include <QObject>

class CC_Alko: public QObject
{
    Q_OBJECT
public:
    CC_Alko(QWidget* ptr);
    void anti_hangover();
    void alkoAbstain();
    void fnAlko(int val);
    int alkoBlock();
signals:
    void sigIncreaseRiscs(int value);
public slots:
    void slotDataInitAlko();
    void slotHangOver();
    void slotAlkoholism();
private:
    int getVAlco(Addiction param);
    void setVAlco(Addiction param, int value);
    void updVAlco(Addiction param, int value);
    int getVStatus(Status param);
    void updVStatus(Status param, int value);
    void setVStatus(Status param, int value);
    void incTime(int min);
    void updSkin(char c, int value);
    QWidget* root;
};

#endif
