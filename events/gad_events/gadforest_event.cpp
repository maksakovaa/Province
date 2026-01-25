#include "gadforest_event.h"
#include "../../menu/buttons.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../locations/gadukino/gadforest.h"

void GadforestEvent::start(QString arg)
{
    if(arg == "search")
        search();
    if(arg == "clothes1")
        clothes1();
    if(arg == "clothes2")
        clothes2();
    if(arg == "gadforest_lost_start")
        gadforest_lost_start();
    if(arg == "gopforest_mitka")
        gopforest_mitka();
    if(arg == "gopforest_kolyamba")
        gopforest_kolyamba();
    if(arg == "gopforest_vasyan")
        gopforest_vasyan();
    if(arg == "gopforest_2boys")
        gopforest_2boys();
    if(arg == "gopforest_3boys")
        gopforest_3boys();
    if(arg == "nude_event")
        nude_event();
    if(arg == "mushroom_pickers1")
        mushroom_pickers1();
    if(arg == "mushroom_pickers2")
        mushroom_pickers2();
    if(arg == "mushroom_pickers3")
        mushroom_pickers3();
    if(arg == "mushroom")
        mushroom();
    if(arg == "bilberry")
        billberry();
    if(arg == "basket")
        basket();
    if(arg == "picnic")
        picnic();
    if(arg == "forest_hanters")
        forest_hanters();
    if(arg == "forest_road")
        forest_road();
    if(arg == "swamp_road")
        swamp_road();
    if(arg == "lost")
        lost();
    if(arg == "relax")
        relax();
}

void GadforestEvent::search()
{
    root->incTime(30);
    switch (root->vEvent(edge_forestday_current))
    {
    case 1:
    root->vEvent(edge_forestday1) = root->vStatus(daystart);
        break;
    case 2:
    root->vEvent(edge_forestday2) = root->vStatus(daystart);
        break;
    case 3:
    root->vEvent(edge_forestday3) = root->vStatus(daystart);
        break;
    case 4:
    root->vEvent(edge_forestday4) = root->vStatus(daystart);
        break;
    }
    if(root->vEvent(goforest) < 20 * root->vEvent(edge_forestday_current))
        root->vEvent(goforest) += getRandInt(0,1);
    if(root->vEvent(edge_forestday_current) == 1)
    {
        if(root->vEvent(mushroom_pickers) == 0 || root->vEvent(mushroom_pickers) == 2)
        {
            root->vEvent(new_boletus) = getRandInt(0,1);
            root->vEvent(new_bilberry) = 1;
        }
        else
        {
            root->vEvent(new_bilberry) = 0;
            root->vEvent(new_boletus) = getRandInt(0,1);
        }
    }
    if(root->vEvent(edge_forestday_current) == 2)
    {
        if(root->vEvent(mushroom_pickers) < 2)
        {
            root->vEvent(new_boletus) = 1;
            root->vEvent(new_bilberry) = getRandInt(1,2);
        }
        else
        {
            root->vEvent(new_bilberry) = getRandInt(0,1);
            root->vEvent(new_boletus) =1;
        }
    }
    else
    {
        root->vEvent(new_boletus) = getRandInt(1,2);
        if(root->vEvent(edge_forestday_current) == 3)
            root->vEvent(new_bilberry) = getRandInt(1,2);
        else
            root->vEvent(new_bilberry) = getRandInt(2,3);
    }
    root->vStatus(boletus) += root->vEvent(new_boletus);
    root->vStatus(bilberry) += root->vEvent(new_bilberry);
    root->vStatus(mood) +=5;
    if(root->vEvent(new_bilberry) > 0 && root->vEvent(new_boletus) > 0)
    {
        root->vStatus(mood) +=10;
        clothes1();
        root->setText(str(0));
    }
    else if(root->vEvent(new_boletus) == 0 && root->vEvent(new_bilberry) > 0)
    {
        root->vStatus(mood) +=5;
        clothes1();
        root->setText(str(1));
    }
    else
    {
        root->vStatus(mood) +=-5;
        clothes2();
        root->setText(str(2));
    }
    makeActBtn("back_to_loc",act(0));
}

void GadforestEvent::clothes1()
{
    if(root->vEvent(mirainforest) == 0)
    {
        if(!root->isNude())
        {
            if(!root->isSkirt())
                root->setImage(media(1));
            else
                root->setImage(media(2));
        }
        else
            root->setImage(media(3));
    }
    else
        root->setImage(media(4));
}

void GadforestEvent::clothes2()
{
    if(root->vEvent(mirainforest) == 0)
    {
        if(!root->isSkirt())
            root->setImage(media(5));
        else
        {
            if(!root->isNude() && root->isPanties())
                root->setImage(media(6));
            if(!root->isNude() && !root->isPanties())
                root->setImage(media(7));
            if(root->isNude())
                root->setImage(media(8));
        }
    }
    else
    {
        if(root->isNude())
            root->setImage(media(9));
        else
            root->setImage(media(10));
    }
}

void GadforestEvent::gadforest_lost_start()
{
    root->setImage(media(11));
    root->setText(str(3));
    makeActBtn("gadforestlostmain",act(0));
}

void GadforestEvent::gopforest_mitka()
{
    if(!root->isNude())
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) == 0 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(15);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(0));
                root->setText(str(4));
                makeActBtn("gadforest",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(0));
                root->setText(str(5));
                makeActBtn("mitksasex",act(1));
                if(root->vEvent(mitkasextimes) < 11 && root->vAddict(alko) < 6 && root->vStatus(horny) < 70)
                    makeActBtn("gadforest",act(2));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) == 0 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) >= 2 && root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->vEvent(mirainforest) =0;
                    root->setImage(media(0));
                    root->setText(str(6));
                    makeActBtn("gadforest",act(3));
                    makeActBtn("watch_miramitka0",act(4));
                }
                else if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) =root->vStatus(daystart);
                    root->vEvent(mirainforest) =0;
                    root->setImage(media(0));
                    root->setText(str(13));
                    makeActBtn("gadforest",act(3));
                    makeActBtn("watch_miramitka2",act(4));
                }
                else
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) =root->vStatus(daystart);
                    root->setImage(media(0));
                    root->setText(str(17));
                    makeActBtn("gadforest",act(0));
                }
            }
            else if((root->vEvent(mitkasextimes) > 0 && root->vEvent(mitkasextimes) < 13 && root->vEvent(gadriver_gang) < 3)|| (root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3))
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(0));
                root->setText(str(18));
                makeActBtn("mitksasex2",act(1));
                if(root->vEvent(mitkasextimes) < 11 && root->vAddict(alko) < 6 && root->vStatus(horny) < 70)
                    makeActBtn("gadforest",act(2));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->vEvent(mitkasextimes) +=1;
                root->setImage(media(0));
                root->setText(str(19));
                makeActBtn("mitkasex3",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(0));
                root->setText(str(20));
                makeActBtn("gadforest",act(0));
            }

        }
    }
    else
    {
        if(root->vEvent(mirainforest) == 0 || root->vEvent(gadriver_gang) >= 3)
        {
            if(root->vEvent(mitkasextimes) == 0 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                int temp = getRandInt(1,2);
                if(temp == 1)
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(0));
                if(temp == 1)
                    root->setText(str(21));
                if(temp == 2)
                    root->setText(str(22));
                if(temp == 1)
                    makeActBtn("run_and_dress",act(6));
                else
                    makeActBtn("hide",act(7));
                makeActBtn("go_next",act(8));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(0));
                root->setText(str(26));
                makeActBtn("mitkasex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) == 0 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    int temp = getRandInt(1,2);
                    root->setImage(media(0));
                    if(temp == 1)
                        root->setText(str(27));
                    else
                        root->setText(str(22));
                    if(temp == 1)
                    {
                        makeActBtn("run_and_dress2",act(6));
                    }
                    else
                    {
                        makeActBtn("hide2",act(7));
                    }
                }
            }
            else if((root->vEvent(mitkasextimes) > 0 && root->vEvent(mitkasextimes) < 13 && root->vEvent(gadriver_gang) < 3) || (root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3))
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                int temp = getRandInt(1,2);
                root->setImage(media(0));
                if(temp == 1)
                    root->setText(str(30));
                else
                    root->setText(str(22));
                if(temp == 1)
                    makeActBtn("mitksasex2",act(0));
                if(temp == 2)
                {
                    makeActBtn("hide2",act(7));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->vEvent(mitboyrand) =1;
                root->vEvent(mitkaforestsex) =1;
                root->setImage(media(0));
                root->setText(str(31));
                makeActBtn("mitkasex3",act(0));
            }
            else
            {
                root->incTime(15);
                root->setImage(media(0));
                root->setText(str(22));
                makeActBtn("hide2",act(7));
            }
        }
    }
}

void GadforestEvent::gopforest_kolyamba()
{
    if(!root->isNude())
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(15);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(12));
                root->setText(str(32));
                makeActBtn("gadforest",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(12));
                root->setText(str(33));
                makeActBtn("kolyambasex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) =root->vStatus(daystart);
                    root->vEvent(mirainforest) =0;
                    root->setImage(media(12));
                    root->setText(str(34));
                    makeActBtn("gadforest",act(3));
                    makeActBtn("watch_mirakolyamba",act(4));
                }
                else
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) =root->vStatus(daystart);
                    root->setImage(media(12));
                    root->setText(str(36));
                    makeActBtn("gadforest", act(0));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->vEvent(mirainforest) =0;
                root->setImage(media(12));
                root->setText(str(36));
                makeActBtn("kolyambasex",act(0));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->vEvent(mitboyrand) =2;
                root->vEvent(mitkaforestsex) =1;
                root->vEvent(mirasextimes) +=1;
                root->setImage(media(12));
                root->setText(str(37));
                makeActBtn("kolyambasex2",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(12));
                root->setText(str(38));
                makeActBtn("gadforest",act(0));
            }
        }
    }
    else
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(5);
                int tmp = getRandInt(1,2);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->setImage(media(12));
                if(tmp == 1)
                    root->setText(str(39));
                else
                    root->setText(str(40));
                if(tmp == 1)
                    makeActBtn("run_and_dress",act(6));
                else
                    makeActBtn("hide3",act(7));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) =root->vStatus(daystart);
                root->vEvent(mirainforest) =0;
                root->setImage(media(12));
                root->setText(str(42));
                makeActBtn("kolyambasex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) < 3)
            {
                if(root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    int tmp = getRandInt(1,2);
                    root->setImage(media(12));
                    if(tmp == 1)
                        root->setText(str(43));
                    else
                        root->setText(str(40));
                    if(tmp == 1)
                        makeActBtn("run_and_dress2",act(6));
                    else
                        makeActBtn("hide4",act(7));

                }
                else if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    int tmp = getRandInt(1,2);
                    root->setImage(media(12));
                    if(tmp == 1)
                        root->setText(str(43));
                    else
                        root->setText(str(40));
                    if(tmp == 1)
                        makeActBtn("run_and_dress3",act(6));
                    else
                        makeActBtn("hide4",act(7));
                }
            }
            else if (root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                int tmp = getRandInt(1,2);
                root->setImage(media(12));
                if(tmp == 1)
                    root->setText(str(46));
                else
                    root->setText(str(40));
                if(tmp == 1)
                    makeActBtn("kolyambasex3",act(0));
                else
                    makeActBtn("hide4",act(7));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mitboyrand) =2;
                root->vEvent(mitkaforestsex) =1;
                root->vEvent(mirasextimes) +=1;
                root->setImage(media(12));
                root->setText(str(47));
                makeActBtn("kolyambasex2",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(12));
                root->setText(str(40));
                makeActBtn("hide4",act(7));
            }
        }
    }
}

