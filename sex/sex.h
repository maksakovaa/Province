#ifndef SEX_H
#define SEX_H

#include "sexviewform.h"

class SexViewForm;

enum ToolType
{
    tDick,
    tDildo,
    tBottle,
    tGirlDildo,
    tGirlBottle,
    tStrapon
};

class Sex
{
public:
    Sex(QWidget* parent);
    void sexStart(int protect);
    void analStart(ToolType type = tDick, int protect = 0);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
private:
    SexViewForm* root;
    int m_protect;
    int m_cc_sex_usecondom;
//methods:
    int getSexVar(SexVar param);
    int getVStatus(Status param);
    int getVBody(Body param);
    int getItemCount(Items item);
    int getVAddict(Addiction param);
    int getBSC(SC param);
    void setSexVar(SexVar param, int value);
    void updSexVar(SexVar param, int value);
    void setVStatus(Status param, int value);
    void updVStatus(Status param, int value);
    void updVSC(SC param, int val);
    void useItem(Items item, int count);
    void setVBody(Body param, int val);
    void checkTextOutput(int addTxtSex, QString text);
};

#endif