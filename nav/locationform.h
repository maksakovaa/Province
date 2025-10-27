#ifndef LOCATIONFORM_H
#define LOCATIONFORM_H

#include <QWidget>
#include <QLabel>
#include <qstackedwidget.h>
#include "location.h"
#include "../timeServer.h"
#include "../video.h"
#include "../weather.h"

namespace Ui {
class LocationForm;
}

class LocationForm : public QWidget
{
    Q_OBJECT
signals:
    void sigIsMapAwaylable(bool status);
    void sigUpdParams();
public:
    explicit LocationForm(QWidget *parent = nullptr);
    ~LocationForm();
    void setPlayerPtr(Player* ptr);
    void setActionsLayout(QVBoxLayout* ptr);
    void setTimePtr(TimeServer* ptr);
    void setPagePtr(QStackedWidget* ptr);
    void setWeatherPtr(Weather* ptr);
    void init(QString loc = "");
    Location* getCurPtr();
    void reloadLocation();
    QLabel* getImageLblPtr();
public slots:
    void slotOnChangeLocation(const QString name, int min);
    void slotChangeLoc(Location* locPtr, int min);
private slots:
    void slotBathActionHandler(Location* loc, QString action);
private:
    void fillSubLocs();
    void bathActions(std::vector<struct Action*> acts);
    QString bathStr(int value);
    QString bathActStr(int value);
    Ui::LocationForm *ui;
    Location* m_currentLoc;
    Player* m_player;
    QVBoxLayout* m_actLayout;
    TimeServer* m_time;
    QStackedWidget* m_page;
    BagForm* m_bag;
    Video* videoWidg;
    Weather* m_weather;
};

#endif // LOCATIONFORM_H
