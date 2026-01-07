#ifndef MAPFORM_H
#define MAPFORM_H

#include "../nav/loc_enums.h"
#include <QWidget>
#include <QGraphicsScene>
namespace Ui {
class MapForm;
}

struct loc {
    LocId id;
    int x;
    int y;
    int hmin;
    int hmax;
};

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr);
    ~MapForm();
    QGraphicsScene* genMap(LocId loc_name, LocId current_loc, int hour);
    void setMap(QGraphicsScene* Scene);
public slots:
    void onMarkerClicked(const QString& name);
signals:
    void closeMapWindow();
    void ChangeLocation(const QString& name, int min);
private:
    Ui::MapForm *ui;
    LocId m_current;
    std::vector<loc> pavlovo_markers;
    std::vector<loc> player_markers;
    std::vector<loc> timeMarkers;
    void init();
    int calcDistance(LocId from, LocId to);
    int calcTimeToGo(LocId from, LocId to);
};

#endif // MAPFORM_H
