#include "location.h"
#include "locationhandler.h"
#include "../menu/buttons.h"
#include "../Functions.h"

int Location::getWeekNum()
{
    return root->getWeekNum();
}

int Location::getHour()
{
    return root->getHour();
}

int Location::getMin()
{
    return root->getMin();
}

int Location::getDay()
{
    return root->getDay();
}

int Location::getMonth()
{
    return root->getMonth();
}

int Location::getSunWeather()
{
    return root->getSunWeather();
}

int Location::getSnow()
{
    return root->getSnow();
}

int Location::getTemp()
{
    return root->getTemp();
}

int Location::getSunrise()
{
    return root->getSunrise();
}

int Location::getSunset()
{
    return root->getSunset();
}

int Location::cardCheck()
{
    return root->m_card.check();
}

void Location::cardInit(int count, int time)
{
    root->m_card.init(count, time);
}

QString Location::getCard()
{
    return root->m_card.getCard();
}

int Location::getCardTime()
{
    return root->m_card.getCardTime();
}

int Location::getCardHorny()
{
    return root->m_card.getCardHorny();
}

int Location::gVStatus(Status param)
{
    return root->getVStatus(param);
}

int Location::gVSick(Sickness param)
{
    return root->getVSick(param);
}

int Location::gVBody(Body param)
{
    return root->getVBody(param);
}

int Location::gVSex(SexVar param)
{
    return root->getSexVar(param);
}

int Location::gVSkill(Skills param)
{
    return root->getVSkill(param);
}

int Location::getItemCount(Items id)
{
    return root->getItmCount(id);
}

int Location::gVSC(SC param)
{
    return root->getVStatistic(param);
}

int Location::gVJob(JobStatus param)
{
    return root->getVJob(param);
}

int Location::gVAddict(Addiction param)
{
    return root->getVAddict(param);
}

bool Location::isAutoTampon()
{
    return root->isAutoTampon();
}

bool Location::isDay()
{
    return root->isDay();
}

Location::Location(LocationHandler *ptr): root(ptr){}

void Location::rendImagePage()
{
    root->m_render->rendImagePage(root);
}

void Location::rendVideoPage()
{
    root->m_render->rendVideoPage(root);
}

void Location::rendObjPage()
{
    root->m_render->rendObjPage(root);
}

void Location::addLayoutInObjPage(QLayout *layout)
{
    root->m_render->addLayoutsInObjPage(layout);
}

void Location::setImage(QString path)
{
    root->m_render->setImage(path);
}

void Location::setVideo(QString path, int width, int height)
{
    root->m_render->setVideo(path, width, height);
}

void Location::setDesc(QString text)
{
    root->m_render->setText(text);
}

void Location::addText(QString text)
{
    root->m_render->addText(text);
}

void Location::addActBtn(QPushButton *btn)
{
    root->m_actions->addWidget(btn);
}

void Location::clearActions()
{
    ClearLayout(root->m_actions);
}

void Location::updateParams()
{
    root->updateParams();
}

void Location::sendNotif(QString message)
{
    root->sendNotif(message);
}

void Location::fancywork()
{
    root->m_common->fancywork();
}

void Location::home_workout()
{
    root->m_common->home_workout();
}

void Location::read_porn()
{
    root->m_common->read_porn();
}

void Location::drinkAll()
{
    root->m_kitchenActs->drink_all();
}

void Location::cookies()
{
    root->m_kitchenActs->cookie();
}

void Location::fatDel()
{
    root->m_kitchenActs->fatdel();
}

void Location::vitamin()
{
    root->m_kitchenActs->vitamin();
}

void Location::pills()
{
    root->m_kitchenActs->pills();
}

void Location::eat(QString foodtype, QString image, QString text)
{
    root->m_kitchenActs->eat(foodtype,image,text);
}

void Location::drink(QString napitokType)
{
    root->m_kitchenActs->drink(napitokType);
}

void Location::fnAlko(int val)
{
    root->fnAlko(val);
}

void Location::incTime(int min)
{
    root->incTime(min);
}

bool Location::isMesec()
{
    return root->isMesec();
}

void Location::uVStatus(Status param, int val)
{
    root->updVStatus(param,val);
}

void Location::uVBody(Body param, int val)
{
    root->updVBody(param,val);
}

void Location::uVSC(SC param, int val)
{
    root->updVStatistic(param,val);
}

void Location::uVSkill(Skills param, int val)
{
    root->updVSkill(param,val);
}

void Location::uVJob(JobStatus param, int val)
{
    root->updVJob(param,val);
}

