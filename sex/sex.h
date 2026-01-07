#ifndef SEX_H
#define SEX_H

#include <QWidget>
#include <QLabel>
#include "enums.h"

class SexHandler;

class Sex
{
public:
    Sex(SexHandler* parent);
    void sexStart();
    void analStart(ToolType type = tDick);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
    void cum(QString target);
    void sex_cum();
    void anal_cum();
    void blow_job();
    void fnswallow();
    void double_penetration();
private:
    SexHandler* root;
    int m_protect;
    int m_cc_sex_usecondom;
};

#endif
