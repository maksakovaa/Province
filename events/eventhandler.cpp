#include "eventhandler.h"
#include "EventHeaders.h"
#include "../nav/locationhandler.h"
#include "../Functions.h"

EventHandler::EventHandler(LocationHandler* ptr): root(ptr) 
{
    initEvents();
}

void EventHandler::eventStart(QString event, QString arg)
{
    m_events[event]->start(arg);
}

void EventHandler::rendImagePage()
{
    root->m_render->rendImagePage(root);
}

void EventHandler::rendVideoPage()
{
    root->m_render->rendVideoPage(root);
}

void EventHandler::setImage(QString path)
{
    root->setImage(path);
}

void EventHandler::setVideo(QString path, int width, int height)
{
    root->m_render->setVideo(path,width,height);
}

void EventHandler::setDesc(QString text)
{
    root->setDesc(text);
}

void EventHandler::addDesc(QString text)
{
    root->addDesc(text);
}

void EventHandler::addActBtn(QPushButton *btn)
{
    root->m_actions->addWidget(btn);
}

void EventHandler::clearActions()
{
    ClearLayout(root->m_actions);
}

QLabel *EventHandler::getTextPtr()
{
    return root->m_render->getTextPtr();
}

void EventHandler::eat(QString foodtype, QString image, QString text)
{
    root->m_kitchenActs->eat(foodtype,image,text);
}

int EventHandler::getAge()
{
    return root->getAge();
}

void EventHandler::initEvents()
{
    for (int i = 0; i <= lastEventParam; ++i)
    {
        m_eventval[static_cast<EventParams>(i)] = 0;
    }
    for(int i = 0; i < lastQW; ++i)
    {
        m_questval[static_cast<QuestParams>(i)] = 0;
    }
    m_eventval[know_no_pirat] = 1;
    m_events["AndreiHanter"] = new AndreiHanter(this);
    m_events["bicycle"] = new Bicycle(this);
    m_events["gadforest_event"] = new GadforestEvent(this);
    m_events["gadforestlost"] = new GadforestLost(this);
    m_events["gadforestrelax"] = new GadforestRelax(this);
    m_events["gadukino_event"] = new GadukinoEvent(this);
    m_events["grandma"] = new Grandma(this);
    m_events["grandmahelp"] = new GrandmaHelp(this);
    m_events["grandpa"] = new Grandpa(this);
    m_events["grandpahelp"] = new GrandpaHelp(this);
    m_events["Miroslava"] = new Miroslava(this);
    m_events["Mitka"] = new Mitka(this);
    m_events["mitkasex"] = new MitkaSex(this);
    m_events["Pirat"] = new Pirat(this);
    m_events["river_events"] = new RiverEvents(this);
    m_events["swamp_events"] = new SwampEvents(this);

    m_events["family"] = new Family(this);
}

int EventHandler::getMonth()
{
    return root->getMonth();
}

int EventHandler::getSunWeather()
{
    return root->getSunWeather();
}

int EventHandler::getSunset()
{
    return root->getSunset();
}

int EventHandler::getSunrise()
{
    return root->getSunrise();
}

int EventHandler::getDay()
{
    return root->getDay();
}

bool EventHandler::isDay()
{
    return root->isDay();
}

int EventHandler::getHour()
{
    return root->getHour();
}

int EventHandler::getWeekNum()
{
    return root->getWeekNum();
}

int EventHandler::getTemp()
{
    return root->getTemp();
}

int EventHandler::getSnow()
{
    return root->getSnow();
}

int EventHandler::getItmCount(Items id)
{
    return root->getItmCount(id);
}

void EventHandler::addItem(Items id, int count)
{
    root->addItem(id,count);
}

void EventHandler::useItem(Items id, int count)
{
    root->useItem(id,count);
}

int EventHandler::vStatus(Status param)
{
    return root->getVStatus(param);
}

int EventHandler::vBody(Body param)
{
    return root->getVBody(param);
}

int EventHandler::vSkill(Skills param)
{
    return root->getVSkill(param);
}

int EventHandler::vSC(SC param)
{
    return root->getVStatistic(param);
}

int EventHandler::vAddict(Addiction param)
{
    return root->getVAddict(param);
}

int EventHandler::vSex(SexVar param)
{
    return root->getSexVar(param);
}

int EventHandler::vSick(Sickness param)
{
    return root->getVSick(param);
}

bool EventHandler::isMesec()
{
    return root->getVStatus(mesec) > 0;
}

void EventHandler::uVStatus(Status param, int val)
{
    root->updVStatus(param,val);
}

void EventHandler::uVBody(Body param, int val)
{
    root->updVBody(param,val);
}

