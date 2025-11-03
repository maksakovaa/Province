#include "ccalko.h"
#include "../Functions.h"

void CC_Alko::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
}

void CC_Alko::slotCheckAlkoBlock(int& value)
{
    if (getVAlco(alko) >= getVAlco(maxAlko))
    {
        value = 1;
    }
    else if (getVAlco(hangoverDay) != 0)
    {
        value = 2;
    }
    else if (getVAlco(alkoholism) > 15)
    {
        value = 3;
    }
    else
    {
        value = 0;
    }
}

void CC_Alko::anti_hangover()
{
    setVAlco(hangoverDay,0);
    setVAlco(alkoAbstainDay, getVStatus(daystart));
    setVAlco(alkoAbstainCount,1);
}

void CC_Alko::slotHangOver()
{
    slotDataInitAlko();
    if (getVAlco(alko) > getVAlco(maxAlko) && getVAlco(hangoverDay) == 0)
    {
        emit sigIncreaseRiscs(getRandInt(1,3));
        setVAlco(hangoverDay, getVStatus(daystart) + 1);
    }
    if (getVAlco(alko) == getVAlco(maxAlko))
    {
        updVAlco(hangoverDay, getVAlco(max_hangoverDay));
    }
    if (getVAlco(alko) > getVAlco(maxAlko))
    {
        updVAlco(hangoverDay, getVAlco(max_hangoverDay) + 1);
    }
    //Опохмелка - увеличиваем алкоголизм
    if (getVAlco(alko) > 0 && getVAlco(hangoverDay) != 0 && getVStatus(daystart) > getVAlco(lenghangoverday))
    {
        updVAlco(alkoholism, 1);
        setVAlco(hangoverDay,0);
        setVAlco(lenghangoverday,0);
        setVStatus(mood, 100);
        setVStatus(health, 100);
    }
    if (getVStatus(daystart) > getVAlco(lenghangoverday))
    {
        setVAlco(hangoverDay, 0);
        setVAlco(lenghangoverday,0);
    }
    if(getVAlco(hangoverDay) != 0 && getVStatus(daystart) >= getVAlco(lenghangoverday))
    {
        updVStatus(Status::water, -3);
        if (getVStatus(Status::water) < 8)
        {
            updVStatus(Status::mood, -3);
        }
        if (getVStatus(Status::mood) < 30)
        {
            updVStatus(Status::health, -3);
        }
    }
    if (getVAlco(hangoverDay) != 0 && getVStatus(daystart) >= getVAlco(hangoverDay))
    {
        updVStatus(Status::mood, getRandInt(1,3));
    }
    
}

void CC_Alko::slotAlkoholism()
{
    if (getVAlco(hangoverDay) != 0)
    {
        setVAlco(hangVneshAlko, 3);
    }
    else
    {
        setVAlco(hangVneshAlko,0);
    }
    if (getVAlco(alkoholism) > 45)
    {
        setVStatus(vneshAlko, 10 + getVAlco(hangVneshAlko));
    }
    else if (getVAlco(alkoholism) > 35)
    {
        setVStatus(vneshAlko, 7 + getVAlco(hangVneshAlko));
    }
    else if (getVAlco(alkoholism) > 25)
    {
        setVStatus(vneshAlko, 5 + getVAlco(hangVneshAlko));
    }
    else if (getVAlco(alkoholism) > 15)
    {
        setVStatus(vneshAlko, 3 + getVAlco(hangVneshAlko));
    }
    else
    {
        setVStatus(vneshAlko, getVAlco(hangVneshAlko));
    }
}

int CC_Alko::getVAlco(Addiction param)
{
    return m_player->getVAddict(param);
}

void CC_Alko::setVAlco(Addiction param, int value)
{
    m_player->setVAddict(param, value);
}

void CC_Alko::updVAlco(Addiction param, int value)
{
    m_player->updVAddict(param,value);
}

void CC_Alko::slotDataInitAlko()
{
    if (getVAlco(alkoholism) > 45)
    {
        setVAlco(maxAlko, 4);
        setVAlco(max_hangoverDay, 3);
    }
    else if (getVAlco(alkoholism) > 35)
    {
        setVAlco(maxAlko, 6);
        setVAlco(max_hangoverDay,2);
    }
    else if (getVAlco(alkoholism) > 25)
    {
        setVAlco(maxAlko, getRandInt(6,8));
        setVAlco(max_hangoverDay, getRandInt(1,2));
    }
    else if (getVAlco(alkoholism) > 15)
    {
        setVAlco(maxAlko, 8);
        setVAlco(max_hangoverDay,1);
    }
    else
    {
        setVAlco(maxAlko, 12);
        setVAlco(max_hangoverDay, 0);
    }    
}

int CC_Alko::getVStatus(Status param)
{
    return m_player->getVStatus(param);
}

void CC_Alko::updVStatus(Status param, int value)
{
    m_player->updVStatus(param, value);
}

void CC_Alko::setVStatus(Status param, int value)
{
    m_player->setVStatus(param, value);
}

void CC_Alko::alkoAbstain()
{
    if (getVAlco(alkoholism) <= 0)
    {
        setVAlco(alkoholism,0);
        setVAlco(alkoAbstainDay,0);
        return;
    }
    if (getVAlco(alko) == 0 && getVAlco(hangoverDay) == 0 && getVAlco(alkoAbstainDay) == 0)
    {
        setVAlco(alkoAbstainDay, getVStatus(daystart));
        setVAlco(alkoAbstainCount, 1);
        return;
    }
    if (getVAlco(alko) != 0 || getVAlco(hangoverDay) != 0)
    {
        setVAlco(alkoAbstainDay, 0);
        setVAlco(alkoAbstainCount, 0);
    }
    if (getVAlco(alkoAbstainCount) != 0 && getVStatus(daystart) >= getVAlco(alkoAbstainDay) + 3)
    {
        if (getVAlco(alko) != 0 && getVAlco(hangoverDay) != 0)
        {
            setVAlco(alkoAbstainDay, 0);
            return;
        }
        updVAlco(alkoholism, -getRandInt(0,1));
        setVAlco(alkoAbstainDay, daystart);
    }    
}
