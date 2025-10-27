#ifndef MENUDIAL_H
#define MENUDIAL_H

#include <QDialog>
#include "player/enums.h"
#include "settingsform.h"
#include "video.h"

namespace Ui {
class MenuDial;
}

class MenuDial : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDial(QWidget *parent = nullptr);
    ~MenuDial();
    CharacterType getCharType();
    SettingsForm* getSettingsPtr();
    QString getStartLoc();
    int getStartYear();
    int getStartMonth();
    int getStartDay();
private slots:
    void on_pbExitGame_clicked();
    void on_pbLoadGame_clicked();
    void on_pbNewGame_clicked();
    void on_label_back_btn_linkActivated(const QString &link);
    void on_label_next_btn_linkActivated(const QString &link);
    void on_labelPersons_linkActivated(const QString &link);
    void on_pbSettings_clicked();
    void slotStart(const QString& link);
private:
    void fillLegend();
    QString getStr(int id);
    Ui::MenuDial *ui;
    Video* videoWidg;
    CharacterType playerType;
    int year;
    int month;
    int day;
    QString m_loc;
};
#endif // MENUDIAL_H
