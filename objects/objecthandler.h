#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H

#include <QWidget>
#include <QVBoxLayout>
#include "../render.h"
#include "../player/player.h"
#include "../items/cloth.h"
#include "../locations/location.h"

class Mirror;
class Bed;
class Wardrobe;
class Books;

class ObjectHandler: public QObject
{
    Q_OBJECT
    friend Mirror; friend Bed; friend Wardrobe; friend Books; friend SaveForm; friend LoadForm;
public:
    ObjectHandler(Game* parent);
    Cloth* wearCloth(Cloth* thing);
    void storeCloth(Cloth* thing, int count = 1);
    void removeCloth(ClothGroup group);
    void sleep();
    QString getBookName(int id);
    void readOnWalk();
    int eroReaded();
    void eroBlock();
    int sisBook();
    int novel_readed();
    void erotic_enable();
    ClothMain* addRandDress(ClothGroup group);
public slots:
    void slotViewObj(QString objName);
    void slotInitWardrobe();
private:
    Game* root;
    Mirror* m_mirror;
    Bed* m_bed;
    Wardrobe* m_wardrobe;
    Books* m_books;
};

#endif // OBJECTHANDLER_H