void GadforestEvent::gopforest_vasyan()
{
    if(!root->isNude())
    {
        if(root->vEvent(mirainforest) == 0 || root->vEvent(gadriver_gang) >= 3)
        {
            if(root->vEvent(mitkasextimes) < 13)
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(13));
                root->setText(str(48));
                makeActBtn("gadforest",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(13));
                root->setText(str(49));
                makeActBtn("vasyansex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->vEvent(mirainforest) = 0;
                    root->setImage(media(13));
                    root->setText(str(50));
                    makeActBtn("gadforest",act(3));
                    makeActBtn("watch_vasyan1",act(4));
                }
                else
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(13));
                    root->setText(str(52));
                    makeActBtn("gadforest",act(0));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mirainforest) =0;
                root->setImage(media(13));
                root->setText(str(53));
                makeActBtn("vasyansex",act(0));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mitboyrand) =3;
                root->vEvent(mitkaforestsex) =1;
                root->vEvent(mirasextimes) +=1;
                root->setImage(media(13));
                root->setText(str(54));
                makeActBtn("vasyansex2",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(13));
                root->setText(str(52));
                makeActBtn("gadforest",act(0));
            }
        }
    }
    else
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                int temp = getRandInt(1,2);
                root->setImage(media(13));
                if(temp == 1)
                    root->setText(str(55));
                else
                    root->setText(str(56));
                if(temp == 1)
                    makeActBtn("run_and_dress",act(6));
                else
                    makeActBtn("hide5",act(7));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(13));
                root->setText(str(58));
                makeActBtn("vasyansex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(13));
                    int tmp = getRandInt(1,2);
                    if(tmp == 1)
                        root->setText(str(59));
                    else
                        root->setText(str(56));
                    if(tmp == 1)
                        makeActBtn("run_and_dress2",act(6));
                    else
                        makeActBtn("hide6",act(7));
                }
                else if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    int temp = getRandInt(1,2);
                    root->setImage(media(13));
                    if(temp == 1)
                        root->setText(str(59));
                    else
                        root->setText(str(56));
                    if(temp == 1)
                        makeActBtn("run_and_dress4",act(6));
                    else
                        makeActBtn("hide5",act(7));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                int temp = getRandInt(1,2);
                root->setImage(media(13));
                if(temp == 1)
                    root->setText(str(62));
                else
                    root->setText(str(56));
                if(temp == 1)
                    makeActBtn("vasyansex3",act(0));
                else
                    makeActBtn("hide6",act(7));
            }
            else if (root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mitboyrand) =3;
                root->vEvent(mitkaforestsex) =1;
                root->vEvent(mirasextimes) +=1;
                root->setImage(media(13));
                root->setText(str(63));
                makeActBtn("vasyansex2",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(13));
                root->setText(str(56));
                makeActBtn("hide6",act(7));
            }
        }
    }
}

void GadforestEvent::gopforest_2boys()
{
    if(!root->isNude())
    {
        if(root->vEvent(mirainforest) == 0)
        {
            root->vEvent(temphant) = getRandInt(4,6);
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(root->vEvent(temphant) == 4)
                    root->setText(str(64));
                if(root->vEvent(temphant) == 5)
                    root->setText(str(65));
                if(root->vEvent(temphant) == 6)
                    root->setText(str(66));
                makeActBtn("gadforest",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(root->vEvent(temphant) == 4)
                    root->setText(str(67));
                if(root->vEvent(temphant) == 5)
                    root->setText(str(68));
                if(root->vEvent(temphant) == 6)
                    root->setText(str(69));
                makeActBtn("2boyssex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->vEvent(mitboyrand) =getRandInt(1,3);
                if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->vEvent(mirainforest) =0;
                    root->setImage(media(14));
                    if(root->vEvent(temphant) == 4)
                        root->setText(str(70));
                    if(root->vEvent(temphant) == 5)
                        root->setText(str(71));
                    if(root->vEvent(temphant) == 6)
                        root->setText(str(72));
                    makeActBtn("gadforest", act(3));
                    makeActBtn("watch_mira2boys",act(4));
                }
                else
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(14));
                    if(root->vEvent(temphant) == 4)
                        root->setText(str(76));
                    if(root->vEvent(temphant) == 5)
                        root->setText(str(77));
                    if(root->vEvent(temphant) == 6)
                        root->setText(str(78));
                    makeActBtn("gadforest",act(0));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mirainforest) =0;
                root->setImage(media(14));
                if(root->vEvent(temphant) == 4)
                    root->setText(str(79));
                if(root->vEvent(temphant) == 5)
                    root->setText(str(80));
                if(root->vEvent(temphant) == 6)
                    root->setText(str(81));
                makeActBtn("2boyssex",act(0));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mirainforest) =0;
                root->setImage(media(14));
                if(root->vEvent(temphant) == 4)
                    root->setText(str(82));
                if(root->vEvent(temphant) == 5)
                    root->setText(str(83));
                if(root->vEvent(temphant) == 6)
                    root->setText(str(84));
                makeActBtn("2boyssex2",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(root->vEvent(temphant) == 4)
                    root->setText(str(76));
                if(root->vEvent(temphant) == 5)
                    root->setText(str(77));
                if(root->vEvent(temphant) == 6)
                    root->setText(str(78));
                makeActBtn("gadforest",act(0));
            }
        }
    }
    else
    {
        if(root->vEvent(mirainforest) == 0)
        {
            root->vEvent(temphant) =getRandInt(1,3);
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(5);
                int temp = getRandInt(1,2);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(temp == 1)
                {
                    if(root->vEvent(temphant) == 1)
                        root->setText(str(85));
                    if(root->vEvent(temphant) == 2)
                        root->setText(str(86));
                    if(root->vEvent(temphant) == 3)
                        root->setText(str(87));
                    makeActBtn("run_and_dress",act(6));
                }
                else
                {
                    if(root->vEvent(temphant) == 1)
                        root->setText(str(88));
                    if(root->vEvent(temphant) == 2)
                        root->setText(str(89));
                    if(root->vEvent(temphant) == 3)
                        root->setText(str(90));
                    makeActBtn("hide7",act(7));
                }
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(root->vEvent(temphant) == 1)
                    root->setText(str(91));
                if(root->vEvent(temphant) == 2)
                    root->setText(str(92));
                if(root->vEvent(temphant) == 3)
                    root->setText(str(93));
                makeActBtn("2boyssex",act(0));
            }
        }
        else
        {
            root->vEvent(mitboyrand) =getRandInt(1,3);
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(14));
                    int tmp = getRandInt(1,2);
                    if(tmp == 1)
                    {
                        if(root->vEvent(mitboyrand) == 1)
                            root->setText(str(94));
                        if(root->vEvent(mitboyrand) == 2)
                            root->setText(str(95));
                        if(root->vEvent(mitboyrand) == 3)
                            root->setText(str(96));
                        makeActBtn("run_and_dress2",act(6));
                    }
                    else
                    {
                        if(root->vEvent(mitboyrand) == 1)
                            root->setText(str(97));
                        if(root->vEvent(mitboyrand) == 2)
                            root->setText(str(98));
                        if(root->vEvent(mitboyrand) == 3)
                            root->setText(str(99));
                        makeActBtn("hide8",act(7));
                    }
                }
                else if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(14));
                    int tmp = getRandInt(1,2);
                    if(tmp == 1)
                    {
                        if(root->vEvent(mitboyrand) == 1)
                            root->setText(str(94));
                        if(root->vEvent(mitboyrand) == 2)
                            root->setText(str(95));
                        if(root->vEvent(mitboyrand) == 3)
                            root->setText(str(96));
                        makeActBtn("run_and_dress5",act(6));
                    }
                    else
                    {
                        if(root->vEvent(mitboyrand) == 1)
                            root->setText(str(97));
                        if(root->vEvent(mitboyrand) == 2)
                            root->setText(str(98));
                        if(root->vEvent(mitboyrand) == 3)
                            root->setText(str(99));
                        makeActBtn("hide8",act(7));
                    }
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang)< 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                int tmp = getRandInt(1,2);
                if(tmp == 1)
                {
                    if(root->vEvent(mitboyrand) == 1)
                        root->setText(str(103));
                    if(root->vEvent(mitboyrand) == 2)
                        root->setText(str(104));
                    if(root->vEvent(mitboyrand) == 3)
                        root->setText(str(105));
                    makeActBtn("2boyssex3",act(0));
                }
                else
                {
                    if(root->vEvent(mitboyrand) == 1)
                        root->setText(str(97));
                    if(root->vEvent(mitboyrand) == 2)
                        root->setText(str(98));
                    if(root->vEvent(mitboyrand) == 3)
                        root->setText(str(99));
                    makeActBtn("hide8",act(7));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang)< 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                root->vEvent(mirasextimes) +=1;
                if(root->vEvent(mitboyrand) == 1)
                    root->setText(str(106));
                if(root->vEvent(mitboyrand) == 2)
                    root->setText(str(107));
                if(root->vEvent(mitboyrand) == 3)
                    root->setText(str(108));
                makeActBtn("2boyssex2",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(14));
                if(root->vEvent(mitboyrand) == 1)
                    root->setText(str(97));
                if(root->vEvent(mitboyrand) == 2)
                    root->setText(str(98));
                if(root->vEvent(mitboyrand) == 3)
                    root->setText(str(99));
                makeActBtn("hide8",act(7));
            }
        }
    }
}

