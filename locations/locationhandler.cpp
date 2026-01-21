#include "locationhandler.h"
#include <QFile>
#include "../menu/mainwindow.h"
#include "../menu/ui_mainwindow.h"
#include "../Functions.h"
#include "location_headers.h"
#include "loc_enums.h"

LocationHandler::LocationHandler(Render *ptr, QWidget *parent, QVBoxLayout *actionsLayout):
    m_render(ptr),
    m_root(parent),
    m_actions(actionsLayout)
{
    m_current = nullptr;
    genLocations();
    m_events = new EventHandler(this);
    m_kitchenActs = new KitchenActs(this);
    m_common = new Common(this);
    m_beach = new Beach(this);
}

void LocationHandler::genLocations()
{
    std::vector<Location*> locs;
    //////////////  Common
    locs.push_back(new BathRoom(this));
    locs.push_back(new Shop(this));
    //////////////  Gadukino
    locs.push_back(new Backwater(this));
    locs.push_back(new Gadbana(this));
    locs.push_back(new Gadbeach(this));
    locs.push_back(new Gaddvor(this));
    locs.push_back(new Gadfield(this));
    locs.push_back(new Gadforest(this));
    locs.push_back(new GadForestSwamp(this));
    locs.push_back(new Gadgarden(this));
    locs.push_back(new Gadhouse(this));
    locs.push_back(new Gadmarket(this));
    locs.push_back(new Gadriver(this));
    locs.push_back(new Gadroad(this));
    locs.push_back(new Gadsarai(this));
    locs.push_back(new Gadukino(this));
    locs.push_back(new Meadow(this));
    locs.push_back(new MiroslavaHome(this));
    locs.push_back(new Swamp(this));
    locs.push_back(new SwampHouse(this));
    locs.push_back(new SwampSpring(this));
    locs.push_back(new SwampYard(this));
    /////////////   Pavlovo
    locs.push_back(new korrPar(this));
    locs.push_back(new BedrPar(this));
    locs.push_back(new BedrPar2(this));
    for(auto i: locs)
    {
        m_locations[i->getLocId()] = i;
    }
}

void LocationHandler::checkMapAwailable()
{
    if (m_current->isParent() || m_current->getLocId() == lgadukino)
    {
        ((MainWindow*)m_root)->ui->pushButtonMap->setEnabled(false);
    }
    else
    {
        ((MainWindow*)m_root)->ui->pushButtonMap->setEnabled(true);
    }
}

void LocationHandler::slotChangeLoc(LocId id, int time, QString arg)
{
    m_prev = m_current;
    m_current = m_locations[id];

    ClearLayout(m_actions);

    ((MainWindow*)m_root)->ui->stackedWidget->setCurrentIndex(0);
    incTime(time);

    m_render->rendImagePage(this);
    m_current->show(arg);
    connect(m_render->getTextPtr(), &QLabel::linkActivated, m_current, &Location::actionHandler);
    checkMapAwailable();
}

LocId LocationHandler::getMainLoc()
{
    return m_current->getLocIn();
}

LocId LocationHandler::getPrevLoc()
{
    return m_prev->getLocId();
}

Location *LocationHandler::getCurPtr()
{
    return m_current;
}

int LocationHandler::gVSchool(SchoolVar param)
{
    return m_events->gVSchool(param);
}

void LocationHandler::uVSchool(SchoolVar param, int val)
{
    m_events->uVSchool(param,val);
}

void LocationHandler::sVSchool(SchoolVar param, int val)
{
    m_events->sVSchool(param,val);
}

int LocationHandler::gVEvent(EventParams param)
{
    return m_events->gVEvent(param);
}

int LocationHandler::gVQuest(QuestParams param)
{
    return m_events->gVQuest(param);
}

void LocationHandler::uVEvent(EventParams param, int val)
{
    m_events->uVEvent(param,val);
}

void LocationHandler::sVEvent(EventParams param, int val)
{
    m_events->sVEvent(param,val);
}

