#ifndef MIRROR_H
#define MIRROR_H

#include "GameObj.h"
#include "objviewform.h"

class Mirror: public GameObj
{
    Q_OBJECT
public:
    Mirror(QWidget* ptr);
    ~Mirror();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewMirror();
private slots:
    void slotMirrorActHandler(QString actName);
private:
    void makeMirrorActBtn(QString text);
    void makeBackBtn(QString text);
    ObjViewForm* root;
    QString m_name;
    QString m_desc;
};

#endif