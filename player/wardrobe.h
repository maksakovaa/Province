#ifndef WARDROBE_H
#define WARDROBE_H

#include <QPixmap>
#include <QString>
#include <QObject>

#include "cloth.h"

class Wardrobe: public QObject
{
    Q_OBJECT
public:
    Wardrobe();
    ~Wardrobe() = default;
    void addCloth(Cloth* thing);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotUpdSize(int size);
private:
    std::unordered_map<Cloth*, int> m_storage;
    int m_size;
};

#endif