void LocationHandler::sVQuest(QuestParams param, int val)
{
    m_events->sVQuest(param,val);
}

LocId LocationHandler::getCurLoc()
{
    return m_current->getLocId();
}

void LocationHandler::updateParams()
{
    ((MainWindow*)m_root)->slotUpdParams();
}
void LocationHandler::incTime(int min)
{
    ((MainWindow*)m_root)->m_time.increaseTime(min);
}

void LocationHandler::updVBody(Body param, int val)
{
    ((MainWindow*)m_root)->m_player->updVBody(param,val);
}

void LocationHandler::updVStatus(Status param, int val)
{
    ((MainWindow*)m_root)->m_player->updVStatus(param,val);
}

void LocationHandler::updVStatistic(SC param, int val)
{
    ((MainWindow*)m_root)->m_player->updVStatistic(param,val);
}

void LocationHandler::updVSkill(Skills type, int val)
{
    ((MainWindow*)m_root)->m_player->updVSkill(type, val);
}

void LocationHandler::updVSex(SexVar param, int val)
{
    ((MainWindow*)m_root)->m_player->updVSexVar(param,val);
}

void LocationHandler::updVSick(Sickness param, int val)
{
    ((MainWindow*)m_root)->m_player->updVSick(param,val);
}

void LocationHandler::updVJob(JobStatus param, int val)
{
    ((MainWindow*)m_root)->m_player->updVJob(param,val);
}

void LocationHandler::fnAlko(int val)
{
    ((MainWindow*)m_root)->m_ccalko.fnAlko(val);
}

void LocationHandler::useItem(Items item, int count)
{
    ((MainWindow*)m_root)->m_bag->useItem(item,count);
}

void LocationHandler::setSexVar(SexVar var, int value)
{
    ((MainWindow*)m_root)->m_player->setVSexVar(var, value);
}

void LocationHandler::setVStatus(Status param, int value)
{
    ((MainWindow*)m_root)->m_player->setVStatus(param,value);
}

void LocationHandler::setVBody(Body param, int value)
{
    ((MainWindow*)m_root)->m_player->setVBody(param,value);
}

void LocationHandler::setVJob(JobStatus param, int val)
{
    ((MainWindow*)m_root)->m_player->setVJob(param,val);
}

void LocationHandler::setVSC(SC param, int val)
{
    ((MainWindow*)m_root)->m_player->setVSC(param,val);
}

void LocationHandler::setBoyName(QString name)
{
    ((MainWindow*)m_root)->m_player->setBoyName(name);
}

void LocationHandler::setBoy2Name(QString name)
{
    ((MainWindow*)m_root)->m_player->setBoy2Name(name);
}

void LocationHandler::startSelfPlay()
{
    ((MainWindow*)m_root)->sexHandler->selfPlayStart();
}

void LocationHandler::sexStart()
{
    ((MainWindow*)m_root)->sexHandler->sexStart();
}

void LocationHandler::analStart(ToolType type)
{
    ((MainWindow*)m_root)->sexHandler->analStart(type);
}

void LocationHandler::vaginal(ToolType type, QString pos)
{
    ((MainWindow*)m_root)->sexHandler->vaginal(type,pos);
}

void LocationHandler::anal(ToolType type)
{
    ((MainWindow*)m_root)->sexHandler->anal(type);
}

void LocationHandler::sex_cum()
{
    ((MainWindow*)m_root)->sexHandler->sex_cum();
}

void LocationHandler::blow_job()
{
    ((MainWindow*)m_root)->sexHandler->blow_job();
}

void LocationHandler::anal_cum()
{
    ((MainWindow*)m_root)->sexHandler->anal_cum();
}

void LocationHandler::fnswallow()
{
    ((MainWindow*)m_root)->sexHandler->fnswallow();
}

void LocationHandler::dp_start()
{
    ((MainWindow*)m_root)->sexHandler->dp_start();
}

void LocationHandler::double_penetration()
{
    ((MainWindow*)m_root)->sexHandler->double_penetration();
}

