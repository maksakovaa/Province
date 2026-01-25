#ifndef TABWIDGETPLAYER_H
#define TABWIDGETPLAYER_H
#include "player.h"
#include <QTabWidget>

namespace Ui {
class TabWidgetPlayer;
}

class LocationHandler;

class TabWidgetPlayer : public QTabWidget
{
    Q_OBJECT

signals:
    void sigUpdateStatus();
public:
    explicit TabWidgetPlayer(QWidget* parent = nullptr);
    ~TabWidgetPlayer();
    void setPtr(Game* ptr);
    void reload();
private slots:
    void on_label_pers_desc_linkActivated(const QString &link);
    void slotSkillUpdate(const QString &link);
    void slotSchoolUpdate(const QString& link);
private:
    Ui::TabWidgetPlayer *ui;
    Game* root;
    int currView{-1};
    //methods
    void connections();
    void setBarStyle();
    void loadStrings();
    void fillBodyDesc();
    void fillCharacteristics();
    void cheatSkillCheck();
};

#endif // TABWIDGETPLAYER_H
