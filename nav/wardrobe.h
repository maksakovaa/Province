#ifndef WARDROBE_H
#define WARDROBE_H

#include "cloth.h"
#include "GameObj.h"
#include "objviewform.h"

enum WardrActs
{
    actWardr0, actWardr1, actWardr2, actWardr3, actWardr4, actWardr5, actWardr6, actWardr7, actWardr8,actWardr9,actWardr10,actWardr11,actWardr12
};

class WardrActionButton: public QPushButton
{
    Q_OBJECT
public:
    WardrActionButton(QString actName, WardrActs act): m_action(act) 
    { this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &WardrActionButton::clicked, this, &WardrActionButton::handleButtonClick); }
signals:
    void sigAction(WardrActs act);
private:
    WardrActs m_action;
private slots:
    void handleButtonClick() { emit sigAction(m_action); }
};

class Wardrobe: public GameObj
{
    Q_OBJECT
    friend void ObjViewForm::slotInitWardrobe();
public:
    Wardrobe(QWidget* ptr);
    ~Wardrobe() = default;
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewWardrobe();
    void addCloth(Cloth* thing, int count);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotUpdSize(int size);
    void reloadActions();
private slots:
    void slotActHandler(WardrActs act);
    void clothFormHandler(Cloth* cloth, QString action);
    void clotTrashHandler(Cloth* cloth, QString action);
    void slotHeader(QString act);
private:
    ClothForm* genForm(ClothMain* cloth);
    ClothFormTrash* genTrashForm(ClothMain* cloth);
    void initNewLayout();
    void initWarDrobe();
    void finalize();
    int countPanties();
    void makeButtons();
    void makeActBtn(WardrActs act);
    QString warStr(int index);
    ObjViewForm* root;
    ClothPanties* m_panties;
    std::unordered_map<Cloth*, int> m_storage;
    std::vector<Cloth*> m_trash;
    std::vector<QHBoxLayout*> m_layouts;
    int m_size;
    WardrActs current;
};

#endif