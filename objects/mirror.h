#ifndef MIRROR_H
#define MIRROR_H

#include "GameObj.h"
#include "objecthandler.h"
#include "objenums.h"

class Mirror: public GameObj
{
    Q_OBJECT
public:
    Mirror(Game* ptr);
    ~Mirror();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewMirror();
public slots:
    void reloadActions();
private slots:
    void slotMirrorActHandler(MirrorActs act);
private:
    void makeButtons();
    void makeMirrorActBtn(MirrorActs act);
    QString actStr(MirrorActs type);
    QString str(MirrorActs type);
    Game* root;
    QString m_name;
    QString m_desc;
    MirrorActs current;
};

#endif
