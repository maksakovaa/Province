#include "wardrobe.h"
#include "cloth.h"

Wardrobe::Wardrobe(): m_size(0) {}

void Wardrobe::addCloth(Cloth* thing)
{
    if(thing->getClothType() == ClothType::Main)
    {
        ClothMain* ptr = (ClothMain*)thing;
        ptr->setSize(m_size);
    }
    m_storage[thing] += 1;
}

Cloth* Wardrobe::wearCloth(Cloth* thing)
{
    m_storage[thing] -= 1;
    return thing;
}

void Wardrobe::slotUpdSize(int size)
{
    m_size = size;
}
