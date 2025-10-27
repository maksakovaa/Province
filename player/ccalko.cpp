#include "ccalko.h"
#include "../Functions.h"

void CC_Alko::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
}

void CC_Alko::slotCheckAlkoBlock(int& value)
{
    if (getVStatus(alko) >= getVStatus(maxAlko))
    {
        value = 1;
    }
    else if (m_hangoverDay != 0)
    {
        value = 2;
    }
    else if (m_alkoholism > 15)
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
    int dayStart = 0;
    m_hangoverDay = 0;
    m_alkoAbstainDay = dayStart;
    m_alkoAbstainCount = 1;
    //Возврат в сумку 
}

void CC_Alko::slotHangOver()
{
    slotDataInitAlko();
    if (getVStatus(alko) > getVStatus(maxAlko) && m_hangoverDay == 0)
    {
        emit sigIncreaseRiscs(getRandInt(1,3));
        int daystart = getVStatus(Status::daystart);
        m_hangoverDay = daystart + 1;
    }
    if (getVStatus(alko) == getVStatus(maxAlko))
    {
        m_hangoverDay = m_hangoverDay + m_max_hangoverDay;
    }
    if (getVStatus(alko) > getVStatus(maxAlko))
    {
        m_hangoverDay = m_hangoverDay + m_max_hangoverDay + 1;
    }
    //Опохмелка - увеличиваем алкоголизм
    if (getVStatus(alko) > 0 && m_hangoverDay != 0 && daystart > m_lenghangoverday)
    {
        m_alkoholism += 1;
        m_hangoverDay = 0;
        m_lenghangoverday = 0;
        setVStatus(mood, 100);
        setVStatus(health, 100);
    }
    if (daystart > m_lenghangoverday)
    {
        m_hangoverDay = 0;
        m_lenghangoverday = 0;
    }
    if(m_hangoverDay != 0 && daystart >= m_lenghangoverday)
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
    if (m_hangoverDay != 0 && daystart >= m_hangoverDay)
    {
        updVStatus(Status::mood, getRandInt(1,3));
    }
    
}

void CC_Alko::slotAlkoholism()
{
    if (m_hangoverDay != 0)
    {
        m_hangVneshAlko = 3;
    }
    else
    {
        m_hangVneshAlko = 0;
    }
    if (m_alkoholism > 45)
    {
        setVStatus(vneshAlko, 10 + m_hangVneshAlko);
    }
    else if (m_alkoholism > 35)
    {
        setVStatus(vneshAlko, 7 + m_hangVneshAlko);
    }
    else if (m_alkoholism > 25)
    {
        setVStatus(vneshAlko, 5 + m_hangVneshAlko);
    }
    else if (m_alkoholism > 15)
    {
        setVStatus(vneshAlko, 3 + m_hangVneshAlko);
    }
    else
    {
        setVStatus(vneshAlko, m_hangVneshAlko);
    }
}

void CC_Alko::slotDataInitAlko()
{
    if (m_alkoholism > 45)
    {
        setVStatus(maxAlko, 4);
        m_max_hangoverDay = 3;
    }
    else if (m_alkoholism > 35)
    {
        setVStatus(maxAlko, 6);
        m_max_hangoverDay = 2;
    }
    else if (m_alkoholism > 25)
    {
        setVStatus(maxAlko, getRandInt(6,8));
        m_max_hangoverDay = getRandInt(1,2);
    }
    else if (m_alkoholism > 15)
    {
        setVStatus(maxAlko, 8);
        m_max_hangoverDay = 1;
    }
    else
    {
        setVStatus(maxAlko, 12);
        m_max_hangoverDay = 0;
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
    int daystart = getVStatus(Status::daystart);
    if (m_alkoholism <= 0)
    {
        m_alkoholism = 0;
        m_alkoAbstainDay = 0;
        return;
    }
    if (getVStatus(alko) == 0 && m_hangoverDay == 0 && m_alkoAbstainDay == 0)
    {
        m_alkoAbstainDay = daystart;
        m_alkoAbstainCount = 1;
        return;
    }
    if (getVStatus(alko) != 0 || m_hangoverDay != 0)
    {
        m_alkoAbstainDay = 0;
        m_alkoAbstainCount = 0;
    }
    if (m_alkoAbstainCount != 0 && daystart >= m_alkoAbstainDay + 3)
    {
        if (getVStatus(alko) != 0 && m_hangoverDay != 0)
        {
            m_alkoAbstainDay = 0;
            return;
        }
        m_alkoholism -= getRandInt(0,1);
        m_alkoAbstainDay = daystart;
    }    
}
