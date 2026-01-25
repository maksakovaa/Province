#ifndef BEDRPAR2_H
#define BEDRPAR2_H

#include "../location.h"
#include "../loc_enums.h"

class BedrPar2: public Location
{
public:
    BedrPar2(Game* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString act, QString actName);
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void main();
    void kamasutra();
    void momtoy_play();
    void xgb_album();
    void view_album();
    void view_album_end();
    void read_book();
    void mom_selfplay();
    void parents_wardrobe();
    void wardrobe_search();
private:
    int i,maxval;
    QString string;
    Game* root;
};

#endif // BEDRPAR2_H
