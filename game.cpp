#include "game.h"
#include "Functions.h"
#include "mainwindow.h"
#include "menu/ui_mainwindow.h"

Game::Game(QWidget* ptr, int year, int month, int day, int hour, int min):
    m_window(ptr),
    m_time(this, year, month, day, hour, min),
    m_ccalko(this),
    m_preg(this),
    m_ccsex(this),
    m_rep(this)
{
    m_actions = ((MainWindow*)m_window)->ui->actionsLayout;
    m_render = ((MainWindow*)m_window)->m_render;
    m_player = new Player(this);
    m_weather = new Weather(this);
    m_locs = new LocationHandler(this);
    m_objs = new ObjectHandler(this);
    connect(m_player, &Player::sigInitWardrobe, m_objs, &ObjectHandler::slotInitWardrobe);
    m_sex = new SexHandler(this);
    m_npc = new NPC_Editor(this);
    m_drugs = new Drugs(this);
    m_events = new EventHandler(this);
    m_npc->init();
}

Game::Game(QWidget *ptr):
    m_window(ptr),
    m_time(this),
    m_ccalko(this),
    m_preg(this),
    m_ccsex(this),
    m_rep(this)
{
    m_actions = ((MainWindow*)m_window)->ui->actionsLayout;
    m_render = ((MainWindow*)m_window)->m_render;
    m_player = new Player(this);
    m_weather = new Weather(this);
    m_locs = new LocationHandler(this);
    m_objs = new ObjectHandler(this);
    connect(m_player, &Player::sigInitWardrobe, m_objs, &ObjectHandler::slotInitWardrobe);
    m_sex = new SexHandler(this);
    m_npc = new NPC_Editor(this);
    m_drugs = new Drugs(this);
    m_events = new EventHandler(this);
    m_npc->init();
}

void Game::newGame(QString loc, CharacterType charType)
{
    m_player->newPlayer(charType);
    emit m_player->sigInitWardrobe();
    m_player->calcVneshBonus();
    m_preg.slotEstrus();
    m_time.firstStart();
    updateParams();
    m_ccalko.slotDataInitAlko();
    if(loc == "gaddvor")
        m_locs->slotChangeLoc(lgaddvor,0);
    else if(loc == "parents_home")
        m_locs->slotChangeLoc(lbedrpar,0);
}

void Game::rendVideoPage(QObject *ptr)
{
    m_render->rendVideoPage(ptr);
}

void Game::rendImagePage(QObject *ptr)
{
    m_render->rendImagePage(ptr);
}

void Game::rendObjPage(QObject *ptr)
{
    m_render->rendObjPage(ptr);
}

void Game::setImage(QString path)
{
    m_render->setImage(path);
}

void Game::setText(QString text)
{
    m_render->setText(text);
}

void Game::addText(QString text)
{
    m_render->addText(text);
}

void Game::setVideo(QString path, int width, int height)
{
    m_render->setVideo(path,width,height);
}

void Game::addLayoutsInObjPage(QLayout *layout)
{
    m_render->addLayoutsInObjPage(layout);
}

void Game::addQWidgetInObjPage(QWidget *widget)
{
    m_render->addQWidgetInObjPage(widget);
}

QLabel *Game::getTextPtr()
{
    return m_render->getTextPtr();
}

QLabel *Game::getImagePtr()
{
    return m_render->getImagePtr();
}

void Game::addActions(QWidget *widget)
{
    m_actions->addWidget(widget);
}

void Game::clearActions()
{
    ClearLayout(m_actions);
}

void Game::updateParams()
{
    ((MainWindow*)m_window)->slotUpdParams();
}

void Game::sendNotif(QString msg)
{
    ((MainWindow*)m_window)->showNotif(msg);
}

bool Game::whoreState()
{
    return ((MainWindow*)m_window)->m_settings->whoreState();
}

