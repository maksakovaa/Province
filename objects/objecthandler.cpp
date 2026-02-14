#include "objecthandler.h"
#include "bed.h"
#include "mirror.h"
#include "wardrobe.h"
#include "books.h"
#include "../menu/mainwindow.h"

ObjectHandler::ObjectHandler(Game* parent):
    root(parent)
{
    m_bed = new Bed(root);
    m_mirror = new Mirror(root);
    m_wardrobe = new Wardrobe(root);
    m_books = new Books(root);
}

Cloth *ObjectHandler::wearCloth(Cloth *thing)
{
    return m_wardrobe->wearCloth(thing);
}

void ObjectHandler::storeCloth(Cloth *thing, int count)
{
    m_wardrobe->addCloth(thing, count);
}

void ObjectHandler::removeCloth(ClothGroup group)
{
    m_wardrobe->removeCloth(group);
}

void ObjectHandler::sleep()
{
    m_bed->sleepInBed();
}

QString ObjectHandler::getBookName(int id)
{
    return m_books->getBookName(id);
}

void ObjectHandler::readOnWalk()
{
    m_books->readOnWalk();
}

int ObjectHandler::eroReaded()
{
    return m_books->ero_readed();
}

void ObjectHandler::eroBlock()
{
    m_books->erotic_block();
}

int ObjectHandler::sisBook()
{
    return m_books->sisBook();
}

int ObjectHandler::novel_readed()
{
    return m_books->novel_readed();
}

void ObjectHandler::erotic_enable()
{
    m_books->erotic_enable();
}

ClothMain *ObjectHandler::addRandDress(ClothGroup group)
{
    return m_wardrobe->addRandDress(group);
}

void ObjectHandler::slotViewObj(QString objName)
{
    if (objName == "wardrobe")
    {
        m_wardrobe->viewWardrobe();
    }
    else if (objName == "bed")
    {
        m_bed->viewBed();
    }
    else if (objName == "mirror")
    {
        m_mirror->viewMirror();
    }
    else if(objName == "books")
    {
        m_books->viewBooks();
    }
}

void ObjectHandler::slotInitWardrobe()
{
    m_wardrobe->initWarDrobe();
}
