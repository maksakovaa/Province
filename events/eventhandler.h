#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QWidget>
#include "questenums.h"
#include "event.h"
#include "eventenums.h"
#include "event_enums.h"
#include <QLabel>
#include <QPushButton>
#include "../locations/location.h"

class Game;
class LocationHandler;
class SaveForm; class LoadForm;

class EventHandler
{
    friend SaveForm; friend LoadForm;
public:
    EventHandler(Game *ptr);
    void startEvent(Events event, QString args = 0);

    int& vSchool(SchoolVar param);
    int& vEvent(EventParams param);
    int& vQuest(QuestParams param);
    bool isHanters();
private:
    void initEvents();
private:
    Game* root;
    std::unordered_map<Events,Event*> m_events;
    std::unordered_map<EventParams,int> m_eventval;
    std::unordered_map<QuestParams, int> m_questval;
    std::unordered_map<SchoolVar,int> m_schoolVal;
};

#endif // EVENTHANDLER_H