void GadforestEvent::gopforest_3boys()
{
    if(!root->isNude())
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->setText(str(109));
                makeActBtn("gadforest",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->setText(str(110));
                makeActBtn("3boyssex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->vEvent(mirainforest) =0;
                    root->setImage(media(15));
                    root->setText(str(111));
                    makeActBtn("gadforest", act(3));
                    makeActBtn("watch_mira3boys",act(4));
                }
                else
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(15));
                    root->setText(str(113));
                    makeActBtn("gadforest",act(0));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mirainforest) = 0;
                root->setImage(media(15));
                root->setText(str(114));
                makeActBtn("3boyssex",act(0));
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang) < 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->vEvent(mirasextimes) +=1;
                root->setImage(media(15));
                root->setText(str(115));
                makeActBtn("3boyssex2",act(0));
            }
            else
            {
                root->incTime(15);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->setText(str(113));
                makeActBtn("gadforest",act(0));
            }
        }
    }
    else
    {
        if(root->vEvent(mirainforest) == 0)
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                root->incTime(5);
                int temp = getRandInt(1,2);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                if(temp == 1)
                {
                    root->setText(str(116));
                    makeActBtn("run_and_dress",act(6));
                }
                else
                {
                    root->setText(str(117));
                    makeActBtn("hide7",act(7));
                }
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->setText(str(118));
                makeActBtn("3boyssex",act(0));
            }
        }
        else
        {
            if(root->vEvent(mitkasextimes) < 13 || root->vEvent(gadriver_gang) >= 3)
            {
                if(root->vQuest(miragopQW) < 11)
                {
                    root->incTime(15);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(15));
                    int tmp = getRandInt(1,2);
                    if(tmp == 1)
                    {
                        makeActBtn("run_and_dress2",act(6));
                        root->setText(str(119));
                    }
                    else
                    {
                        makeActBtn("hide8",act(7));
                        root->setText(str(120));
                    }
                }
                else if(root->vQuest(miragopQW) >= 11)
                {
                    root->incTime(5);
                    root->vEvent(gadboyday) = root->vStatus(daystart);
                    root->setImage(media(15));
                    int tmp = getRandInt(1,2);
                    if(tmp == 1)
                    {
                        root->setText(str(119));
                        makeActBtn("run_and_dress6",act(6));
                    }
                    else
                    {
                        root->setText(str(120));
                        makeActBtn("hide8",act(7));
                    }
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) < 11 && root->vEvent(gadriver_gang)< 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                int tmp = getRandInt(1,2);
                if(tmp == 1)
                {
                    root->setText(str(121));
                    makeActBtn("3boyssex3",act(0));
                }
                else
                {
                    root->setText(str(120));
                    makeActBtn("hide8",act(7));
                }
            }
            else if(root->vEvent(mitkasextimes) >= 13 && root->vQuest(miragopQW) >= 11 && root->vEvent(gadriver_gang)< 3)
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->vEvent(mirasextimes) +=1;
                root->setText(str(122));
                makeActBtn("3boyssex2",act(0));
            }
            else
            {
                root->incTime(5);
                root->vEvent(gadboyday) = root->vStatus(daystart);
                root->setImage(media(15));
                root->setText(str(120));
                makeActBtn("hide8",act(7));
            }
        }
    }
}

void GadforestEvent::nude_event()
{
    root->incTime(5);
    root->vStatus(horny) += 10;
    if(root->vEvent(mirainforest) == 0)
    {
        root->setImage(media(16));
        root->setText(str(123));
    }
    else
    {
        root->setImage(media(17));
        root->setText(str(124));
    }
    makeActBtn("Give_in_to_temptation",act(9));
}

void GadforestEvent::mushroom_pickers1()
{
    root->incTime(5);
    root->vEvent(mushroom_pickersday) = root->vStatus(daystart);
    root->setImage(media(18));
    root->setText(str(127));
    if(root->isNude())
        root->addText(str(128));
    makeActBtn("back_to_loc",act(0));
}

void GadforestEvent::mushroom_pickers2()
{
    root->incTime(5);
    root->vEvent(mushroom_pickersday) = root->vStatus(daystart);
    root->setImage(media(19));
    root->setText(str(129));
    if(root->isNude())
    {
        root->vStatus(horny) += 5;
        root->addText(str(128));
    }
    makeActBtn("gadforest",act(10));
    if(root->vEvent(mirainforest) == 0)
        makeActBtn("mushroom_pickers_way",act(11));
}

void GadforestEvent::mushroom_pickers3()
{
    root->incTime(5);
    root->vEvent(mushroom_pickersday) = root->vStatus(daystart);
    root->setImage(media(20));
    root->setText(str(130));
    if(root->isNude())
    {
        root->vStatus(horny) += 5;
        root->addText(str(128));
    }
    makeActBtn("pickers3_exit",act(12));
    if(root->isCloth())
        makeActBtn("hello_pickers",act(13));
}

void GadforestEvent::mushroom()
{
    root->vEvent(foresteventday) = root->vStatus(daystart);
    root->setImage(media(21));
    root->setText(str(134));
    makeActBtn("collect_mushrooms",act(15));
}

void GadforestEvent::billberry()
{
    root->vEvent(foresteventday) = root->vStatus(daystart);
    root->setImage(media(22));
    root->setText(str(136));
    makeActBtn("collect_billberry",act(16));
}

void GadforestEvent::basket()
{
    root->incTime(5);
    int tmp = getRandInt(1,2);
    root->vEvent(foresteventday) = root->vStatus(daystart);
    if(tmp == 1)
    {
        root->setImage(media(23));
        root->setText(str(138));
        makeActBtn("take_boletus_basket",act(17));
    }
    if(tmp == 2)
    {
        root->setImage(media(24));
        root->setText(str(139));
        makeActBtn("take_bilberry_basket",act(17));
    }
}

void GadforestEvent::picnic()
{
    root->incTime(5);
    root->setImage(media(25));
    root->setText(str(140));
    if(root->isNude())
    {
        root->addText(str(141));
        makeActBtn("hide_n_dress",act(18));
    }
    makeActBtn("gadforest",act(3));
}

void GadforestEvent::forest_hanters()
{
    root->incTime(5);
    root->vEvent(foresteventday) = root->vStatus(daystart);
    root->setImage(media(26));
    if(root->vEvent(hantersKnow) == 0)
        root->setText(str(143));
    else if(root->vEvent(hantersKnow) == 1)
        root->setText(str(144));
    if(root->vEvent(forest_lost) == 1)
    {
        makeActBtn("hanters_lost1",act(0));
    }
    else
    {
        if(!root->isNude())
        {
            makeActBtn("go_hanters",act(20));
            makeActBtn("back_to_loc",act(12));
        }
        else
        {
            makeActBtn("hide_hanters",act(7));
        }
    }
}

void GadforestEvent::forest_road()
{
    int tmp = getRandInt(1,10);
    root->setImage(media(16));
    root->setText(str(164));
    if(tmp > 3)
    {
        makeActBtn("forest_road1",act(0));
    }
    else
    {
        makeActBtn("forest_road2",act(0));
    }
}

void GadforestEvent::swamp_road()
{
    int tmp = getRandInt(1,10);
    root->setImage(media(16));
    root->setText(str(172));
    if(tmp > 3)
    {
        makeActBtn("forest_road1",act(0));
    }
    else
    {
        makeActBtn("swamp_road2",act(0));
    }
}

void GadforestEvent::lost()
{
    root->setImage(media(27));
    root->setText(str(173));
    makeActBtn("forest_road1",act(0));
}

void GadforestEvent::relax()
{
    root->setImage(media(28));
    root->setText(str(174));
    makeActBtn("forest_road1",act(0));
}

