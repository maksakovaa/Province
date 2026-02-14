#ifndef SEX_H
#define SEX_H

#include <QWidget>
#include <QLabel>
#include "../player/enums.h"

class Game;

class Sex
{
public:
    Sex(Game* parent);
    void rand_cum(int min = 0);
    void sexStart();
    void analStart(ToolType type = tDick);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
    void cum(QString target);
    void sex_cum();
    void anal_cum();
    void blow_job();
    void fnswallow();
    void dp_start();
    void double_penetration();
    void dp_cum();
    void dd_anus(int dick1, int dick2, QString name1, QString name2, int protection = 0);
    void dd_vagina(int dick1, int dick2, QString name1, QString name2, int protection = 0);
private:
    Game* root;
    int m_protect;
    int m_cc_sex_usecondom;
};

#endif
