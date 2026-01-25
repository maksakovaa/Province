#include "locationhandler.h"
#include "location_headers.h"
#include "loc_enums.h"
#include "../game.h"

LocationHandler::LocationHandler(Game *parent):
    root(parent)
{
    m_current = nullptr;
    genLocations();
    m_kitchenActs = new KitchenActs(root);
    m_common = new Common(root);
    m_beach = new Beach(root);
}

void LocationHandler::genLocations()
{
    std::vector<Location*> locs;
    //////////////  Common
    locs.push_back(new BathRoom(root));
    locs.push_back(new Shop(root));
    //////////////  Gadukino
    locs.push_back(new Backwater(root));
    locs.push_back(new Gadbana(root));
    locs.push_back(new Gadbeach(root));
    locs.push_back(new Gaddvor(root));
    locs.push_back(new Gadfield(root));
    locs.push_back(new Gadforest(root));
    locs.push_back(new GadForestSwamp(root));
    locs.push_back(new Gadgarden(root));
    locs.push_back(new Gadhouse(root));
    locs.push_back(new Gadmarket(root));
    locs.push_back(new Gadriver(root));
    locs.push_back(new Gadroad(root));
    locs.push_back(new Gadsarai(root));
    locs.push_back(new Gadukino(root));
    locs.push_back(new Meadow(root));
    locs.push_back(new MiroslavaHome(root));
    locs.push_back(new Swamp(root));
    locs.push_back(new SwampHouse(root));
    locs.push_back(new SwampSpring(root));
    locs.push_back(new SwampYard(root));
    /////////////   Pavlovo
    locs.push_back(new korrPar(root));
    locs.push_back(new BedrPar(root));
    locs.push_back(new BedrPar2(root));
    for(auto i: locs)
    {
        m_locations[i->getLocId()] = i;
    }
}

void LocationHandler::checkMapAwailable()
{
    if (m_current->isParent() || m_current->getLocId() == lgadukino)
    {
        root->setMapAwailable(false);
    }
    else
    {
        root->setMapAwailable(true);
    }
}

void LocationHandler::slotChangeLoc(LocId id, int time, QString arg)
{
    m_prev = m_current;
    m_current = m_locations[id];
    root->clearActions();
    root->setCurrentPage(0);
    root->incTime(time);

    root->rendImagePage(this);
    m_current->show(arg);
    connect(root->getTextPtr(), &QLabel::linkActivated, m_current, &Location::actionHandler);
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

LocId LocationHandler::getCurLoc()
{
    return m_current->getLocId();
}

Location *LocationHandler::getLocPtr(LocId locId)
{
    return m_locations[locId];
}

void LocationHandler::eat(QString foodtype, QString image, QString text)
{
    m_kitchenActs->eat(foodtype,image,text);
}

void LocationHandler::drink(QString napitokType)
{
    m_kitchenActs->drink(napitokType);
}

void LocationHandler::icecream()
{
    m_common->icecream();
}

void LocationHandler::coffee()
{
    m_common->coffee();
}

void LocationHandler::read_porn()
{
    m_common->read_porn();
}

void LocationHandler::crossing(int arg)
{
    m_common->crossing(arg);
}

void LocationHandler::home_workout()
{
    m_common->home_workout();
}

void LocationHandler::lokerchoice()
{
    m_common->lokerchoice();
}

void LocationHandler::sitrobrd()
{
    m_common->sitrobrd();
}

void LocationHandler::sitrskakd()
{
    m_common->sitrskakd();
}

void LocationHandler::sitrpressd()
{
    m_common->sitrpressd();
}

void LocationHandler::sitrpushd()
{
    m_common->sitrpushd();
}

void LocationHandler::watch_tv_on_sofa()
{
    m_common->watch_tv_on_sofa();
}

void LocationHandler::run_competition(QString arg)
{
    m_common->run_competition(arg);
}

void LocationHandler::fancywork()
{
    m_common->fancywork();
}

bool LocationHandler::check_inhome()
{
    return m_common->check_inhome();
}

void LocationHandler::wet_wipes()
{
    m_common->wet_wipes();
}

int LocationHandler::getClothDecreaseLevel()
{
    return m_common->getClothDecreaseLevel();
}

void LocationHandler::fnsport(int arg)
{
    m_common->fnsport(arg);
}

void LocationHandler::waiting(int arg)
{
    m_common->waiting(arg);
}

void LocationHandler::init(int count, int min)
{
    m_card.init(count,min);
}

int LocationHandler::check()
{
    return m_card.check();
}

int LocationHandler::getCardTime()
{
    return m_card.getCardTime();
}

int LocationHandler::getCardHorny()
{
    return m_card.getCardHorny();
}

QString LocationHandler::getCard()
{
    return m_card.getCard();
}

void LocationHandler::walk()
{
    m_beach->walk();
}

void LocationHandler::undress(int arg)
{
    m_beach->undress(arg);
}

void LocationHandler::sunbathe(int isCream)
{
    m_beach->sunbathe(isCream);
}

void LocationHandler::cream()
{
    m_beach->cream();
}

void LocationHandler::swim()
{
    m_beach->swim();
}

void LocationHandler::getDressed(int arg)
{
    m_beach->getDressed(arg);
}

void LocationHandler::drinkAll()
{
    m_kitchenActs->drink_all();
}

void LocationHandler::cookies()
{
    m_kitchenActs->cookie();
}

void LocationHandler::fatDel()
{
    m_kitchenActs->fatdel();
}

void LocationHandler::vitamin()
{
    m_kitchenActs->vitamin();
}

void LocationHandler::pills()
{
    m_kitchenActs->pills();
}
