#ifndef LOCATIONFORM_H
#define LOCATIONFORM_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <qstackedwidget.h>
#include "location.h"
#include "../timeServer.h"
#include "../video.h"
#include "cloth.h"
#include "bathroom.h"
#include "shop.h"

namespace Ui {
class LocationForm;
}

class BathRoom; class Shop;

class LocationForm : public QWidget
{
    Q_OBJECT
    friend BathRoom; friend Shop;
signals:
    void sigIsMapAwaylable(bool status);
    void sigUpdParams();
public:
    explicit LocationForm(QWidget *parent = nullptr);
    ~LocationForm();
    void setRoot(QWidget* ptr);
    void setActionsLayout(QVBoxLayout* ptr);
    void init(QString loc = "");
    Location* getCurPtr();
    Location* getPrevPtr();
    void reloadLocation();
    QLabel* getImageLblPtr();
public slots:
    void slotOnChangeLocation(const QString& name, int min);
    void slotChangeLoc(Location* locPtr, int min);
    void sendNotif(QString text);
private:
//methods:
    QString sextToysBlock(int val);
    QString getItemName(Items id);
    void DFSlocations(Location* parent);
    void fillSubLocs();
    void createLocations();
    void incTime(int min);
    void updVBody(Body param, int val);
    void updVStatus(Status param, int val);
    void updVStatistic(SC param, int val);
    void useItem(Items item, int count);
    void setSexVar(SexVar var, int value);
    void setVStatus(Status param, int value);
    void setVBody(Body param, int value);
    void startSelfPlay();
    int getVBody(Body param);
    int getVStatus(Status param);
    int getItmCount(Items item);
    int getSexVar(SexVar var);
    int getVStatistic(SC param);
    int getDay();
    int getMonth();
    void setImage(QString path);
    void setDesc(QString text);
    void addDesc(QString str);
    void setVideoDesc(QString str);
    bool isAutoTampon();
    void redress(Cloth* newCloth);
    Cloth* getCloth(ClothType type);
    void viewObj(QString obj);
    void updSkin(char c, int val);
    TimeServer* gTime();
    void addCloth(Cloth* thing);
    void addItem(Items id, int count = 1);
    bool isDay();
//members:
    Ui::LocationForm *ui;
    QWidget* root;
    Location* m_currentLoc;
    Location* m_prevLoc;
    std::unordered_map<QString,Location*> m_locations;
    QVBoxLayout* m_actLayout;
    Video* videoWidg;
    BathRoom* m_bath;
    Shop* m_shop;
};

#endif // LOCATIONFORM_H
