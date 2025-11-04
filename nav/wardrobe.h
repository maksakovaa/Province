#ifndef WARDROBE_H
#define WARDROBE_H

#include "cloth.h"
#include "GameObj.h"
#include "objviewform.h"

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
    void trashBox();
    void addCloth(Cloth* thing, int count);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotUpdSize(int size);
private slots:
    void wardrobeHandler(QString act);
    void clothFormHandler(Cloth* cloth, QString action);
    void clotTrashHandler(Cloth* cloth, QString action);
private:
    ClothForm* genForm(ClothMain* cloth);
    ClothFormTrash* genTrashForm(ClothMain* cloth);
    void initNewLayout();
    void initWarDrobe();
    void finalize();
    int countPanties();
    void makeActBtn(QString txt);
    QString warStr(int index);
    ObjViewForm* root;
    ClothPanties* m_panties;
    std::unordered_map<Cloth*, int> m_storage;
    std::vector<Cloth*> m_trash;
    std::vector<QHBoxLayout*> m_layouts;
    int m_size;
};

#endif