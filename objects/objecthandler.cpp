#include "objecthandler.h"
#include "bed.h"
#include "mirror.h"
#include "wardrobe.h"
#include "books.h"
#include "../menu/mainwindow.h"

ObjectHandler::ObjectHandler(Render* ptr, QWidget* parent, QVBoxLayout* actions):
    m_render(ptr),
    root(parent),
    m_actions(actions)
{
    m_bed = new Bed(this);
    m_mirror = new Mirror(this);
    m_wardrobe = new Wardrobe(this);
    m_books = new Books(this);
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

int ObjectHandler::getTemp()
{
    return ((MainWindow*)root)->m_weather->getTemp();
}

int ObjectHandler::getSunWeather()
{
    return ((MainWindow*)root)->m_weather->getSunWeather();
}

bool ObjectHandler::isNude()
{
    return ((MainWindow*)root)->m_player->isNude();
}

int ObjectHandler::getVStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int ObjectHandler::getVBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

int ObjectHandler::getVAddict(Addiction param)
{
    return ((MainWindow*)root)->m_player->getVAddict(param);
}

int ObjectHandler::getVBuzzer(budilnik param)
{
    return ((MainWindow*)root)->m_player->getVBuzzer(param);
}

int ObjectHandler::getVSick(Sickness param)
{
    return ((MainWindow*)root)->m_player->getVSick(param);
}

int ObjectHandler::getHour()
{
    return ((MainWindow*)root)->m_time.getHour();
}

int ObjectHandler::getMin()
{
    return ((MainWindow*)root)->m_time.getMin();
}

int ObjectHandler::getMonth()
{
    return ((MainWindow*)root)->m_time.getMonth();
}

int ObjectHandler::getVSC(SC param)
{
    return ((MainWindow*)root)->m_player->getStatisticsValue(param);
}

int ObjectHandler::getVsexVar(SexVar param)
{
    return ((MainWindow*)root)->m_player->getVSexVar(param);
}

int ObjectHandler::getItmCount(Items id)
{
    return ((MainWindow*)root)->m_bag->getQuantityof(id);
}

int ObjectHandler::alkoBlock()
{
    return ((MainWindow*)root)->m_ccalko.alkoBlock();
}

int ObjectHandler::gVQuest(QuestParams param)
{
    return ((MainWindow*)root)->locHandler->gVQuest(param);
}

int ObjectHandler::gVEvent(EventParams param)
{
    return ((MainWindow*)root)->locHandler->gVEvent(param);
}

void ObjectHandler::uVEvent(EventParams param, int val)
{
    ((MainWindow*)root)->locHandler->uVEvent(param,val);
}

void ObjectHandler::sVEvent(EventParams param, int val)
{
    ((MainWindow*)root)->locHandler->sVEvent(param,val);
}

void ObjectHandler::sVQuest(QuestParams param, int val)
{
    ((MainWindow*)root)->locHandler->sVQuest(param,val);
}

void ObjectHandler::sendNotif(QString text)
{
    ((MainWindow*)root)->showNotif(text);
}

void ObjectHandler::updateParams()
{
    ((MainWindow*)root)->slotUpdParams();
}

void ObjectHandler::setVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->setVStatus(param,val);
}

void ObjectHandler::setVSexVar(SexVar param, int val)
{
    ((MainWindow*)root)->m_player->setVSexVar(param,val);
}

void ObjectHandler::setVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->setVBody(param,val);
}

void ObjectHandler::updVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->updVStatus(param,val);
}

void ObjectHandler::updVSkill(Skills param, int val)
{
    ((MainWindow*)root)->m_player->updVSkill(param,val);
}

void ObjectHandler::updVBody(Body param, int value)
{
    ((MainWindow*)root)->m_player->updVBody(param,value);
}

void ObjectHandler::updBuzzer(budilnik param, int val)
{
    ((MainWindow*)root)->m_player->updVBuzzer(param,val);
}

void ObjectHandler::updVAddict(Addiction param, int val)
{
    ((MainWindow*)root)->m_player->updVAddict(param,val);
}

void ObjectHandler::incTime(int min)
{
    ((MainWindow*)root)->m_time.increaseTime(min);
}

void ObjectHandler::changeLoc(LocId locId)
{
    ((MainWindow*)root)->locHandler->slotChangeLoc(locId,1);
}

void ObjectHandler::decreaseClothCond(int val)
{
    ((MainWindow*)root)->m_player->decreaseCondition(val);
}

void ObjectHandler::redress(ClothType type,Cloth *thing)
{
    ((MainWindow*)root)->m_player->redress(type,thing);
}

void ObjectHandler::redressOld()
{
    ((MainWindow*)root)->m_player->redressOld();
}

void ObjectHandler::startSelfPlay()
{
    ((MainWindow*)root)->sexHandler->selfPlayStart();
}

void ObjectHandler::useItem(Items id, int count)
{
    ((MainWindow*)root)->m_bag->useItem(id, count);
}

bool ObjectHandler::isPanties()
{
    return ((MainWindow*)root)->m_player->isPanties();
}

bool ObjectHandler::isHapri()
{
    return ((MainWindow*)root)->page4->isHapri();
}

Cloth *ObjectHandler::getCloth(ClothType type)
{
    return ((MainWindow*)root)->m_player->getCloth(type);
}

Location *ObjectHandler::getCurLoc()
{
    return ((MainWindow*)root)->locHandler->getCurPtr();
}

Player *ObjectHandler::player()
{
    return ((MainWindow*)root)->m_player;
}

NPC& ObjectHandler::gNPC(int id)
{
    return ((MainWindow*)root)->m_npc->gNPC(id);
}
