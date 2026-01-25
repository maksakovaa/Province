#include "eventhandler.h"
#include "EventHeaders.h"

EventHandler::EventHandler(Game* ptr): root(ptr)
{
    initEvents();
}

void EventHandler::startEvent(Events event, QString arg)
{
    m_events[event]->start(arg);
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
    m_eventval[book_in_bag] = -1;
    m_events[eAndreiHanter] = new AndreiHanter(root);
    m_events[eBicycle] = new Bicycle(root);
    m_events[eGadForestEvent] = new GadforestEvent(root);
    m_events[eGadForestLost] = new GadforestLost(root);
    m_events[eGadForestRelax] = new GadforestRelax(root);
    m_events[eGadukinoEvents] = new GadukinoEvent(root);
    m_events[eGrandMa] = new Grandma(root);
    m_events[eGrandMaHelp] = new GrandmaHelp(root);
    m_events[eGrandPa] = new Grandpa(root);
    m_events[eGrandPaHelp] = new GrandpaHelp(root);
    m_events[eGrandParentEvents] = new GrandparentsEvents(root);
    m_events[eHanterSex] = new HanterSex(root);
    m_events[eHanters] = new Hanters(root);
    m_events[eHantersLoveSex] = new HantersLoveSex(root);
    m_events[eIgorHanter] = new IgorHanter(root);
    m_events[eMeadowEvent] = new MeadowEvent(root);
    m_events[eMiraFather] = new MiraFather(root);
    m_events[eMiraSex] = new MiraSex(root);
    m_events[eMiroslava] = new Miroslava(root);
    m_events[eMitkaBuhGroup] = new MitkaBuhGroup(root);
    m_events[eMitkaBuh] = new MitkaBuh(root);
    m_events[eMitka] = new Mitka(root);
    m_events[eMitkaSex] = new MitkaSex(root);
    m_events[ePirat] = new Pirat(root);
    m_events[eRiverEvents] = new RiverEvents(root);
    m_events[eSergeiHanter] = new SergeiHanter(root);
    m_events[eSwampEvents] = new SwampEvents(root);

    m_events[eFamily] = new Family(root);
}

int &EventHandler::vSchool(SchoolVar param)
{
    return m_schoolVal[param];
}

int &EventHandler::vEvent(EventParams param)
{
    return m_eventval[param];
}

int &EventHandler::vQuest(QuestParams param)
{
    return m_questval[param];
}

bool EventHandler::isHanters()
{
    return m_eventval[hanters] > 0;
}