bool Game::isCheats()
{
    return ((MainWindow*)m_window)->m_settings->isCheats();
}

bool Game::isHapri()
{
    return ((MainWindow*)m_window)->m_settings->isHapri();
}

int Game::getBody_tits()
{
    return ((MainWindow*)m_window)->m_settings->getBody_tits();
}

bool Game::getPubicHair()
{
    return ((MainWindow*)m_window)->m_settings->getPubicHair();
}

int Game::getBodyType()
{
    return ((MainWindow*)m_window)->m_settings->getBodyType();
}

bool Game::isFullScreen()
{
    return ((MainWindow*)m_window)->m_settings->isFullScreen();
}

int Game::getLanguage()
{
    return ((MainWindow*)m_window)->m_settings->getLanguage();
}

int Game::getAddTxtSex()
{
    return ((MainWindow*)m_window)->m_settings->getAddTxtSex();
}

int Game::getSexLevel()
{
    return ((MainWindow*)m_window)->m_settings->getSexLevel();
}

void Game::addItem(Items name, int count)
{
    ((MainWindow*)m_window)->m_bag->putInBag(name,count);
}

int Game::getItmCount(Items name)
{
    return ((MainWindow*)m_window)->m_bag->getQuantityof(name);
}

void Game::useItem(Items name, int count)
{
    ((MainWindow*)m_window)->m_bag->useItem(name,count);
}

QString Game::getItemName(Items id)
{
    ((MainWindow*)m_window)->m_bag->getItemName(id);
}

void Game::setItemCount(Items id, int count)
{
    ((MainWindow*)m_window)->m_bag->setItemCount(id,count);
}

bool Game::isAutoTampon()
{
    return ((MainWindow*)m_window)->m_settings->isAutoTampon();
}
//TimeServer funcs
void Game::incTime(int min)
{
    m_time.increaseTime(min);
}

int Game::getYear()
{
    return m_time.getYear();
}

int Game::getMonth()
{
    return m_time.getMonth();
}

int Game::getDay()
{
    return m_time.getDay();
}

int Game::getHour()
{
    return m_time.getHour();
}

int Game::getMin()
{
    return m_time.getMin();
}

int Game::getWeek()
{
    return m_time.getWeekNum();
}

int Game::calcYears(tm from)
{
    return m_time.calcYears(from);
}

void Game::setTime(int hour, int min)
{
    m_time.setTime(hour,min);
}
//Weather
bool Game::isDay()
{
    return m_weather->isDay();
}

bool Game::isSnow()
{
    return m_weather->isSnow();
}

QString Game::getImage()
{
    return m_weather->getImage();
}

QString Game::getCurrentTemp()
{
    return m_weather->getCurrentTemp();
}

void Game::updOnTimeMove()
{
    m_weather->updOnTimeMove();
}

int Game::getSunWeather()
{
    return m_weather->getSunWeather();
}

int Game::getSnow()
{
    return m_weather->getSnow();
}

int Game::getTemp()
{
    return m_weather->getTemp();
}

int Game::getSunrise()
{
    return m_weather->getSunrise();
}

int Game::getSunset()
{
    return m_weather->getSunset();
}

void Game::fnWeather()
{
    m_weather->mainFunc();
}
//Event funcs
void Game::startEvent(Events event, QString args)
{
    m_events->startEvent(event,args);
}

int &Game::vSchool(SchoolVar param)
{
    return m_events->vSchool(param);
}

int &Game::vEvent(EventParams param)
{
    return m_events->vEvent(param);
}

int &Game::vQuest(QuestParams param)
{
    return m_events->vQuest(param);
}

bool Game::isHanters()
{
    return m_events->isHanters();
}
//Player funcs:
void Game::newPlayer(CharacterType history)
{
    m_player->newPlayer(history);
}

QString Game::getBoyName()
{
    return m_player->getBoyName();
}

QString Game::getBoy2Name()
{
    return m_player->getBoy2Name();
}

