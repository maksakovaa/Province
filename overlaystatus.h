#ifndef OVERLAYSTATUS_H
#define OVERLAYSTATUS_H

#include <QVBoxLayout>
#include <QObject>
#include <QLabel>
#include "player/enums.h"

enum statusNotif {
    ind_makeup,
    ind_dress,
    ind_nude,
    ind_dampness,
    ind_rub,
    ind_pain,
    ind_wday,
    ind_sweat,
    ind_PillsAndCondoms,
    ind_mouthsmell,
    ind_cum,
    ind_sperma,
    ind_depilation,
    ind_toy,
    ind_pin,
    ind_ass,
    ind_remedy,
    ind_books,
    ind_drunk,
    ind_frost,
    ind_addict,
    ind_basket_full,
    ind_debt,
    ind_work,
    ind_info,
    ind_vagina_estrus,
    ind_vagina_issues,
    ind_rose,
    ind_hangover,
    ind_closed_door,
    ind_tryst_house,
    ind_christmas,
    ind_no_alcohol,
    ind_gel_rubbing,
    ind_pregnancy,
    ind_bell
};


class OverlayStatus: public QObject
{
    Q_OBJECT
public:
    OverlayStatus(QWidget* ptr);
    void setParentWidget(QWidget* ptr);
    void genOverlay();
private:
    void grabStatusVector();
    void grabInd_dress();
    void grabInd_dampness();
    void grabInd_makeup();
    void grabInd_Pain();
    void grabInd_Rub();
    void grabInd_Pin();
    void grabIndAss();
    void grabInd_depilation();
    void grabInd_Sweat();
    void grabInd_Wday();
    void grabInd_pregnancy();
    void grabInd_MouthSmell();
    void grabInd_Cum();
    void grabInd_Toy();
    void grabInd_Remedy();
    void grabInd_Books();
    void grabInd_Drunk();
    void grabInd_Frost();
    void grabInd_Addict();
    void grabInd_Basket_Full();
    void grabInd_Debt();
    //ind_work
    //ind_info
    void grabInd_Vagina_Estrus();
    void grabInd_Vagina_Issues();
    //ind_rose
    void grabInd_PillsAndCondoms();
    void granInd_hangover();
    void grabInd_Christmas();

    int getVStatus(Status param);
    int getVSick(Sickness param);
    int getVAddict(Addiction param);
    int getVSex(SexVar param);
    int getVBody(Body param);
    QLabel* genStatusWidget(QString imgLink, QString desc);
    std::unordered_map<statusNotif, QString> m_statuses;
    std::unordered_map<statusNotif, QString> m_statusesImg;
    QVBoxLayout* m_layout;
    QWidget* m_parent;
    QWidget* root;
    QString m_styleSheet;
};

#endif // OVERLAYSTATUS_H