QString GadforestEvent::str(int id)
{
    QString str[175];
    str[0] = "Вы в течение получаса бродили по лесу в поисках грибов или ягод и нашли " + intQStr(root->vEvent(new_boletus)) + " кг грибов и " + intQStr(root->vEvent(new_bilberry)) + " кг ягод.";
    str[1] = "Вы в течение получаса бродили по лесу в поисках грибов или ягод и нашли " + intQStr(root->vEvent(new_bilberry)) + " кг ягод.";
    str[2] = "Вы в течение получаса бродили по лесу в поисках грибов или ягод, но ничего не нашли.";
    str[3] = "Вы вдруг с ужасом понимаете, что местность вам не знакома... вы заблудились.";
    str[4] = "Идя по лесу вы встретили Митьку. Поболтав с ним немного вы отправились дальше.";
    str[5] = "Идя по лесу вы встретили Митьку. Увидев вас Митька почесал яйца и сказал с ухмылкой:<br>- Светик, пойдем поебемся, а то стояк заеб.";
    str[6] = "Идя по лесу с Мирой, вы встретили Митьку. Поболтав немного вместе, вы уже собрались идти дальше, когда к вам подошла Мира."
             "- Светик, ты погуляй дальше по лесу одна, а мне тут с Митькой поговорить наедине надо, - отчаянно краснея произнесла она."
             "- Он меня потом проводит домой сам."
             "- Ну ладно, - ответили вы Мире и подмигнув на прощанье отправились дальше.";
    str[7] = "Они болтают между собой, попутно раздеваясь, но о чем именно они говорят, вам не удается услышать из-за растояния.";
    str[8] = "Через пару минут Мирослава ложится перед Митькой на покрывало и призывно расставляет перед ним ноги. Тот, не заставляя себя ждать, тут же пристраивается у нее между ног и начинает грубо и сильно вколачивать в нее свой член, отчего она начинает громко и охать и подвизгивать.";
    str[9] = "Минуть через пятнадцать Митька наконец кончает Мирославе на живот и еще немного полежав, они оделись и пошли в сторону деревни...";
    str[10] = "Мирка прыгает задницей на митькином члене, каждый раз шлепаясь ягодицами о его бедра, и громко постанывает.";
    str[11] = "Мирка, раздвинув руками ягодицы, стоит на четвереньках и громко охает, когда Митька, полностью вынимая, вгоняет в ее распахнутую задницу свой член.";
    str[12] = "Через пару минут Митька сильно шлепает ее по заднице и Мира быстро разворачивается, встает перед ним на колени и далеко высунув язык, принимает на свое лицо его теплую сперму...";
    str[13] = "Идя по лесу с Мирой, вы встретили Митьку. Увидев Миру Митька не церемонясь схватил её за руку и поволок в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[14] = "Мирка прыгает задницей на митькином члене, каждый раз шлепаясь ягодицами о его бедра, и громко постанывает.";
    str[15] = "Мирка, раздвинув руками ягодицы, стоит на четвереньках и громко охает, когда Митька, полностью вынимая, вгоняет в ее распахнутую задницу свой член.";
    str[16] = "Через пару минут Митька сильно шлепает ее по заднице и Мира быстро разворачивается, встает перед ним на колени и далеко высунув язык, принимает на свое лицо его теплую сперму...";
    str[17] = "Идя по лесу с Мирой, вы встретили Митьку. Вы поболтали с ним немного, порой замечая, с каким интересом Мира рассматривает Митьку, и отправились дальше.";
    str[18] = "Идя по лесу с Мирой вы встретили Митьку. Увидев вас Митька почесал яйца и не обращая внимания на рядом стоящую Мирославу сказал с ухмылкой:"
              "- Светик, пойдем поебемся, а то стояк заеб.";
    str[19] = "Идя с Мирой по лесу вы встретили Митьку. Увидев вас Митька почесал яйца и сказал с ухмылкой:"
                "- О, вы то мне как раз и нужны, - и схватив вас за руки поволок в ближайшие кусты.";
    str[20] = "Идя по лесу с Мирой, вы встретили Митьку. Вы поболтали с ним немного и отправились дальше.";
    str[21] = "Идя по лесу вы нос к носу столкнулись с Митькой. Он вытаращился, глядя на вас обнаженную, а вы решили...";
    str[22] = "Идя по лесу вы увидели Митьку. Понимая, что он вас еще не заметил, вы решили...";
    str[23] = "Взвизгнув от неожиданности, вы кинулись наутек, в сторону своей одежды. Одевшись и успокоившись вы отправились дальше.";
    str[24] = "Вы быстро спрятались в ближайших кустах, а когда Митька прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[25] = "Вы, делая вид, что не замечаете остолбеневшего Митьку, прошли мимо него, демонстративно покачивая бедрами для закрепления эффекта. Оглянувшись украдкой, вы заметили, что произведенный эффект превзошел ваши ожидания. Митька спустив штаны до колен дрочил, глядя вам вслед.";
    str[26] = "Идя по лесу вы встретили Митьку. Увидев его вы попытались одеться, но Митька без лишних слов схватил вас за руку и потащил в ближайшие кусты.";
    str[27] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Митькой. Он вытаращился, глядя на вас обнаженных...";
    str[28] = "Взвизгнув от неожиданности, вы с Мирой кинулись убегать к вашей одежде. Одевшись и успокоившись неспеша отправились дальше.";
    str[29] = "Вы с Мирой спрятались в ближайших кустах, а когда Митька прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[30] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Митькой. Взвизгнув от неожиданности вы кинулись к своей одежде, за улепетывающей со всех ног Мирославой, но Митька без лишних слов схватил вас в охапку и потащил в ближайшие кусты.";
    str[31] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Митькой. Увидев вас обнаженных Митька почесал яйца и поволок в ближайшие кусты.";
    str[32] = "Идя по лесу вы встретили Колямбу. Поболтав с ним немного вы отправились дальше.";
    str[33] = "Идя по лесу вы встретили Колямбу. Увидев вас он почесал яйца и поволок ближайшие в кусты.";
    str[34] = "Идя по лесу с Мирой, вы встретили Колямбу. Увидев Миру он не церемонясь схватил её за руку и поволок в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[35] = "Мира в одних шлепанцах стоит раком, оттопырив как раз в вашу сторону свою задницу, и громко охает, когда Колямба шлепает ее по промежности своими яйцами, вгоняя в ее влагалище свой член. Мирослава скребет руками по земле и выгибается как кошка, при этом что-то в перерывах между оханьями говоря Колямбе. Но тот, кажется. не обращает на это совершенно никакого внимания, продолжая долбить ее в киску, и вскоре доводит девушку до оргазма, а через минуту кончает и сам...";
    str[36] = "Идя по лесу с Мирой вы встретили Колямбу. Увидев вас он почесал яйца и не обращая внимания на рядом стоящую Мирославу, поволок вас в ближайшие кусты.";
    str[37] = "Идя с Мирой по лесу вы встретили Колямбу. Увидев вас он почесал яйца и схватив вас обеих за руки, поволок в кусты.";
    str[38] = "Идя по лесу с Мирой, вы встретили Колямбу. Вы поболтали с ним немного и отправились дальше.";
    str[39] = "Идя по лесу вы нос к носу столкнулись с Колямбой. Он вытаращился, глядя на вас обнаженную, а вы решили...";
    str[40] = "Идя по лесу вы увидели Колямбу. Понимая, что он вас еще не заметил, вы решили...";
    str[41] = "Вы быстро спрятались в ближайших кустах, а когда Колямба прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[42] = "Идя по лесу вы встретили Колямбу. Увидев его вы попытались одеться, но он без лишних слов схватил вас за руку и потащил в ближайшие кусты.";
    str[43] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Колямбой. Он вытаращился, глядя на вас обнаженных...";
    str[44] = "Вы с Мирой спрятались в ближайших кустах, а когда Колямба прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[45] = "Взвизгнув от неожиданности, вы с Мирой кинулись к вашей одежде. Убегая вы успели замить краем глаза, как Колямба, особо не церемонясь схватил её за руку, и поволок в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы побежали дальше одна. Одевшись и успокоившись вы решили...";
    str[46] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Колямбой. Взвизгнув от неожиданности вы кинулись к своей одежде, за улепетывающей со всех ног Мирославой, но он без лишних слов схватил вас в охапку и потащил в ближайшие кусты.";
    str[47] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Колямбой. Увидев вас обнаженных он почесал яйца и без разговоров поволок в ближайшие кусты.";
    str[48] = "Идя по лесу вы встретили Васяна. Поболтав с ним немного вы отправились дальше.";
    str[49] = "Идя по лесу вы встретили Васяна. Увидев вас он почесал яйца и поволок ближайшие в кусты.";
    str[50] = "Идя по лесу с Мирой, вы встретили Васяна. Увидев Миру он не церемонясь схватил её за руку и поволок в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[51] = "Полностью голая Мирослава, согнувшись, стоит перед Васяном и усиленно подставляет ему попку, в которую он и вгоняет свой член. Судя по ее похотливым стонам, ей вполне нравится, что ее имеют в задницу, но уже через пару минут Васян вынимает из нее свой член и спускает ей на ягодицы...";
    str[52] = "Идя по лесу с Мирой, вы встретили Васяна. Вы поболтали с ним немного и отправились дальше.";
    str[53] = "Идя по лесу с Мирой вы встретили Васяна. Увидев вас он почесал яйца и не обращая внимания на рядом стоящую Мирославу, поволок вас в ближайшие кусты.";
    str[54] = "Идя с Мирой по лесу вы встретили Васяна. Увидев вас он почесал яйца и схватив вас обеих за руки, поволок в кусты.";
    str[55] = "Идя по лесу вы нос к носу столкнулись с Васяном. Он вытаращился, глядя на вас обнаженную, а вы решили...";
    str[56] = "Идя по лесу вы увидели Васяна. Понимая, что он вас еще не заметил, вы решили...";
    str[57] = "Вы быстро спрятались в ближайших кустах, а когда Васян прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[58] = "Идя по лесу вы встретили Васяна. Увидев его вы попытались одеться, но он без лишних слов схватил вас за руку и потащил в ближайшие кусты.";
    str[59] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Васяном. Он вытаращился, глядя на вас обнаженных...";
    str[60] = "Взвизгнув от неожиданности, вы с Мирой кинулись к вашей одежде. Убегая вы успели замить краем глаза, как Васян, особо не церемонясь схватил её за руку, и поволок в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы побежали дальше одна. Одевшись и успокоившись вы решили...";
    str[61] = "Вы с Мирой спрятались в ближайших кустах, а когда Васян прошел мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[62] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Васяном. Взвизгнув от неожиданности вы кинулись к своей одежде, за улепетывающей со всех ног Мирославой, но он без лишних слов схватил вас в охапку и потащил в ближайшие кусты.";
    str[63] = "Идя по лесу с Мирой, вы нос к носу столкнулись с Васяном. Увидев вас обнаженных он почесал яйца и без разговоров поволок в ближайшие кусты.";
    str[64] = "Идя по лесу вы встретили Митьку и Колямбу. Вы поболтали с ними немного и отправились дальше.";
    str[65] = "Идя по лесу вы встретили Митьку и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[66] = "Идя по лесу вы встретили Колямбу и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[67] = "Идя по лесу вы встретили Митьку и Колямбу. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[68] = "Идя по лесу вы встретили Митьку и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[69] = "Идя по лесу вы встретили Колямбу и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[70] = "Идя с Мирой по лесу вы встретили Митьку и Колямбу. Увидев Миру они не церемонясь схватили её за руки и поволокли в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[71] = "Идя с Мирой по лесу вы встретили Митьку и Васяна. Увидев Миру они не церемонясь схватили её за руки и поволокли в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[72] = "Идя с Мирой по лесу вы встретили Колямбу и Васяна. Увидев Миру они не церемонясь схватили её за руки и поволокли в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[73] = "Мира на корточках сидит перед одним из пацанов и как раз принимает себе в рот его сперму. Облизав и спрятав в штаны его член, она то же самое прожелывает с другим...";
    str[74] = "Пацаны, вдвоем трахая Миру в рот и в киску, о чем-то со смехом разговаривают между собой. Мирослава же вторит им своими стонами и плямканьями... Минут через пятнадцать они заканчивают и начинают собираться...";
    str[75] = "Все трое почти голые и одному из них Мира как раз отсасывает, а второй, судя по всему, уже кончил, а потому просто лапает ее грудь и шебуршит рукой у нее между похотливо рассталвенных ног...";
    str[76] = "Идя с Мирой по лесу вы встретили Митьку и Колямбу. Вы поболтали с ними немного и отправились дальше.";
    str[77] = "Идя с Мирой по лесу вы встретили Митьку и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[78] = "Идя с Мирой по лесу вы встретили Колямбу и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[79] = "Идя с Мирой по лесу вы встретили Митьку и Колямбу. Увидев вас они усмехнулись и не обращая внимания на рядом стоящую Мирославу, поволокли в ближайшие кусты.";
    str[80] = "Идя с Мирой по лесу вы встретили Митьку и Васяна. Увидев вас они усмехнулись и не обращая внимания на рядом стоящую Мирославу, поволокли в ближайшие кусты.";
    str[81] = "Идя с Мирой по лесу вы встретили Колямбу и Васяна. Увидев вас они усмехнулись и не обращая внимания на рядом стоящую Мирославу, поволокли в ближайшие кусты.";
    str[82] = "Идя с Мирой по лесу вы встретили Митьку и Колямбу. Увидев вас они обрадовались и схватив вас обеих за руки, поволокли в ближайшие кусты.";
    str[83] = "Идя с Мирой по лесу вы встретили Митьку и Васяна. Увидев вас они обрадовались и схватив вас обеих за руки, поволокли в ближайшие кусты.";
    str[84] = "Идя с Мирой по лесу вы встретили Васяна и Колямбу. Увидев вас они обрадовались и схватив вас обеих за руки, поволокли в ближайшие кусты.";
    str[85] = "Идя по лесу вы нос к носу столкнулись с Митькой и Колямбой. Они вытаращились, глядя на вас обнаженную, а вы решили...";
    str[86] = "Идя по лесу вы нос к носу столкнулись с Митькой и Васяном. Они вытаращились, глядя на вас обнаженную, а вы решили...";
    str[87] = "Идя по лесу вы нос к носу столкнулись с Васяном и Колямбой. Они вытаращились, глядя на вас обнаженную, а вы решили...";
    str[88] = "Идя по лесу вы увидели Митьку и Колямбу. Понимая, что он вас еще не заметили, вы решили...";
    str[89] = "Идя по лесу вы увидели Митьку и Васяна. Понимая, что он вас еще не заметили, вы решили...";
    str[90] = "Идя по лесу вы увидели Васяна и Колямбу. Понимая, что он вас еще не заметили, вы решили...";
    str[91] = "Идя по лесу вы встретили Митьку и Колямбу. Увидев их вы попытались убежать и одеться, но они без лишних слов схватили вас под руки и потащили в ближайшие кусты.";
    str[92] = "Идя по лесу вы встретили Митьку и Васяна. Увидев их вы попытались убежать и одеться, но они без лишних слов схватили вас под руки и потащили в ближайшие кусты.";
    str[93] = "Идя по лесу вы встретили Васяна и Колямбу. Увидев их вы попытались убежать и одеться, но они без лишних слов схватили вас под руки и потащили в ближайшие кусты.";
    str[94] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Колямбой. Они вытаращились, глядя на вас обнаженных, а вы решили...";
    str[95] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Васяном. Они вытаращились, глядя на вас обнаженных, а вы решили...";
    str[96] = "Идя с Мирой по лесу вы нос к носу столкнулись с Васяном и Колямбой. Они вытаращились, глядя на вас обнаженных, а вы решили...";
    str[97] = "Идя с Мирой по лесу вы увидели Митьку и Колямбу. Понимая, что они вас еще не заметили, вы решили...";
    str[98] = "Идя с Мирой по лесу вы увидели Митьку и Васяна. Понимая, что они вас еще не заметили, вы решили...";
    str[99] = "Идя с Мирой по лесу вы увидели Васяна и Колямбу. Понимая, что они вас еще не заметили, вы решили...";
    str[100] = "Вы быстро спрятались в ближайших кустах, а когда парни прошли мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[101] = "Вы с Мирой спрятались в ближайших кустах, а когда парни прошли мимо так и не заметив вас, выбрались и переведя дух отправились дальше.";
    str[102] = "Взвизгнув от неожиданности, вы с Мирой кинулись к вашей одежде. Убегая вы успели замить краем глаза, как парни, особо не церемонясь схватили её за руки, и поволокли в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы побежали дальше одна. Одевшись и успокоившись вы решили...";
    str[103] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Колямбой. Взвизгнув от неожиданности вы кинулись к своей одежде, вслед за улепетывающей со всех ног Мирославой, но они без лишних слов схватили вас в охапку и потащили в ближайшие кусты.";
    str[104] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Васяном. Взвизгнув от неожиданности вы кинулись к своей одежде, вслед за улепетывающей со всех ног Мирославой, но они без лишних слов схватили вас в охапку и потащили в ближайшие кусты.";
    str[105] = "Идя с Мирой по лесу вы нос к носу столкнулись с Васяном и Колямбой. Взвизгнув от неожиданности вы кинулись к своей одежде, вслед за улепетывающей со всех ног Мирославой, но они без лишних слов схватили вас в охапку и потащили в ближайшие кусты.";
    str[106] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Колямбой. Увидев вас обнаженных они почесали яйца и без разговоров поволокли в ближайшие кусты.";
    str[107] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой и Васяном. Увидев вас обнаженных они почесали яйца и без разговоров поволокли в ближайшие кусты.";
    str[108] = "Идя с Мирой по лесу вы нос к носу столкнулись с Васяном и Колямбой. Увидев вас обнаженных они почесали яйца и без разговоров поволокли в ближайшие кусты.";
    str[109] = "Идя по лесу вы встретили Митьку, Колямбу и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[110] = "Идя по лесу вы встретили Митьку, Колямбу и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[111] = "Идя с Мирой по лесу вы встретили Митьку, Колямбу и Васяна. Увидев Миру они не церемонясь схватили её за руки и поволокли в ближайшие кусты. Видя , что Мира идет не сопротивляясь, вы решили не вмешиваться и отправились дальше.";
    str[112] = "Мира на корточках сидит между тремя дружками и с удовольствием чавкает их членами. Вы наблюдаете, как они по очереди спукают ей кто в рот, а кто просто на лицо...";
    str[113] = "Идя с Мирой по лесу вы встретили Митьку, Колямбу и Васяна. Вы поболтали с ними немного и отправились дальше.";
    str[114] = "Идя с Мирой по лесу вы встретили Митьку, Колямбу и Васяна. Увидев вас они усмехнулись и не обращая внимания на рядом стоящую Мирославу, поволокли в ближайшие кусты.";
    str[115] = "Идя с Мирой по лесу вы встретили Митьку, Колямбу и Васяна. Увидев вас они обрадовались и схватив вас обеих за руки, поволокли в ближайшие кусты.";
    str[116] = "Идя по лесу вы нос к носу столкнулись с Митьку, Колямбу и Васяна. Они вытаращились, глядя на вас обнаженную, а вы решили...";
    str[117] = "Идя по лесу вы увидели Митьку, Колямбу и Васяна. Понимая, что они вас еще не заметили, вы решили...";
    str[118] = "Идя по лесу вы встретили Митьку, Колямбу и Васяна. Увидев их вы попытались убежать и одеться, но они без лишних слов схватили вас под руки и потащили в ближайшие кусты.";
    str[119] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой, Колямбой и Васяном. Они вытаращились, глядя на вас обнаженных, а вы решили...";
    str[120] = "Идя с Мирой по лесу вы увидели Митьку, Колямбу и Васяна. Понимая, что они вас еще не заметили, вы решили...";
    str[121] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой, Колямбой и Васяном. Взвизгнув от неожиданности вы кинулись к своей одежде, вслед за улепетывающей со всех ног Мирославой, но они без лишних слов схватили вас в охапку и потащили в ближайшие кусты.";
    str[122] = "Идя с Мирой по лесу вы нос к носу столкнулись с Митькой, Колямбой и Васяном. Увидев вас обнаженных они почесали яйца и без разговоров поволокли в ближайшие кусты.";
    str[123] = "Войдя в лес, вы вдруг вспомнили рассказ Миры про гуляние нагишом и чудодейственное влияние местного воздуха на организм."
               "- Хмммм.... подумали вы. - Байки наверное, но почему бы не попробовать?"
               "От одной мысли, что вы будете обнаженной посреди леса, между ножек стало предательски зудеть. Наконец в сотый раз оглянувшись, чтобы удостовериться, что рядом никого нет, вы решаете...";
    str[124] = "Вы с Мирой вошли в лес, когда она начала разговор."
                "- Светик, помнишь мой рассказ про лес? - начала она. - Байки наверное, но почему бы не попробовать?"
                "- Это про гуляние голышом? - спросили вы её."
                "- Ага, про это, - подтвердила Мира. - Не хочешь сама попробовать?"
                "- Ээээ... ну я не знаю Мир, - неожиданное предложение Миры с одной стороны вас пугало, с другой стороны не на шутку возбуждало. - А если кто-нибудь увидит?"
                "- Ой, да кто тут увидит? - засмеялась она и отвернувшись от вас, закричала во весь голос. - Эййй, люди, ауууу!!!"
                " В ответ, кроме щебетания птиц не раздалось ни звука."
                "- Вот видишь, нет тут никого, - она опять повернулась в вашу сторону."
                "Вы все равно стояли и нерешительно оглядывались по сторонам."
                "- Ну, Светик, давай, решайся, - весело сказала Мира и начала хватать вас за одежду, пытаясь её стянуть."
                "Наконец в сотый раз оглянувшись, чтобы удостовериться, что рядом никого нет, вы решаете...";
    str[125] = "Вы не стеснясь разделись, оставшись в чем мать родила.";
    str[126] = "Видя, что сопротивление сломлено, Мира быстро принялась вас раздевать, оставив в чем мать родила.";
    str[127] = "Бродя по лесу в поисках грибов, вы замечаете других грибников. Интересно, стоит ли продолжать поиски в этом месте, или стоит перейти в другое?";
    str[128] = "Хорошо, что они вас не заметили, а то было бы разговоров на всю деревню.";
    str[129] = "На окраине леса вы увидели других грибников, уходящих в глубь леса. Интересно, может стоит пойти за ними? Вдруг они выведут в грибные места.";
    str[130] = "Бродя по лесу в поисках грибов, вы замечаете грибников устроивших привал.";
    str[131] = "Вы вежливо поздоровались, проходя мимо. Мужчины глянув на вас, ответили тем же.";
    str[132] = "Вы весело спрашиваете у грибников, как дела, и один из них, показывает большой палец, кивая на полную корзину грибов. Вы еще минут десять болтаете о лесе и грибных местах, потом попрощавшись уходите.";
    str[133] = "Вы весело спрашиваете у грибников, как дела, и один из них, показывает большой палец, кивая на полную корзину грибов."
                "- А у тебя как дела внучка? - спрашивает один из них."
                "- Так себе, - грустно отвечаете вы, показывая свою почти пустую корзинку."
                "- Ну что мужики, поможем девушке, отсыпем из наших немного? - весело спрашивает он своих друзей. Те с радостью соглашаются и ваша корзинка сразу становится значительно тяжелее."
                "Вы еще минут десять болтаете о лесе и грибных местах, потом попрощавшись уходите.";
    str[133] = "Вы весело спрашиваете у грибников, как дела, и один из них, показывает большой палец, кивая на полную корзину грибов."
                "- А у тебя как дела внучка? - спрашивает один из них."
                "- Сегодня нормально, - отвечаете вы, показывая свою корзинку."
                "Вы еще минут десять болтаете о лесе и грибных местах, потом попрощавшись уходите.";
    str[134] = "Бродя по лесу, вы наткнулись на грибную поляну. Вот так удача!.";
    str[135] = "Вы принялись собирать грибы стараясь все вместить в корзину.";
    str[136] = "Бродя по лесу, вы наткнулись на поляну с ягодами. Вот так удача!";
    str[137] = "Вы принялись собирать грибы стараясь все вместить в корзину.";
    str[138] = "Бродя по лесу вы находите карзину полную грибов. Странно, наверное кто-то забыл её здесь или просто потерял.";
    str[139] = "Бродя по лесу вы находите карзину полную ягод. Странно, наверное кто-то забыл её здесь или просто потерял.";
    str[140] = "На окраине леса вы увидели людей. Судя по всему у них тут семейный пикник.";
    str[141] = "Хорошо, что они вас не заметили.";
    str[142] = "Вы переоделись в свою одежду.";
    str[143] = "Бродя по лесу вы наткнулись людей. Судя по внешнему виду это были охотники.";
    str[144] = "Бродя по лесу вы увидели людей. Это были ваши знакомые охотники Андрей, Сергей и Игорь.";
    str[145] = "- Дяденьки, помогите, - кинулись вы к ним с криком."
                    "- Что случилось? - встрепенулись они, выставив ружья в разные стороны."
                    "- Я заблудилась, а в лесу так страаашноо, - со слезами ответили вы."
                    "- Тьфу ты, - сплюнул на землю мужчина постарше. - Ты так кричала, что мы подумали, что за тобой стая волков гонится, не меньше.";
    str[146] = "- А они тут есть? - в ужасе распахнули вы глаза."
                "- Конечно, - сказал охотник. - Днем они в основном не показываются, а вот ночью в лес ходить не советую.";
    str[147] = "- Да хорош пугать девчонку, - сказал другой охотник. - Лучше бы присесть предложил, смотри, умаялась вся."
            "- Да, действительно, пошли присядем, - согласился первый. - В ногах правды нет."
            "- Ага, - хохотнул второй. - И выше её тоже нет."
            "После этого вы отправились на видневшуюся за деревьями поляну.";
    str[148] = "Вы замерли, не зная что вам делать, то ли спрятаться, то ли попросить помощи. Но прятаться было уже поздно, мужчины вас заметили и вы не смело двинулись к ним на встречу. Пока вы шли к ним, мужчины не сводили с вас глаз. Вам было неприятно под этими изучающими взглядами, но другого выхода не было."
                    "- Что случилось? - начал один, постарше, когда вы подошли ближе. - И почему ты в таком... хмммм... виде?"
                    "- Я заблудилась, - ответили вы со слезами на глазах. И начали нести всякую околесицу про маньяков, насильников, погони и другие нелепости, объясняя свой совсем не подходящий для прогулки по лесу вид."
                    "- Ладно, ладно, успокойся, - прервал он вас. - Все уже позади. Это хорошо, что ты нас встретила, а не стаю волков каких.";
    str[149] = "- Да хорош пугать девчонку, - сказал другой охотник. - Лучше дай ей чем прикрыться, а то стоит, красная как рак. И присесть бы предложил, смотри, умаялась вся."
               "- Да, действительно, - согласился первый и покапавшись в рюкзаке достал кусок какой-то ткани. "
               "- Держи, не Дольче Габбана конечно, но другого все равно нет."
               "- Спасибо, - пискнули в ответ вы и быстренько обмотались тканью как полотенцем."
               "- Ну, а теперь пошли присядем, познакомимся, - сказал первый охотник. - В ногах правды нет."
               "- Ага, - хохотнул второй. - И выше её тоже нет."
               "После этого вы отправились на находящуюся за деревьями поляну.";
    str[150] = "Добравшись до поляны, парни уселись прямо на землю. Вы, немного подумав, поступили так же.";
    str[151] = "- Как звать-величать тебя, красавица? - спросил один из них.";
    str[152] = "- Как звать-величать то тебя? - спросил один из них.";
    str[153] = "- Света, - ответили вы.";
    str[154] = "- А я Андрей, - ответил ответил мужчина постарше, - а это друзья мои из центра, Игорь и Сергей."
                "- А твоя фамилия не Лебедева случайно? - спросил он. Вы удивленно посмотрели на него и кивнули."
               "- Не удивляйся Света, ты очень похожа на маму в молодости. А я её ... Хммм... очень хорошо знал когда-то, я ведь тоже из Гадюкино, - сказал Андрей.";
    str[155] = "- Ба, кого к нам занесло, - удивлённо протянул мужчина постарше, присмотревшись к вам повнимательней, - это же Света Лебедева, местная шлюшка."
               "Вы удивленно посмотрели на него."
                "- Не удивляйся, я ведь тоже из Гадюкино, а ты очень похожа на маму в молодости, и судя по всему такая же блядоватая, - сказал он."
                "- Я Андрей, - добавил он дальше, - а это друзья мои из центра, Игорь и Сергей."
                "- Да не вскакивай ты, мы дяди добрые, не кусаемся, - сказал Сергей, видя вашу попытку вскочить на ноги.";
    str[156] = "Отдохнув полчаса охотники начали подниматься на ноги."
                "- Ладно Света, давай мы тебя до болота доведем, - сказал Андрей. - А там дорога есть на деревню, а если захочешь, у нас в гостях останешься.";
    str[157] = "Вы решили подойти к ребятам и пообщаться.";
    str[158] = "Поболтав с вами о том, о сём, еще полчаса, охотники стали собираться..."
                "- Ладно Светик, пора нам, - сказал Андрей. - А может к нам в гости заглянешь?";
    str[159] = "- О, Светик, вовремя ты появилась, - сказал Андрей с довольной улыбкой беря вас за руку.";
    str[160] = "Вы покорно пошли следом, прекрасно понимая куда и зачем вас ведут.";
    str[161] = "- Надо, так надо, - подумали вы и пошли с парнями, прекрасно понимая куда и зачем вас ведут.";
    str[162] = "- Отлично, то что нужно, главное вовремя, - подумали вы, чувствуя как ваша киска изнывает от желания. Вы пошли с парнями, чуть ли не обгоняя его, и уже не ясно было, кто кого ведет.";
    str[163] = "Вы решили спрятаться от греха, пока вас не заметили. Подождав, пока мужчины уйдут, вы продолжили свой путь.";
    str[164] = "Вы отправились по дороге в сторону деревни, весело напевая себе под нос.";
    str[165] = "Пройдя примерно половину пути, вы вдруг услышали страшный вой.";
    str[166] = "На вас напал ступор и вы застыли в ужасе, глядя в темноту в которой были уже заметны неясные тени.";
    str[167] = "Вы не раздумывая кинулись наутек.";
    str[168] = "Вы долго бежали по дороге, боясь оглянуться назад. В конец выбившись из сил вы остановились и осмотревшись поняли, что за вами никто не гонится, а вы уже на окраине леса.";
    str[169] = "Вы долго бежали не разбирая дороги и боясь оглянуться назад. В конец выбившись из сил вы остановились и осмотревшись поняли, что за вами никто не гонится, но вы понятия не имеете, где находитесь.";
    str[170] = "Вы кинулись в панике бежать, но почти сразу же почувствовали мощной толчок в спину и упали.";
    str[171] = "Чуть приподнявшись на руках вы оглянулись и увидели оскаленную пасть волка, прямо у себя перед лицом.";
    str[172] = "Вы отправились по дороге в сторону болота, весело напевая себе под нос.";
    str[173] = "Вы блуждаете по лесу, пытаясь найти знакомые места и выйти из леса.";
    str[174] = "Вы сидите в лесу и отдыхаете, пытаясь вспомнить дорогу до деревни.";
    return str[id];
}