QString Game::getBirthDate()
{
    return m_player->getBirthDate();
}

QString Game::getNameDesc()
{
    return m_player->getNameDesc();
}

QString Game::getBirthDayDesc()
{
    return m_player->getBirthDayDesc();
}

QString Game::getAgesDesc()
{
    return m_player->getAgesDesc();
}

QString Game::getHeightDesc()
{
    return m_player->getHeightDesc();
}

QString Game::getBreastsDesc()
{
    return m_player->getBreastsDesc();
}

QString Game::getLipsDesc()
{
    return m_player->getLipsDesc();
}

QString Game::getThroatDesc()
{
    return m_player->getThroatDesc();
}

QString Game::getVaginaDesc()
{
    return m_player->getVaginaDesc();
}

QString Game::getAnusDesc()
{
    return m_player->getAnusDesc();
}

QString Game::getBodyDesc()
{
    return m_player->getBodyDesc();
}

QString Game::getBodyTypeFigureDesc()
{
    return m_player->getBodyTypeFigureDesc();
}

QString Game::getHairDesc()
{
    return m_player->getHairDesc();
}

QString Game::getPubisDesc()
{
    return m_player->getPubisDesc();
}

QString Game::getSkinDesc()
{
    return m_player->getSkinDesc();
}

QString Game::getEyeDesc()
{
    return m_player->getEyeDesc();
}

QString Game::getMakeupDesc()
{
    return m_player->getMakeupDesc();
}

QString Game::getLegsDesc()
{
    return m_player->getLegsDesc();
}

QString Game::getShamelessDesc()
{
    return m_player->getShamelessDesc();
}

QString Game::getVneshDesc()
{
    return m_player->getVneshDesc();
}

QString Game::getCurClothName()
{
    return m_player->getCurClothName();
}

QString Game::getPlayerFace()
{
    return m_player->getPlayerFace();
}

QPixmap Game::getPlayerIcon()
{
    return m_player->getPlayerIcon();
}

QString Game::getPlayerBody()
{
    return m_player->getPlayerBody();
}

QString Game::getPlayerVagina()
{
    return m_player->getPlayerVagina();
}

QString Game::getPlayerAnus()
{
    return m_player->getPlayerAnus();
}

QString Game::getPlayerPubis()
{
    return m_player->getPlayerPubis();
}

QString Game::getPlayerClothes()
{
    return m_player->getPlayerClothes();
}

QString Game::getPlayerBreasts()
{
    return m_player->getPlayerBreasts();
}

void Game::setBoyName(QString name)
{
    m_player->setBoyName(name);
}

void Game::setBoy2Name(QString name)
{
    m_player->setBoy2Name(name);
}

int Game::getAge()
{
    return m_player->getAge();
}

void Game::calcShamelessFlag()
{
    m_player->calcShamelessFlag();
}

void Game::updBody()
{
    m_player->updBody();
}

bool Game::isPanties()
{
    return m_player->isPanties();
}

bool Game::isSkirt()
{
    return m_player->isSkirt();
}

bool Game::isGlamour()
{
    return m_player->isGlamour();
}

bool Game::isJeans()
{
    return m_player->isJeans();
}

bool Game::isNude()
{
    return m_player->isNude();
}

bool Game::isCloth()
{
    return m_player->isCloth();
}

Cloth *Game::getCloth(ClothType type)
{
    return m_player->getCloth(type);
}

void Game::decreaseClothCond(int value)
{
    m_player->decreaseCondition(value);
}

int Game::getClothGroup()
{
    return m_player->getClothGroup();
}

void Game::redress(ClothType type, Cloth *newCloth)
{
    m_player->redress(type, newCloth);
}

void Game::redressOld()
{
    m_player->redressOld();
}

void Game::storeOldToWardrobe()
{
    m_player->storeOldToWardrobe();
}

