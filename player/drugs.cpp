#include "drugs.h"
#include "../Functions.h"
#include "../game.h"

Drugs::Drugs(Game *ptr): root(ptr) {}

void Drugs::setStatus(int type)
{
    root->vAddict(drugType) = type;
    root->vAddict(drugStatus) += 100;

    if(root->vAddict(drugType) == 1 && root->vAddict(drugStatus) >= 100)
        root->startEvent(eGameOver,"6");
    else
        root->vAddict(drugStatus) = 100;

    if(getRandInt(0,10) % 5 == 0)
        root->vAddict(drugEffect) =1;
    else
        root->vAddict(drugEffect) = 0;

    if(root->vAddict(drugEffect) == 0)
        root->vStatus(mood) += getRandInt(50,80);
    else
        root->vStatus(mood) += getRandInt(10,20);

    if(root->vAddict(drugType) == 0)
        root->vStatus(energy) -= getRandInt(10,20);
    else
        root->vAddict(drugAddict) += 1;
}

void Drugs::setValues()
{
    if(root->vAddict(drugStatus) > 50 && root->vAddict(drugStatus) <= 75)
    {
        if(root->vAddict(drugType) == 0)
        {
            if(root->vStatus(mood) > 80)
                root->vStatus(mood) = 80;
            if(root->vStatus(horny) > 80)
                root->vStatus(horny) = 80;
        }
        else
        {
            if(root->vStatus(mood) > 60)
                root->vStatus(mood) = 60;
            if(root->vStatus(horny) > 60)
                root->vStatus(horny) =60;
        }
    }
    else if (root->vAddict(drugStatus) > 25 && root->vAddict(drugStatus) <= 50)
    {
        if(root->vAddict(drugType) == 0)
        {
            if(root->vStatus(mood) > 60)
                root->vStatus(mood) = 60;
            if(root->vStatus(horny) > 40)
                root->vStatus(horny) = 40;
        }
        else
        {
            if(root->vStatus(mood) > 10)
                root->vStatus(mood) = 10;
            root->vStatus(horny) = 0;
            root->vStatus(lust) = 0;
        }
    }
    else if(root->vAddict(drugStatus) > 0 && root->vAddict(drugStatus) <= 25)
    {
        if(root->vAddict(drugType) == 0)
        {
            if(root->vStatus(mood) > 70)
                root->vStatus(mood) = 70;
            if(root->vStatus(horny) > 40)
                root->vStatus(horny) = 40;
        }
        else
        {
            if(root->vStatus(mood) > 30)
                root->vStatus(mood) = 30;
            root->vStatus(horny) =0;
            root->vStatus(lust) =0;
        }
    }
    if(root->vAddict(drugStatus) < 0)
        root->vAddict(drugStatus) = 0;
    if(root->vAddict(drugAddict) > 20 && root->vStatus(mood) >= 10)
        root->vStatus(mood) = 9;

}

void Drugs::hourRecalc()
{
    if(root->vAddict(drugStatus) <= 0)
        return;
    if(root->vAddict(drugType) == 0)
        root->vAddict(addictTime) = 16;
    else
    {
        if(root->vAddict(drugStatus) > 25 && root->vAddict(drugStatus) <= 50)
        {
            root->vAddict(_addict) = root->vAddict(drugAddict) / 5;
            if(root->vAddict(_addict) > 5)
                root->vAddict(_addict) = 5;
            root->vAddict(addictTime) = 12 - root->vAddict(_addict);
            root->vStatus(health) += -1;
            root->vStatus(mood) += getRandInt(root->vAddict(_addict), 3*(root->vAddict(_addict) + 1));
        }
        else
            root->vAddict(addictTime) =16;
    }
    root->vAddict(drugStatus) += -root->vAddict(addictTime);
}

bool Drugs::drugBlock()
{
    if((root->vAddict(drugAddict) > 20 && root->vAddict(drugStatus) < 75) || (root->vAddict(drugStatus) > 0 && root->vAddict(drugStatus) < 75))
        return true;
    else
        return false;
}