void EventHandler::uVSkill(Skills param, int val)
{
    root->updVSkill(param,val);
}

void EventHandler::uVSC(SC param, int val)
{
    root->updVStatistic(param,val);
}

void EventHandler::uVSex(SexVar param, int val)
{
    root->updVSex(param,val);
}

void EventHandler::sVStatus(Status param, int val)
{
    root->setVStatus(param,val);
}

void EventHandler::sVSex(SexVar param, int val)
{
    root->setSexVar(param,val);
}

void EventHandler::sVBody(Body param, int val)
{
    root->setVBody(param,val);
}

void EventHandler::setBoyName(QString name)
{
    root->setBoyName(name);
}

void EventHandler::setBoy2Name(QString name)
{
    root->setBoy2Name(name);
}

QString EventHandler::getLipTalk()
{
    return root->getLipTalk();
}

QString EventHandler::getLipTalk3()
{
    return root->getLipTalk3();
}

QString EventHandler::getAnusTipe()
{
    return root->getAnusTipe();
}

QString EventHandler::getAnusTipe2()
{
    return root->getAnusTipe2();
}

QString EventHandler::getVaginaTipe2()
{
    return root->getVaginaTipe2();
}

QString EventHandler::getBoyName()
{
    return root->getBoyName();
}

QString EventHandler::getBoy2Name()
{
    return root->getBoy2Name();
}

Cloth *EventHandler::getCloth(ClothType type)
{
    return root->getCloth(type);
}

void EventHandler::redress(ClothType type, Cloth *newCloth)
{
    root->redress(type, newCloth);
}

void EventHandler::redressOld()
{
    root->redressOld();
}

bool EventHandler::isNude()
{
    return root->isNude();
}

bool EventHandler::isCloth()
{
    return root->isCloth();
}

bool EventHandler::isSkirt()
{
    return root->isSkirt();
}

bool EventHandler::isPanties()
{
    return root->isPanties();
}

int EventHandler::getClothGroup()
{
    return root->getClothGroup();
}

void EventHandler::decCondition(int val)
{
    root->decreaseCondition(val);
}

void EventHandler::startSelfPlay()
{
    root->startSelfPlay();
}

void EventHandler::sexStart()
{
    root->sexStart();
}

void EventHandler::analStart(ToolType type)
{
    root->analStart(type);
}

void EventHandler::vaginal(ToolType type, QString pos)
{
    root->vaginal(type,pos);
}

void EventHandler::anal(ToolType type)
{
    root->anal(type);
}

void EventHandler::sex_cum()
{
    root->sex_cum();
}

void EventHandler::cum(QString target)
{
    root->cum(target);
}

void EventHandler::blow_job()
{
    root->blow_job();
}

void EventHandler::anal_cum()
{
    root->anal_cum();
}

void EventHandler::fnswallow()
{
    root->fnswallow();
}

void EventHandler::double_penetration()
{
    root->double_penetration();
}

void EventHandler::changeLoc(LocId locId, int min, QString arg)
{
    root->slotChangeLoc(locId,min,arg);
}

LocId EventHandler::getCurLoc()
{
    return root->getCurLoc();
}

Location *EventHandler::getLocPtr()
{
    return root->getLocPtr(root->getCurLoc());
}

Location *EventHandler::getLocPtr(LocId loc)
{
    return root->getLocPtr(loc);
}

NPC &EventHandler::gNPC(int id)
{
    return root->gNPC(id);
}

void EventHandler::sleep()
{
    root->sleepInBed();
}

int EventHandler::gVSchool(SchoolVar param)
{
    return m_schoolVal[param];
}

void EventHandler::uVSchool(SchoolVar param, int val)
{
    m_schoolVal[param] += val;
}

void EventHandler::sVSchool(SchoolVar param, int val)
{
    m_schoolVal[param] = val;
}

int EventHandler::gVEvent(EventParams param)
{
    return m_eventval[param];
}

void EventHandler::sVEvent(EventParams param, int val)
{
    m_eventval[param] = val;
}

void EventHandler::uVEvent(EventParams param, int val)
{
    m_eventval[param] += val;
}

bool EventHandler::isHanters()
{
    return m_eventval[hanters] > 0;
}

int EventHandler::gVJob(JobStatus param)
{
    return root->getVJob(param);
}

void EventHandler::sVJob(JobStatus param, int val)
{
    root->setVJob(param,val);
}

int EventHandler::gVQuest(QuestParams param)
{
    return m_questval[param];
}

void EventHandler::sVQuest(QuestParams param, int val)
{
    m_questval[param] = val;
}

void EventHandler::uVQuest(QuestParams param, int val)
{
    m_questval[param] += val;
}

void EventHandler::incTime(int min)
{
    root->incTime(min);
}
