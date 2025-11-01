#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>
#include <QGraphicsScene>
namespace Ui {
class MapForm;
}

struct loc {
    QString name;
    int x;
    int y;
};

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr);
    ~MapForm();
    QGraphicsScene* genMap(const QString& loc_name, const QString& current_loc);
    void setMap(QGraphicsScene* Scene);
public slots:
    void onMarkerClicked(const QString& name);
signals:
    void closeMapWindow();
    void ChangeLocation(const QString& name, int min);
private:
    Ui::MapForm *ui;
    QString m_current;
    std::vector<loc> pavlovo_markers;
    std::vector<loc> player_markers;
    void init();
    int calcDistance(const QString& from, const QString& to);
    int calcTimeToGo(const QString& from, const QString& to);
};

#endif // MAPFORM_H