void LocationHandler::sleepInBed()
{
    ((MainWindow*)m_root)->objHandler->sleep();
}

int LocationHandler::getVBody(Body param)
{
    return ((MainWindow*)m_root)->m_player->getVBody(param);
}

int LocationHandler::getVStatus(Status param)
{
    return ((MainWindow*)m_root)->m_player->getVStatus(param);
}

int LocationHandler::getItmCount(Items item)
{
    return ((MainWindow*)m_root)->m_bag->getQuantityof(item);
}

int LocationHandler::getSexVar(SexVar var)
{
    return ((MainWindow*)m_root)->m_player->getVSexVar(var);
}

int LocationHandler::getVStatistic(SC param)
{
    return ((MainWindow*)m_root)->m_player->getStatisticsValue(param);
}

int LocationHandler::getVSkill(Skills type)
{
    return ((MainWindow*)m_root)->m_player->getSkillValue(type);
}

int LocationHandler::getVSick(Sickness param)
{
    return ((MainWindow*)m_root)->m_player->getVSick(param);
}

int LocationHandler::getVJob(JobStatus param)
{
    return ((MainWindow*)m_root)->m_player->getVJob(param);
}

int LocationHandler::getVAddict(Addiction param)
{
    return ((MainWindow*)m_root)->m_player->getVAddict(param);
}

int LocationHandler::alkoBlock()
{
    return ((MainWindow*)m_root)->m_ccalko.alkoBlock();
}

QString LocationHandler::getLipTalk()
{
    return ((MainWindow*)m_root)->m_player->getLipTalk();
}

QString LocationHandler::getLipTalk3()
{
    return ((MainWindow*)m_root)->m_player->getLipTalk3();
}

QString LocationHandler::getAnusTipe2()
{
    return ((MainWindow*)m_root)->m_player->getAnusTipe2();
}

QString LocationHandler::getAnusTipe()
{
    return ((MainWindow*)m_root)->m_player->getAnusTipe1();
}

QString LocationHandler::getVaginaTipe2()
{
    return ((MainWindow*)m_root)->m_player->getVaginaTipe2();
}

QString LocationHandler::getBoyName()
{
    return ((MainWindow*)m_root)->m_player->getBoyName();
}

QString LocationHandler::getBoy2Name()
{
    return ((MainWindow*)m_root)->m_player->getBoy2Name();
}

QString LocationHandler::getPFName()
{
    return ((MainWindow*)m_root)->m_player->getPFName();
}

int LocationHandler::getAge()
{
    return ((MainWindow*)m_root)->m_player->getAge();
}

int LocationHandler::getDay()
{
    return ((MainWindow*)m_root)->m_time.getDay();
}

bool LocationHandler::isDay()
{
    return ((MainWindow*)m_root)->m_weather->isDay();
}

void LocationHandler::cum(QString target)
{
    ((MainWindow*)m_root)->sexHandler->cum(target);
}

void LocationHandler::sendNotif(QString text)
{
    ((MainWindow*)m_root)->showNotif(text);
}

QString LocationHandler::getItemName(Items id)
{
    return ((MainWindow*)m_root)->m_bag->getItemName(id);
}

QString LocationHandler::sextToysBlock(int val)
{
    return ((MainWindow*)m_root)->m_ccsex.sextToysBlock(val);
}

Location *LocationHandler::getLocPtr(LocId locId)
{
    return m_locations[locId];
}

QString LocationHandler::getBookName(int id)
{
    return ((MainWindow*)m_root)->objHandler->getBookName(id);
}

void LocationHandler::readOnWalk()
{
    ((MainWindow*)m_root)->objHandler->readOnWalk();
}

int LocationHandler::eroReaded()
{
    return ((MainWindow*)m_root)->objHandler->eroReaded();
}

void LocationHandler::eroBlock()
{
    ((MainWindow*)m_root)->objHandler->eroBlock();
}

NPC& LocationHandler::gNPC(int id)
{
    return ((MainWindow*)m_root)->m_npc->gNPC(id);
}

