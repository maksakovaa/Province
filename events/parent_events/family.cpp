#include "family.h"
#include "../eventhandler.h"

Family::Family(EventHandler* parent): root(parent) {}

void Family::start(QString arg)
{
    if(arg == "checkTrip")
        checkTrip();
    if(arg == "mother_sheduler")
        mother_sheduler();
    if(arg == "father_sheduler")
        father_sheduler();
    if(arg == "sister_sheduler")
        sister_sheduler();
    if(arg == "brother_sheduler")
        brother_sheduler();
    if(arg == "mother_act")
        mother_act();
    if(arg == "father_act")
        father_act();
    if(arg == "brother_act")
        brother_act();
    if(arg == "sister_act")
        sister_act();
}

void Family::checkTrip()
{
    int trip_month = root->gVEvent(family_trip_month);
    int month = root->getMonth();
    int week = root->getWeekNum();
    if(trip_month == month || (trip_month != month && week > 0 && week < 6) || (trip_month != month && week == 6 && root->getHour() < 12))
    {
        root->sVEvent(family_trip, 0);
    }
    else
    {
        if(week == 0 /*&& Mother location == gadhouse*/)
        {
            root->sVEvent(family_trip_month,month);
            root->sVEvent(family_trip,1);
        }
    }
}

void Family::mother_sheduler()
{
    checkTrip();
    if(root->gVEvent(family_trip) == 0)
    {

    }
}

void Family::father_sheduler()
{
    checkTrip();
}

void Family::sister_sheduler()
{
    checkTrip();
}

void Family::brother_sheduler()
{
    checkTrip();
}

void Family::mother_act()
{

}

void Family::father_act()
{

}

void Family::brother_act()
{

}

void Family::sister_act()
{

}

