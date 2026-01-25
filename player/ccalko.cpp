#include "ccalko.h"
#include "../Functions.h"
#include "../game.h"

CC_Alko::CC_Alko(Game *ptr): root(ptr){}

void CC_Alko::anti_hangover()
{
    root->vAddict(hangoverDay) =0;
    root->vAddict(alkoAbstainDay) = root->vStatus(daystart);
    root->vAddict(alkoAbstainCount) =1;
}

void CC_Alko::slotHangOver()
{
    slotDataInitAlko();
    if (root->vAddict(alko) > root->vAddict(maxAlko) && root->vAddict(hangoverDay) == 0)
    {
        emit sigIncreaseRiscs(getRandInt(1,3));
        root->vAddict(hangoverDay) = root->vStatus(daystart) + 1;
    }
    if (root->vAddict(alko) == root->vAddict(maxAlko))
    {
        root->vAddict(hangoverDay) += root->vAddict(max_hangoverDay);
    }
    if (root->vAddict(alko) > root->vAddict(maxAlko))
    {
        root->vAddict(hangoverDay) += root->vAddict(max_hangoverDay) + 1;
    }
    //Опохмелка - увеличиваем алкоголизм
    if (root->vAddict(alko) > 0 && root->vAddict(hangoverDay) != 0 && root->vStatus(daystart) > root->vAddict(lenghangoverday))
    {
        root->vAddict(alkoholism) += 1;
        root->vAddict(hangoverDay) =0;
        root->vAddict(lenghangoverday) = 0;
        root->vStatus(mood) = 100;
        root->vStatus(health) = 100;
    }
    if (root->vStatus(daystart) > root->vAddict(lenghangoverday))
    {
        root->vAddict(hangoverDay) = 0;
        root->vAddict(lenghangoverday) = 0;
    }
    if(root->vAddict(hangoverDay) != 0 && root->vStatus(daystart) >= root->vAddict(lenghangoverday))
    {
        root->vStatus(Status::water) -= 3;
        if (root->vStatus(water) < 8)
        {
            root->vStatus(mood) -= 3;
        }
        if (root->vStatus(mood) < 30)
        {
            root->vStatus(health) -= 3;
        }
    }
    if (root->vAddict(hangoverDay) != 0 && root->vStatus(daystart) >= root->vAddict(hangoverDay))
    {
        root->vStatus(mood) += getRandInt(1,3);
    }
    
}

void CC_Alko::slotAlkoholism()
{
    if (root->vAddict(hangoverDay) != 0)
    {
        root->vAddict(hangVneshAlko) = 3;
    }
    else
    {
        root->vAddict(hangVneshAlko) =0;
    }
    if (root->vAddict(alkoholism) > 45)
    {
        root->vStatus(vneshAlko) = 10 + root->vAddict(hangVneshAlko);
    }
    else if (root->vAddict(alkoholism) > 35)
    {
        root->vStatus(vneshAlko) = 7 + root->vAddict(hangVneshAlko);
    }
    else if (root->vAddict(alkoholism) > 25)
    {
        root->vStatus(vneshAlko) = 5 + root->vAddict(hangVneshAlko);
    }
    else if (root->vAddict(alkoholism) > 15)
    {
        root->vStatus(vneshAlko) = 3 + root->vAddict(hangVneshAlko);
    }
    else
    {
        root->vStatus(vneshAlko) = root->vAddict(hangVneshAlko);
    }
}

void CC_Alko::slotDataInitAlko()
{
    if (root->vAddict(alkoholism) > 45)
    {
        root->vAddict(maxAlko) = 4;
        root->vAddict(max_hangoverDay) = 3;
    }
    else if (root->vAddict(alkoholism) > 35)
    {
        root->vAddict(maxAlko) = 6;
        root->vAddict(max_hangoverDay) =2;
    }
    else if (root->vAddict(alkoholism) > 25)
    {
        root->vAddict(maxAlko) = getRandInt(6,8);
        root->vAddict(max_hangoverDay) = getRandInt(1,2);
    }
    else if (root->vAddict(alkoholism) > 15)
    {
        root->vAddict(maxAlko) = 8;
        root->vAddict(max_hangoverDay) =1;
    }
    else
    {
        root->vAddict(maxAlko) = 12;
        root->vAddict(max_hangoverDay) = 0;
    }    
}

void CC_Alko::alkoAbstain()
{
    if (root->vAddict(alkoholism) <= 0)
    {
        root->vAddict(alkoholism) =0;
        root->vAddict(alkoAbstainDay) =0;
        return;
    }
    if (root->vAddict(alko) == 0 && root->vAddict(hangoverDay) == 0 && root->vAddict(alkoAbstainDay) == 0)
    {
        root->vAddict(alkoAbstainDay) = root->vStatus(daystart);
        root->vAddict(alkoAbstainCount) = 1;
        return;
    }
    if (root->vAddict(alko) != 0 || root->vAddict(hangoverDay) != 0)
    {
        root->vAddict(alkoAbstainDay) = 0;
        root->vAddict(alkoAbstainCount) = 0;
    }
    if (root->vAddict(alkoAbstainCount) != 0 && root->vStatus(daystart) >= root->vAddict(alkoAbstainDay) + 3)
    {
        if (root->vAddict(alko) != 0 && root->vAddict(hangoverDay) != 0)
        {
            root->vAddict(alkoAbstainDay) = 0;
            return;
        }
        root->vAddict(alkoholism) += -getRandInt(0,1);
        root->vAddict(alkoAbstainDay) = root->vStatus(daystart);
    }    
}

void CC_Alko::fnAlko(int val)
{
    root->vStatus(frost) = 0;
    root->incTime(getRandInt(5,15));
    root->vStatus(mood) += 10*val;
    root->vStatus(cumLips) = 0;
    if(val <= 0)
        root->vAddict(alko) += 1;
    else
        root->vAddict(alko) += val;
    if(root->vStatus(energy) > 20)
        root->vStatus(day_weight) += 1;
    if(val > 2)
        root->updSkin('-',1);
    if(root->vAddict(alko) >= 6)
        root->vStatus(vidageday) -= 1;
}

int CC_Alko::alkoBlock()
{
    qDebug() << "alko :" << root->vAddict(alko) << root->vAddict(maxAlko);
    if (root->vAddict(alko) >= root->vAddict(maxAlko))
    {
        return 1;
    }
    else if (root->vAddict(hangoverDay) != 0)
    {
        return 2;
    }
    else if (root->vAddict(alkoholism) > 15)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