QString GadforestEvent::act(int id)
{
    QString act[25];
    act[0] = "Далее";
    act[1] = "Согласиться";
    act[2] = "Отказаться";
    act[3] = "Уйти";
    act[4] = "Подсматривать";
    act[5] = "Смотреть";
    act[6] = "Убежать и одеться";
    act[7] = "Спрятаться";
    act[8] = "Идти дальше";
    act[9] = "Поддаться искушению";
    act[10] = "Остаться тут";
    act[11] = "Пойти за грибниками";
    act[12] = "Пройти мимо";
    act[13] = "Поздоровоться";
    act[14] = "Поболтать";
    act[15] = "Собирать грибы";
    act[16] = "Собирать ягоды";
    act[17] = "Забрать";
    act[18] = "Спрятаться и одеться";
    act[19] = "Назад";
    act[20] = "Подойти";
    act[21] = "Идти с охотниками";
    act[22] = "Убегать";
    act[23] = "Застыть в ужасе";
    act[24] = "Закричать от ужаса";
    return act[id];
}

QString GadforestEvent::media(int id)
{
    QString med[66];
    med[0] = "data/npc/gadukino/mitka/mitka.jpg";
    med[1] = "data/locations/gadukino/forest/mushroom1.jpg";
    med[2] = "data/locations/gadukino/forest/mushroom" + intQStr(2 + root->isPanties()) + ".jpg";
    med[3] = "data/locations/gadukino/forest/mushroom4." + intQStr(getRandInt(1,3)) + ".jpg";
    QString add;
    if(root->isNude())
        add = "_nude";
    med[4] = "data/locations/gadukino/forest/miramushroom" + add + intQStr(getRandInt(1,2)) + ".jpg";
    med[5] = "data/locations/gadukino/forest/gulforest2.jpg";
    med[6] = "data/locations/gadukino/forest/gulforest3.jpg";
    med[7] = "data/locations/gadukino/forest/gulforest_tanga1."+intQStr(getRandInt(1,2)) + ".jpg";
    med[8] = "data/locations/gadukino/forest/gulforest_nude1."+intQStr(getRandInt(1,4)) + ".jpg";
    med[9] = "data/locations/gadukino/forest/miramushroom_nude3.jpg";
    med[10] = "data/locations/gadukino/forest/miramushroom3.jpg";
    med[11] = "data/locations/gadukino/forest/gadfear";
    if(root->isNude()) { med[11] += "2"; }
    else
    {
        if(root->getTemp() < 15) { med[11] += "3"; }
        else { med[11] += "1"; }
    }
    med[11] += ".jpg";
    med[12] = "data/npc/gadukino/mitka/kolyamba.jpg";
    med[13] = "data/npc/gadukino/mitka/vasyan.jpg";
    med[14] = "data/npc/gadukino/mitka/2boys." + intQStr(getRandInt(1,2)) + ".jpg";
    med[15] = "data/npc/gadukino/mitka/3boys." + intQStr(getRandInt(1,2)) + ".jpg";
    med[16] = "data/locations/gadukino/forest/forest_road.jpg";
    med[17] = "data/locations/gadukino/forest/miraforest4.jpg";
    med[18] = "data/locations/gadukino/forest/mushroom_pickers1.jpg";
    med[19] = "data/locations/gadukino/forest/mushroom_pickers2.jpg";
    med[20] = "data/locations/gadukino/forest/mushroom_pickers3.jpg";
    med[21] = "data/locations/gadukino/forest/mushroom0." + intQStr(getRandInt(1,3)) + ".jpg";
    med[22] = "data/locations/gadukino/forest/bilberry3.jpg";
    med[23] = "data/locations/gadukino/forest/basket_boletus.jpg";
    med[24] = "data/locations/gadukino/forest/basket_boletus.jpg";
    med[25] = "data/locations/gadukino/forest/picnic1." + intQStr(getRandInt(1,4)) + ".jpg";
    med[26] = "data/locations/gadukino/forest/forest_hanters" + intQStr(getRandInt(1,2)) + ".jpg";
    med[27] = "data/locations/gadukino/forest/gadforestsearch0.4.jpg";
    med[28] = "data/locations/gadukino/forest/gadforestrelax3.jpg";
    med[29] = "data/sex/mira/MiraMeadowSex.jpg";
    med[30] = "data/sex/mira/MiraMeadowAnal.jpg";
    med[31] = "data/sex/mira/MiraMeadowAnal1.jpg";
    med[32] = "data/sex/mira/MiraMeadowSex1.jpg";
    med[33] = "data/sex/mira/MiraMeadowSex2.jpg";
    med[34] = "data/sex/mira/MiraMeadowAnal2.jpg";
    med[35] = "data/locations/gadukino/swamp/swampbackwaternude1.jpg";
    med[36] = "data/locations/gadukino/forest/gopforestnude.jpg";
    med[37] = "data/locations/gadukino/forest/mitkahideforest.jpg";
    med[38] = "data/locations/gadukino/forest/gophideforest.jpg";
    med[39] = "data/locations/gadukino/forest/mitkanudeforest.jpg";
    med[40] = "data/sex/mira/MiraMeadowBJ2.jpg";
    med[41] = "data/sex/mira/MiraMeadowBJ6.jpg";
    med[42] = "data/sex/mira/MiraMeadowBJ8.jpg";
    med[43] = "data/sex/mira/MiraMeadowBJ9.jpg";
    med[44] = "data/sex/mira/MiraMeadowBJ10.jpg";
    med[45] = "data/sex/mira/MiraMeadowBJ11.jpg";
    med[46] = "data/locations/gadukino/forest/nudeforest.jpg";
    med[47] = "data/locations/gadukino/forest/nudeforest1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[48] = "data/locations/gadukino/forest/miraforest5.jpg";
    med[49] = "data/locations/gadukino/forest/mushroom2.jpg";
    med[50] = "data/locations/gadukino/forest/mushroom3.jpg";
    med[51] = "data/locations/gadukino/forest/mushroom4." + intQStr(getRandInt(1,3)) + ".jpg";
    med[52] = "data/locations/gadukino/forest/bilberry1.jpg";
    med[53] = "data/locations/gadukino/forest/nudeforest1." + intQStr(getRandInt(1,2))+ ".jpg";
    med[54] = "data/locations/gadukino/forest/gadfear1.jpg";
    med[55] = "data/locations/gadukino/forest/gadfear2.jpg";
    med[56] = "data/locations/gadukino/forest/gadfear3.jpg";
    med[57] = "data/locations/gadukino/swamp/hanters.jpg";
    med[58] = "data/locations/gadukino/forest/hiding_woods.jpg";
    med[59] = "data/locations/gadukino/forest/howl.jpg";
    med[60] = "data/locations/gadukino/forest/horror.jpg";
    med[61] = "data/locations/gadukino/forest/run.jpg";
    med[62] = "data/locations/gadukino/forest/run_end1.jpg";
    med[63] = "data/locations/gadukino/forest/run_end2.jpg";
    med[64] = "data/locations/gadukino/forest/run_wolf.jpg";
    med[65] = "data/locations/gadukino/forest/wolf.jpg";
    return med[id];
}