void Location::uVEvent(EventParams param, int val)
{
    root->m_events->uVEvent(param, val);
}

void Location::uVSex(SexVar param, int val)
{
    root->updVSex(param,val);
}

void Location::sVStatus(Status param, int val)
{
    root->setVStatus(param,val);
}

void Location::sVBody(Body param, int val)
{
    root->setVBody(param,val);
}

void Location::sVSex(SexVar param, int val)
{
    root->setSexVar(param,val);
}

void Location::sVJob(JobStatus param, int val)
{
    root->setVJob(param,val);
}

void Location::updSkin(char c, int val)
{
    root->updSkin(c, val);
}

void Location::setBoyName(QString name)
{
    root->setBoyName(name);
}

void Location::decrease_condition(int val)
{
    root->decreaseCondition(val);
}

void Location::startEvent(Events event, QString arg)
{
    root->m_events->startEvent(event, arg);
}

int Location::gVQuest(QuestParams param)
{
    return root->m_events->gVQuest(param);
}

void Location::sVQuest(QuestParams param, int val)
{
    root->m_events->sVQuest(param,val);
}

void Location::uVQuest(QuestParams param, int val)
{
    root->m_events->uVQuest(param,val);
}

int Location::gVEvent(EventParams param)
{
    return root->m_events->gVEvent(param);
}

void Location::sVEvent(EventParams param, int val)
{
    root->m_events->sVEvent(param,val);
}

bool Location::isHanters()
{
    return root->m_events->isHanters();
}

void Location::changeLoc(LocId locId, int min)
{
    root->slotChangeLoc(locId,min);
}

void Location::viewObj(QString object)
{
    root->viewObj(object);
}

void Location::startSelfPlay()
{
    root->startSelfPlay();
}

void Location::fnSport(int arg)
{
    root->m_common->fnsport(arg);
}

void Location::fnBlowJob()
{
    root->blow_job();
}

void Location::fnCum(QString target)
{
    root->cum(target);
}

void Location::fnSwallow()
{
    root->fnswallow();
}

void Location::dp_start()
{
    root->dp_start();
}

void Location::redress(ClothType type, Cloth *newCloth)
{
    root->redress(type, newCloth);
}

void Location::redressOld()
{
    root->redressOld();
}

void Location::storeOldToWardrobe()
{
    root->storeOldToWardrobe();
}

void Location::useItem(Items id, int count)
{
    root->useItem(id,count);
}

void Location::addItem(Items id, int count)
{
    root->addItem(id,count);
}

void Location::addCloth(Cloth *thing)
{
    root->addCloth(thing);
}

int Location::getClothGroup()
{
    return root->getClothGroup();
}

Cloth *Location::getCloth(ClothType type)
{
    return root->getCloth(type);
}

bool Location::isSkirt()
{
    return root->isSkirt();
}

bool Location::isPanties()
{
    return root->isPanties();
}

bool Location::isGlamour()
{
    return root->isGlamour();
}

bool Location::isJeans()
{
    return root->isJeans();
}

bool Location::isNude()
{
    return root->isNude();
}

bool Location::isCloth()
{
    return root->isCloth();
}

QString Location::sextToysBlock(int val)
{
    return root->sextToysBlock(val);
}

QString Location::getItemName(Items id)
{
    return root->getItemName(id);
}

void Location::walk()
{
    root->m_beach->walk();
}

void Location::undress(int arg)
{
    root->m_beach->undress(arg);
}

void Location::sunbathe(int isCream)
{
    root->m_beach->sunbathe(isCream);
}

void Location::cream()
{
    root->m_beach->cream();
}

void Location::swim()
{
    root->m_beach->swim();
}

void Location::getDressed(int arg)
{
    root->m_beach->getDressed(arg);
}

QString Location::getPFName()
{
    return root->getPFName();
}

Location *Location::getLocPtr(LocId locId)
{
    return root->getLocPtr(locId);
}

int Location::gVSchool(SchoolVar param)
{
    return root->m_events->gVSchool(param);
}

void Location::uVSchool(SchoolVar param, int val)
{
    root->m_events->uVSchool(param,val);
}

void Location::sVSchool(SchoolVar param, int val)
{
    root->m_events->sVSchool(param,val);
}

LocId Location::getPrevId()
{
    return root->m_prev->getLocId();
}

LocId Location::getPrevIn()
{
    return root->m_prev->getLocIn();
}

QLabel *Location::getTextPtr()
{
    return root->m_render->getTextPtr();
}

NPC Location::gNPC(int id)
{
    return root->gNPC(id);
}
