#ifndef TABWIDGETPLAYER_H
#define TABWIDGETPLAYER_H
#include "player.h"
#include <QTabWidget>

namespace Ui {
class TabWidgetPlayer;
}

class TabWidgetPlayer : public QTabWidget
{
    Q_OBJECT

signals:
    void sigUpdateStatus();
public:
    explicit TabWidgetPlayer(QWidget *parent = nullptr);
    ~TabWidgetPlayer();
    void setPtr(Player* ptr);
    void reload();
private slots:
    void on_label_pers_desc_linkActivated(const QString &link);
    void slotSkillUpdate(const QString &link);

private:
    Ui::TabWidgetPlayer *ui;
    Player* m_player;
    int currView{-1};
    //methods
    void connections();
    void setBarStyle();
    void updBodyVal(Body param, int val);
    void loadStrings();
    void fillBodyDesc();
    void fillCharacteristics();
};

#endif // TABWIDGETPLAYER_H