void Game::wearClothes(Cloth *thing)
{
    m_player->wearClothes(thing);
}

int &Game::vSkill(Skills skill)
{
    return m_player->vSkill(skill);
}

int &Game::vBody(Body param)
{
    return m_player->vBody(param);
}

int &Game::vStatus(Status param)
{
    return m_player->vStatus(param);
}

int &Game::vSex(SexVar param)
{
    return m_player->vSex(param);
}

int &Game::vStatistics(SC param)
{
    return m_player->vStatistics(param);
}

int &Game::vSick(Sickness param)
{
    return m_player->vSick(param);
}

int &Game::vAddict(Addiction param)
{
    return m_player->vAddict(param);
}

int &Game::vJob(JobStatus param)
{
    return m_player->vJob(param);
}

int &Game::vBuzzer(budilnik param)
{
    return m_player->vBuzzer(param);
}

int Game::vConst(Const param)
{
    return m_player->vConst(param);
}

int &Game::vRep(LocId param)
{
    return m_player->vRep(param);
}

void Game::updSkin(char c, int value)
{
    m_player->updSkin(c,value);
}

void Game::checkPanties()
{
    m_player->checkPanties();
}

QString Game::getName()
{
    return m_player->getName();
}

QString Game::getLipTalk()
{
    return m_player->getLipTalk();
}

QString Game::getLipTalk2()
{
    return m_player->getLipTalk2();
}

QString Game::getLipTalk3()
{
    return m_player->getLipTalk3();
}

QString Game::getThroattipe()
{
    return m_player->getThroattipe();
}

QString Game::getVaginaTipe1()
{
    return m_player->getVaginaTipe1();
}

QString Game::getVaginaTipe2()
{
    return m_player->getVaginaTipe2();
}

QString Game::getVaginaTipe3()
{
    return m_player->getVaginaTipe3();
}

QString Game::getAnusTipe()
{
    return m_player->getAnusTipe1();
}

QString Game::getAnusTipe2()
{
    return m_player->getAnusTipe2();
}

QString Game::getAnusTipe3()
{
    return m_player->getAnusTipe3();
}

bool Game::isEstrus()
{
    return m_preg.isEstrus();
}

QString Game::getPFName()
{
    return m_player->getPFName();
}

//Preegnancy

int &Game::vPreg(PregVar param)
{
    return m_player->vPreg(param);
}

void Game::slotMenstruus()
{
    m_preg.slotMenstruus();
}

void Game::slotEstrus()
{
    m_preg.slotEstrus();
}

void Game::slotIncreaseRiscs(int value)
{
    m_preg.slotIncreaseRiscs(value);
}

void Game::slotPregRecalc()
{
    m_preg.slotPregRecalc();
}

void Game::slotRiscsUpdate()
{
    m_preg.slotRiscsUpdate();
}

bool Game::condomDef()
{
    return m_preg.condomDef();
}

void Game::chanceOfPreg()
{
    m_preg.chanceOfPregnancy();
}

bool Game::PregVisibility()
{
    return m_preg.PregVisibility();
}

QString Game::repDesc()
{
    return m_rep.repDesc();
}

int Game::repGet()
{
    return m_rep.repGet();
}

void Game::setMapAwailable(bool status)
{
    ((MainWindow*)m_window)->ui->pushButtonMap->setEnabled(status);
}

void Game::setCurrentPage(int id)
{
    ((MainWindow*)m_window)->ui->stackedWidget->setCurrentIndex(id);
}

LocId Game::getCurLoc()
{
    return m_locs->getCurLoc();
}

LocId Game::getMainLoc()
{
    return m_locs->getMainLoc();
}

LocId Game::getPrevLoc()
{
    return m_locs->getPrevLoc();
}

Location *Game::getCurPtr()
{
    return m_locs->getCurPtr();
}

void Game::changeLoc(LocId id, int time, QString arg)
{
    m_locs->slotChangeLoc(id,time,arg);
}