void LocationHandler::rendNpcProfile(NPCId id)
{
    ((MainWindow*)m_root)->m_npc->rendNpcProfile(id);
}

int LocationHandler::getMonth()
{
    return ((MainWindow*)m_root)->m_time.getMonth();
}

int LocationHandler::getHour()
{
    return ((MainWindow*)m_root)->m_time.getHour();
}

int LocationHandler::getMin()
{
    return ((MainWindow*)m_root)->m_time.getMin();
}

int LocationHandler::getWeekNum()
{
    return ((MainWindow*)m_root)->m_time.getWeekNum();
}

int LocationHandler::getSunWeather()
{
    return ((MainWindow*)m_root)->m_weather->getSunWeather();
}

int LocationHandler::getSnow()
{
    return ((MainWindow*)m_root)->m_weather->getSnow();
}

int LocationHandler::getTemp()
{
    return ((MainWindow*)m_root)->m_weather->getTemp();
}

int LocationHandler::getSunrise()
{
    return ((MainWindow*)m_root)->m_weather->getSunrise();
}

int LocationHandler::getSunset()
{
    return ((MainWindow*)m_root)->m_weather->getSunset();
}

void LocationHandler::setImage(QString path)
{
    m_render->setImage(path);
}

void LocationHandler::setDesc(QString text)
{
    m_render->setText(text);
}

void LocationHandler::addDesc(QString str)
{
    m_render->addText(str);
}

bool LocationHandler::isAutoTampon()
{
    return ((MainWindow*)m_root)->page4->isAutoTampon();
}

bool LocationHandler::whoreState()
{
    return ((MainWindow*)m_root)->page4->whoreState();
}

bool LocationHandler::isMesec()
{
    return ((MainWindow*)m_root)->m_reproductSys.isMesec();
}

void LocationHandler::redress(ClothType type, Cloth *newCloth)
{
    ((MainWindow*)m_root)->m_player->redress(type, newCloth);
}

void LocationHandler::redressOld()
{
    ((MainWindow*)m_root)->m_player->redressOld();
}

void LocationHandler::storeOldToWardrobe()
{
    ((MainWindow*)m_root)->m_player->storeOldToWardrobe();
}

Cloth *LocationHandler::getCloth(ClothType type)
{
    return ((MainWindow*)m_root)->m_player->getCloth(type);
}

bool LocationHandler::isSkirt()
{
    return ((MainWindow*)m_root)->m_player->isSkirt();
}

bool LocationHandler::isPanties()
{
    return ((MainWindow*)m_root)->m_player->isPanties();
}

bool LocationHandler::isGlamour()
{
    return ((MainWindow*)m_root)->m_player->isGlamour();
}

bool LocationHandler::isJeans()
{
    return ((MainWindow*)m_root)->m_player->isJeans();
}

bool LocationHandler::isNude()
{
    return ((MainWindow*)m_root)->m_player->isNude();
}

bool LocationHandler::isCloth()
{
    return ((MainWindow*)m_root)->m_player->isCloth();
}

int LocationHandler::getClothGroup()
{
    return ((MainWindow*)m_root)->m_player->getClothGroup();
}

void LocationHandler::viewObj(QString obj)
{
    ((MainWindow*)m_root)->objHandler->slotViewObj(obj);
}

void LocationHandler::updSkin(char c, int val)
{
    ((MainWindow*)m_root)->m_player->updSkin(c,val);
}

void LocationHandler::addCloth(Cloth *thing)
{
    ((MainWindow*)m_root)->objHandler->storeCloth(thing);
}

void LocationHandler::decreaseCondition(int val)
{
    ((MainWindow*)m_root)->m_player->decreaseCondition(val);
}

int LocationHandler::getClothDecreaseLevel()
{
    return m_common->getClothDecreaseLevel();
}

void LocationHandler::removeCloth(ClothGroup group)
{
    ((MainWindow*)m_root)->objHandler->removeCloth(group);
}

void LocationHandler::addItem(Items id, int count)
{
    ((MainWindow*)m_root)->m_bag->putInBag(id,count);
}
