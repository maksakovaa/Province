#ifndef WARDROBE_H
#define WARDROBE_H

#include "../items/cloth.h"
#include "GameObj.h"
#include <QHBoxLayout>
#include "objecthandler.h"
#include "objenums.h"

class SaveForm; class LoadForm;

class Wardrobe: public GameObj
{
    Q_OBJECT
    friend void ObjectHandler::slotInitWardrobe();
    friend SaveForm; friend LoadForm;
public:
    Wardrobe(Game* ptr);
    ~Wardrobe() = default;
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewWardrobe();
    void addCloth(Cloth* thing, int count);
    Cloth* wearCloth(Cloth* thing);
    void removeCloth(ClothGroup group);
    ClothMain* addRandDress(ClothGroup group);
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
    Game* root;
    ClothPanties* m_panties;
    std::unordered_map<Cloth*, int> m_storage;
    std::vector<Cloth*> m_trash;
    std::vector<QHBoxLayout*> m_layouts;
    int m_size;
    WardrActs current;
    QLabel* header;
};

#endif