Location *Game::getLocPtr(LocId locId)
{
    return m_locs->getLocPtr(locId);
}

void Game::checkMapAwailable()
{
    m_locs->checkMapAwailable();
}

void Game::eat(QString foodtype, QString image, QString text)
{
    m_locs->eat(foodtype,image,text);
}

void Game::drink(QString napitokType)
{
    m_locs->drink(napitokType);
}

void Game::walk()
{
    m_locs->walk();
}

void Game::undress(int arg)
{
    m_locs->undress(arg);
}

void Game::sunbathe(int isCream)
{
    m_locs->sunbathe(isCream);
}

void Game::cream()
{
    m_locs->cream();
}

void Game::swim()
{
    m_locs->swim();
}

void Game::getDressed(int arg)
{
    m_locs->getDressed(arg);
}

void Game::kitchenActsAll(int arg)
{
    m_locs->kitchenActsAll(arg);
}

void Game::drinkAll()
{
    m_locs->drinkAll();
}

void Game::cookies()
{
    m_locs->cookies();
}

void Game::fatDel()
{
    m_locs->fatDel();
}

void Game::vitamin()
{
    m_locs->vitamin();
}

void Game::pills()
{
    m_locs->pills();
}

void Game::icecream()
{
    m_locs->icecream();
}

void Game::coffee()
{
    m_locs->coffee();
}

void Game::read_porn()
{
    m_locs->read_porn();
}

void Game::crossing(int arg)
{
    m_locs->crossing(arg);
}

void Game::home_workout()
{
    m_locs->home_workout();
}

void Game::lokerchoice()
{
    m_locs->lokerchoice();
}

void Game::sitrobrd()
{
    m_locs->sitrobrd();
}

void Game::sitrskakd()
{
    m_locs->sitrskakd();
}

void Game::sitrpressd()
{
    m_locs->sitrpressd();
}

void Game::sitrpushd()
{
    m_locs->sitrpushd();
}

void Game::watch_tv_on_sofa()
{
    m_locs->watch_tv_on_sofa();
}

void Game::run_competition(QString arg)
{
    m_locs->run_competition(arg);
}

void Game::fancywork()
{
    m_locs->fancywork();
}

bool Game::check_inhome()
{
    return m_locs->check_inhome();
}

int Game::getClothDecreaseLevel()
{
    return m_locs->getClothDecreaseLevel();
}

void Game::fnSport(int arg)
{
    m_locs->fnsport(arg);
}

void Game::waiting(int arg)
{
    m_locs->waiting(arg);
}

void Game::cardInit(int count, int min)
{
    m_locs->init(count,min);
}

int Game::cardCheck()
{
    return m_locs->check();
}

int Game::getCardTime()
{
    return m_locs->getCardTime();
}

int Game::getCardHorny()
{
    return m_locs->getCardHorny();
}

QString Game::getCard()
{
    return m_locs->getCard();
}

void Game::selfPlayStart()
{
    m_sex->selfPlayStart();
}

void Game::cum(QString target)
{
    m_sex->cum(target);
}

void Game::sexStart()
{
    m_sex->sexStart();
}

void Game::analStart(ToolType type)
{
    m_sex->analStart(type);
}

void Game::vaginal(ToolType type, QString pos)
{
    m_sex->vaginal(type, pos);
}

void Game::anal(ToolType type)
{
    m_sex->anal(type);
}

void Game::sex_cum()
{
    m_sex->sex_cum();
}

void Game::blow_job()
{
    m_sex->blow_job();
}

void Game::anal_cum()
{
    m_sex->anal_cum();
}

void Game::fnswallow()
{
    m_sex->fnswallow();
}

void Game::dp_start()
{
    m_sex->dp_start();
}

void Game::double_penetration()
{
    m_sex->double_penetration();
}

QString Game::sextToysBlock(int arg)
{
    return m_ccsex.sextToysBlock(arg);
}