void GadforestEvent::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"gadforestevent");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadforestEvent::actionHandler);
    root->addActions(btn);
}

void GadforestEvent::actionHandler(QString action)
{
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "gadforestlostmain")
    {
        root->startEvent(eGadForestLost, "main");
    }
    if(action == "gadforest")
    {
        root->changeLoc(lgadforest);
    }
    if(action == "mitkasex")
    {
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) = 4;
        root->startEvent(eHanters);
    }
    if(action == "mitksasex2")
    {
        root->vEvent(mirainforest) = 0;
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) = 4;
        root->startEvent(eHanters);
    }
    if(action == "mitkasex3")
    {
        root->vEvent(mitboyrand) =1;
        root->startEvent(eMitkaSex);
    }
    if(action == "kolyambasex")
    {
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) =5;
        root->startEvent(eHanters);
    }
    if(action == "kolyambasex2")
    {
        root->startEvent(eMitkaSex);
    }
    if(action == "kolyambasex3")
    {
        root->vEvent(mirainforest) = 0;
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) =5;
        root->startEvent(eHanters);
    }
    if(action == "vasyansex")
    {
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) =6;
        root->startEvent(eHanters);
    }
    if(action == "vasyansex2")
    {
        root->startEvent(eMitkaSex);
    }
    if(action == "vasyansex3")
    {
        root->vEvent(mirainforest) =0;
        root->vEvent(forest_gopsex) = 1;
        root->vEvent(temphant) =6;
        root->startEvent(eHanters);
    }
    if(action == "watch_miramitka0")
    {
        if(root->vQuest(miragopQW) < 8)
        {
            root->incTime(2);
            root->vStatistics(voyeurism) += 1;
            root->vStatus(horny) += 5;
            root->setImage(media(29));
            root->setText(str(7));
            makeActBtn("watch_miramitka01",act(5));
        }
        else
        {
            root->incTime(2);
            root->vStatus(horny) +=  getRandInt(15,30);
            int temp = getRandInt(0,1);
            if(temp == 0)
            {
                root->setImage(media(30));
                root->setText(str(10));
            }
            else
            {
                root->setText(str(11));
                root->setImage(media(31));
            }
            makeActBtn("watch_miramitka11",act(5));
        }
    }
    if(action == "watch_miramitka01")
    {
        root->incTime(5);
        root->vStatus(horny) += 25;
        root->setImage(media(32));
        root->setText(str(8));
        makeActBtn("watch_miramitka02",act(5));
    }
    if(action == "watch_miramitka02")
    {
        root->incTime(5);
        root->vStatus(horny) += 15;
        if(root->vQuest(miragopQW) == 2)
            root->vQuest(miragopQW) =3;
        root->setImage(media(33));
        root->setText(str(9));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_miramitka11")
    {
        root->incTime(10);
        root->vStatus(horny) += getRandInt(15,30);
        root->vEvent(mirasextimes) +=1;
        root->setImage(media(34));
        root->setText(str(12));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_miramitka2")
    {
        root->incTime(5);
        root->vStatus(horny) += getRandInt(15,30);
        root->vStatistics(voyeurism) += 1;
        int temp = getRandInt(0,1);
        if(temp == 0)
        {
            root->setImage(media(30));
            root->setText(str(14));
        }
        else
        {
            root->setImage(media(31));
            root->setText(str(15));
        }
        makeActBtn("watch_miramitka21",act(5));
    }
    if(action == "watch_miramitka21")
    {
        root->incTime(10);
        root->vStatus(horny) += getRandInt(15,30);
        root->vEvent(mirasextimes) +=1;
        root->setImage(media(34));
        root->setText(str(16));
        makeActBtn("gadforest",act(0));
    }
    if(action == "run_and_dress")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(35));
        root->setText(str(23));
        makeActBtn("gadforest",act(0));
    }
    if(action == "run_and_dress2")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(36));
        root->setText(str(28));
        makeActBtn("gadforest",act(0));
    }
    if(action == "run_and_dress3")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(36));
        root->setText(str(45));
        makeActBtn("gadforest",act(3));
        makeActBtn("watch_mirakolyamba2",act(4));
    }
    if(action == "run_and_dress4")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(36));
        root->setText(str(60));
        makeActBtn("gadforest",act(3));
        makeActBtn("watch_miravasyan",act(4));
    }
    if(action == "run_and_dress5")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(36));
        root->setText(str(102));
        makeActBtn("gadforest",act(3));
        makeActBtn("watch_mira2boys",act(4));
    }
    if(action == "run_and_dress6")
    {
        root->vEvent(gopsawnaked) += 1;
        if(root->vEvent(gopsawnaked) >= 10)
        {
            root->vEvent(gopsawnaked) = 0;
            root->vEvent(mitkasextimes) +=1;
        }
        root->vStatus(horny) += 10;
        root->vStatus(clothesforest) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->incTime(5);
        root->redressOld();
        root->setImage(media(36));
        root->setText(str(102));
        makeActBtn("gadforest",act(3));
        makeActBtn("watch_mira3boys",act(4));
    }
    if(action == "hide")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(37));
        root->setText(str(24));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide2")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(38));
        root->setText(str(29));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide3")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(37));
        root->setText(str(41));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide4")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(38));
        root->setText(str(44));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide5")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(37));
        root->setText(str(57));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide6")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(38));
        root->setText(str(61));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide7")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(37));
        root->setText(str(100));
        makeActBtn("gadforest",act(0));
    }
    if(action == "hide8")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(38));
        root->setText(str(101));
        makeActBtn("gadforest",act(0));
    }
    if(action == "go_next")
    {
        root->vEvent(gadboyday) = root->vStatus(daystart);
        root->incTime(5);
        if(root->vEvent(mitkasextimes) == 0)
            root->vEvent(mitkasextimes) +=1;
        root->vStatus(horny) += 20;
        root->setImage(media(39));
        root->setText(str(25));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_mirakolyamba")
    {
        root->incTime(10);
        root->vStatus(horny) += 30;
        root->vEvent(mirasextimes) +=1;
        root->setImage(media(40));
        root->setText(str(35));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_mirakolyamba2")
    {
        root->incTime(10);
        root->vStatus(horny) += 30;
        root->vEvent(mirasextimes) +=1;
        root->vStatistics(voyeurism) += 1;
        root->setImage(media(40));
        root->setText(str(35));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_vasyan1")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->vEvent(mirasextimes) +=1;
        root->vStatistics(voyeurism) += 1;
        root->setImage(media(41));
        root->setText(str(51));
        makeActBtn("gadforest",act(0));
    }
    if(action == "watch_miravasyan")
    {
        root->incTime(10);
        root->vStatus(horny) += 40;
        root->vEvent(mirasextimes) +=1;
        root->vStatistics(voyeurism) += 1;
        root->setImage(media(41));
        root->setText(str(51));
        makeActBtn("gadforest",act(0));
    }
    if(action == "2boyssex")
    {
        root->vEvent(forest_gopsex) = 2;;
        root->startEvent(eHanterSex);
    }
    if(action == "2boyssex2")
    {
        root->vEvent(mitkaforestsex) = 2;
        root->startEvent(eMitkaSex);
    }
    if(action == "2boyssex3")
    {
        root->vEvent(mirainforest) =0;
        root->vEvent(forest_gopsex) = 2;;
        root->startEvent(eHanterSex);
    }
    if(action == "watch_mira2boys")
    {
        root->incTime(5);
        root->vStatus(horny) += 40;
        root->vEvent(mirasextimes) +=1;
        root->vStatistics(voyeurism) += 1;
        if(root->vEvent(mitboyrand) == 1)
        {
            root->setImage(media(45));
            root->setText(str(73));
        }
        else if(root->vEvent(mitboyrand) == 2)
        {
            root->setImage(media(44));
            root->setText(str(74));
        }
        else
        {
            root->setImage(media(43));
            root->setText(str(75));
        }
        makeActBtn("gadforest",act(0));
    }
    if(action == "3boyssex")
    {
        root->vEvent(forest_gopsex) = 3;;
        root->startEvent(eHanters);
    }
    if(action == "3boyssex2")
    {
        root->vEvent(mitkaforestsex) =3;
        root->startEvent(eMitkaSex);
    }
    if(action == "3boyssex3")
    {
        root->vEvent(mirainforest) =0;
        root->vEvent(forest_gopsex) = 3;;
        root->startEvent(eHanters);
    }
    if(action == "watch_mira3boys")
    {
        root->incTime(5);
        root->vStatus(horny) += 40;
        root->vEvent(mirasextimes) +=1;
        root->vStatistics(voyeurism) += 1;
        root->setImage(media(42));
        root->setText(str(112));
        makeActBtn("gadforest",act(0));
    }
    if(action == "Give_in_to_temptation")
    {
        root->vStatus(clothesforest) = 1;
        root->incTime(5);
        root->vStatus(horny) += 10;
        if(root->vEvent(mirainforest) == 1)
            root->vQuest(miraQW) += 5;
        if(root->vEvent(mirainforest) == 0)
            root->vEvent(miratalkforest) = 2;
        else
            root->vEvent(miratalkforest) = 3;
        if(!root->isSkirt() && root->vEvent(mirainforest) == 0)
            root->setImage(media(46));
        if(root->isSkirt() && root->vEvent(mirainforest) == 0)
            root->setImage(media(47));
        if(root->vEvent(mirainforest) == 1)
            root->setImage(media(48));
        root->redress(ClothType::Main,nullptr);
        if(root->vEvent(mirainforest) == 0)
            root->setText(str(125));
        else
            root->setText(str(126));
        makeActBtn("gadforest",act(0));
    }
    if(action == "mushroom_pickers_way")
    {
        ((Gadforest*)root->getLocPtr(root->getCurLoc()))->actionHandler(intQStr(getRandInt(2,4)));
    }
    if(action == "pickers3_exit")
    {
        root->vEvent(pickersday) = root->vStatus(daystart);
        actionHandler("back_to_loc");
    }
    if(action == "hello_pickers")
    {
        root->vEvent(foresteventday) = root->vStatus(daystart);
        root->incTime(3);
        if(root->vQuest(pickersQW) < 3)
            root->vQuest(pickersQW) += 1;
        root->setImage(media(20));
        root->setText(str(131));
        if(root->vQuest(pickersQW) >= 3)
            makeActBtn("talk_pickers",act(14));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "talk_pickers")
    {
        root->incTime(10);
        root->vQuest(pickersQW) = getRandInt(4,7);
        root->vEvent(goforest) += getRandInt(0,1);
        root->setImage(media(20));
        if(root->vQuest(pickersQW) <= 5)
            root->setText(str(132));
        if(root->vQuest(pickersQW) > 5 && root->vStatus(boletus) + root->vStatus(bilberry) < 5)
        {
            root->setText(str(133));
            root->vEvent(pickershelp) =1;
        }
        if(root->vQuest(pickersQW) > 5 && root->vStatus(boletus) + root->vStatus(bilberry) >= 5)
        {
            root->setText(str(134));
        }
        if(root->vEvent(pickershelp) == 1)
        {
            root->vEvent(pickershelp) = 0;
            root->vStatus(boletus) += getRandInt(1,2);
            root->vStatus(bilberry) += getRandInt(1,2);
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "collect_mushrooms")
    {
        root->incTime(60);
        root->vStatus(boletus) += getRandInt(5,10);
        if(root->isCloth() && !root->isSkirt())
            root->setImage(media(1));
        if(root->isCloth() && root->isSkirt() && root->isPanties())
            root->setImage(media(49));
        if(root->isCloth() && root->isSkirt() && !root->isPanties())
            root->setImage(media(50));
        if(root->isNude())
            root->setImage(media(51));
        root->setText(str(135));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "collect_billberry")
    {
        root->incTime(60);
        root->vStatus(bilberry) += getRandInt(5,10);
        root->setImage(media(52));
        root->setText(str(137));
    }
    if(action == "take_boletus_basket")
    {
        root->vStatus(boletus)+=10;
        actionHandler("back_to_loc");
    }
    if(action == "take_bilberry_basket")
    {
        root->vStatus(bilberry) += 10;
        actionHandler("back_to_loc");
    }
    if(action == "hide_n_dress")
    {
        root->redressOld();
        if(root->isSkirt())
            root->setImage(media(53));
        else
            root->setImage(media(46));
        root->setText(str(142));
        makeActBtn("gadforest",act(19));
    }
    if(action == "hanters_lost1")
    {
        if(root->vEvent(hantersKnow) == 0)
        {
            root->incTime(5);
            root->vEvent(forest_lost) =0;
            root->vEvent(hantersKnow) = 1;
            root->vEvent(goforest) +=1;
            if(root->getMonth() >= 5 && root->getMonth() <= 9)
            {
                if(!root->isNude())
                    root->setImage(media(54));
                else
                    root->setImage(media(55));
            }
            else
                root->setImage(media(56));
            if(!root->isNude())
            {
                root->setText(str(145));
                if(root->vEvent(wolf_know) == 0)
                    root->addText(str(146));
                root->addText(str(147));
            }
            else
            {
                root->setText(str(148));
                if(root->vEvent(wolf_know) == 0)
                    root->addText(str(146));
                root->addText(str(149));
                root->vEvent(hanterslut) +=1;
            }
            makeActBtn("hanters_lost1.1",act(0));
        }
        else
        {
            root->incTime(5);
            root->vEvent(goforest) +=1;
            root->setImage(media(57));
            root->setText(str(157));
            if(root->vEvent(hantersKnowSlut) == 0 || (root->vEvent(hantersKnowSlut) > 0 && root->vEvent(hantslutsex) > 0))
            {
                root->incTime(30);
                root->addText(str(158));
                makeActBtn("go_swamp",act(21));
                makeActBtn("back_to_lock",act(10));
            }
            else
            {
                root->setText(str(159));
                if(root->vStatus(horny) < 40)
                    root->addText(str(160));
                if(root->vStatus(horny) >= 40 && root->vStatus(horny) < 70)
                    root->addText(str(161));
                if(root->vStatus(horny) >= 70)
                    root->addText(str(162));
                makeActBtn("go_fuck_hanters",act(21));
            }
        }
    }
    if(action == "hanters_lost1.1")
    {
        root->incTime(30);
        root->vEvent(wolf_know) = 1;
        if(root->isNude())
        {
            root->vStatus(swamp_clothes) = 1;
            root->redress(ClothType::Main,new ClothMain(1,towel,"полотенце"));
        }
        root->setImage(media(57));
        root->setText(str(150));
        if(root->vStatus(vnesh) >= 40)
            root->addText(str(151));
        if(root->vStatus(vnesh) < 40)
            root->addText(str(152));
        root->addText(str(153));
        if(root->vEvent(gadriver_gang) == 0)
            root->addText(str(154));
        else
        {
            root->addText(str(155));
            root->vEvent(hantersKnowSlut) =1;
            root->vEvent(hantersRape) =1;
        }
        root->addText(str(156));
        makeActBtn("go_swamp",act(0));
    }
    if(action == "go_swamp")
    {
        root->vEvent(goswamp) = 1;
        root->vEvent(hanters) = 1;
        root->incTime(60);
        root->changeLoc(lswampyard);
    }
    if(action == "go_fuck_hanters")
    {
        root->vEvent(hanters) = 1;
        root->vEvent(goswamp) = 1;
        int tmp = getRandInt(1,3);
        root->vEvent(temphant) =getRandInt(1,3);
        if(tmp == 1)
        {
            root->vEvent(forest_hantersex) =1;
            root->startEvent(eHanters);
        }
        if(tmp == 2)
        {
            root->vEvent(forest_hantersex) =2;
            root->startEvent(eHanterSex);
        }
        if(tmp == 3)
        {
            root->vEvent(forest_hantersex) =3;
            root->startEvent(eHanters);
        }
    }
    if(action == "hide_hanters")
    {
        root->incTime(5);
        root->setImage(media(58));
        root->setText(str(163));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "forest_road1")
    {
        root->incTime(75);
        root->setImage(media(59));
        root->setText(str(165));
        if(root->vSkill(domination) >= 0)
            makeActBtn("run_from_wolf",act(22));
        else
            makeActBtn("stay_fear",act(23));
    }
    if(action == "forest_road2")
    {
        root->changeLoc(lgadforest,150);
    }
    if(action == "stay_fear")
    {
        root->incTime(1);
        root->setImage(media(60));
        root->setText(str(166));
        makeActBtn("finish_in_forest",act(0));
    }
    if(action == "finish_in_forest")
    {
        root->startEvent(eGameOver, "8");
    }
    if(action == "run_from_wolf")
    {
        root->setImage(media(61));
        root->setText(str(167));
        makeActBtn("run_from_wolf2",act(0));
    }
    if(action == "run_from_wolf2")
    {
        int wolftemp = getRandInt(0,200);
        int lostrand = getRandInt(0,100);
        if(root->vSkill(runner) > wolftemp && root->vEvent(goforest) > lostrand)
        {
            root->incTime(25);
            root->vStatus(sweat) +=2;
            root->setImage(media(62));
            root->setText(str(168));
            makeActBtn("gadforest",act(0));
        }
        else if(root->vSkill(runner) > wolftemp && root->vEvent(goforest) < lostrand)
        {
            root->incTime(25);
            root->vStatus(sweat) +=2;
            root->setImage(media(63));
            root->setText(str(169));
            makeActBtn("gadforestlostmain",act(0));
        }
        else
        {
            root->incTime(5);
            root->setImage(media(64));
            root->setText(str(170));
            makeActBtn("run_from_wolf3",act(0));
        }
    }
    if(action == "run_from_wolf3")
    {
        root->incTime(1);
        root->setImage(media(65));
        root->setText(str(171));
        makeActBtn("wolf_end",act(24));
    }
    if(action == "wolf_end")
    {
        root->startEvent(eGameOver,"9");
    }
    if(action == "swamp_road2")
    {
        root->changeLoc(lswamp,150);
    }

}