int Game::getVaginaDampness()
{
    return m_ccsex.getVaginaDampness();
}

int Game::calc_rubb(QString holeType)
{
    return m_ccsex.calc_rubb(holeType);
}

void Game::antiRubbing()
{
    m_ccsex.antiRubbing();
}

int Game::getVagDamp()
{
    return m_ccsex.getVagDamp();
}

void Game::calcRubbing()
{
    return m_ccsex.slotCalcRubbing();
}

void Game::vagGelTouch()
{
    m_ccsex.slotVagGelTouch();
}

void Game::decRubbing(Body holeType)
{
    m_ccsex.slotDecRubbing(holeType);
}

void Game::sexCorrector()
{
    m_ccsex.slotSexCorrector();
}

void Game::setGape(Body holeType, int horny, int dick, int silavag)
{
    m_ccsex.slotSetGape(holeType,horny,dick,silavag);
}

void Game::viewObj(QString objName)
{
    m_objs->slotViewObj(objName);
}

Cloth *Game::wearCloth(Cloth *thing)
{
    return m_objs->wearCloth(thing);
}

void Game::storeCloth(Cloth *thing, int count)
{
    m_objs->storeCloth(thing,count);
}

void Game::removeCloth(ClothGroup group)
{
    m_objs->removeCloth(group);
}

ClothMain *Game::addRandCloth(ClothGroup group)
{
    return m_objs->addRandDress(group);
}

void Game::sleep()
{
    m_objs->sleep();
}

QString Game::getBookName(int id)
{
    return m_objs->getBookName(id);
}

void Game::readOnWalk()
{
    m_objs->readOnWalk();
}

int Game::eroReaded()
{
    m_objs->eroReaded();
}

void Game::eroBlock()
{
    m_objs->eroBlock();
}

NPC &Game::gNPC(int id)
{
    return m_npc->gNPC(id);
}

QString Game::getNpcTex(int id)
{
    return m_npc->getNpcTex(id);
}

QString Game::getNpcLink(int id)
{
    return m_npc->getNpcLink(id);
}

QString Game::getNpcGroup(int id)
{
    return m_npc->getNpcGroup(id);
}

QString Game::makeNpcGroup(int group)
{
    m_npc->makeNpcGroup(group);
}

int Game::getAvgRelation(npcGroup group)
{
    return m_npc->getAvgRelation(group);
}

void Game::rendRealationList()
{
    m_npc->rendRealationList();
}

void Game::rendNpcProfile(NPCId id)
{
    m_npc->rendNpcProfile(id);
}

void Game::changeRep(char act, int id, int val, int cup, bool msgShow)
{
    m_npc->changeRep(act,id,val,cup,msgShow);
}

void Game::fnAlko(int val)
{
    m_ccalko.fnAlko(val);
}

void Game::anti_hangover()
{
    m_ccalko.anti_hangover();
}



void Game::alkoAbstain()
{
    m_ccalko.alkoAbstain();
}

int Game::alkoBlock()
{
    return m_ccalko.alkoBlock();
}

void Game::slotDataInitAlko()
{
    m_ccalko.slotDataInitAlko();
}

void Game::slotHangOver()
{
    m_ccalko.slotHangOver();
}

void Game::slotAlkoholism()
{
    m_ccalko.slotAlkoholism();
}

void Game::ability(Body holeType, int value)
{
    m_ccsex.ability(holeType,value);
}

void Game::setStatus(int type)
{
    m_drugs->setStatus(type);
}

void Game::setValues()
{
    m_drugs->setValues();
}

void Game::hourRecalc()
{
    m_drugs->hourRecalc();
}

bool Game::drugBlock()
{
    return m_drugs->drugBlock();
}

bool Game::isMesec()
{
    return m_preg.isMesec();
}

bool Game::isPregnant()
{
    return m_preg.isPregnancy();
}
