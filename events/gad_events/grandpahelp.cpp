#include "grandpahelp.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

GrandpaHelp::GrandpaHelp(Game* ptr): root(ptr) {}

void GrandpaHelp::start(QString arg)
{
    actionHandler("grandpahelp");
}

void GrandpaHelp::actionHandler(QString action)
{
    if(action == "grandpahelp")
    {
        root->setImage(media(0));
        root->setText(str(0));
        int mon = root->getMonth();
        if(mon >= 1 && mon <= 4)
            root->vEvent(grandpahelping) = getRandInt(0,5);
        if(mon == 5)
            root->vEvent(grandpahelping) = getRandInt(6,11);
        if(mon == 6 || mon == 9)
            root->vEvent(grandpahelping) = getRandInt(12,21);
        if(mon == 7 || mon == 8)
            root->vEvent(grandpahelping) = getRandInt(22,32);
        if(mon >= 10 && mon <= 12)
            root->vEvent(grandpahelping) = getRandInt(0,4);
        fnGrandpaHelping();
    }
    if(action == "clean_yard")
    {
        root->incTime(60);
        root->vEvent(grandpahelp) +=1;
        root->vQuest(grandpaQW) += 1;
        root->vStatus(day_weight) -= 1;
        if(root->getMonth() >= 4 && root->getMonth() <= 10)
        {
            root->vSkill(strenght) += 1;
            root->setImage(media(1));
            root->setText(str(2));
        }
        else
        {
            root->setImage(media(2));
            root->setText(str(3));
        }
        makeActBtn("gaddvor",act(1));
    }
    if(action == "gaddvor")
    {
        root->changeLoc(lgaddvor,0);
    }
    if(action == "take_firewood")
    {
        root->incTime(15);
        root->vEvent(grandpahelp) += 1;
        root->vQuest(grandpaQW)+=1;
        genimage();
        root->setText(str(5));
        makeActBtn("gadhouse",act(1));
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "feed_horse")
    {
        root->vJob(feed_horse) =1;
        root->incTime(15);
        genimage();
        root->setText(str(7));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "gadsarai")
    {
        root->changeLoc(getLocId(action));
    }
    if(action == "feed_cow")
    {
        root->incTime(15);
        root->vJob(feed_cow) =1;
        genimage();
        root->setText(str(9));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "comb_horse")
    {
        root->vJob(comb_horse) =1;
        root->incTime(15);
        genimage();
        root->setText(str(11));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "feed_boar")
    {
        root->vJob(feed_boar) =1;
        root->incTime(15);
        genimage();
        root->setText(str(13));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "horse_field")
    {
        root->vJob(horse_field) = 1;
        root->incTime(10);
        root->setImage(media(3));
        root->setText(str(17));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "cow_field")
    {
        root->vJob(cow_field) =1;
        root->incTime(10);
        root->setImage(media(3));
        root->setText(str(18));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "graze_cow")
    {
        root->vJob(graze_cow) =1;
        root->vStatus(mood) +=20;
        root->vStatus(health) += 10;
        root->vStatus(cumLips) = 0;
        root->vStatus(water) = 24;
        root->vStatus(energy) += 10;
        if(root->vStatus(energy) > 24)
            root->vStatus(day_weight) += 2;
        else if(root->vStatus(energy) > 15 && root->vStatus(energy) < 25)
            root->vStatus(day_weight) += 1;
        root->incTime(20);
        //$inventory[5+'_count'] += 1
        //$inventory[6+'_count'] += 1
        if(root->vJob(graze_cow_exp) == 0)
        {
            root->setImage(media(3));
            root->setText(str(21));
            makeActBtn("gadsarai",act(4));
        }
        else
        {
            root->setImage(media(4));
            root->setText(str(22));
            makeActBtn("graze_field",act(4));
        }
    }
    if(action == "graze_field")
    {
        root->changeLoc(lgadfield,0,action);
    }
    if(action == "horse_river")
    {
        root->vJob(horse_river) = 1;
        root->incTime(10);
        root->setImage(media(3));
        root->setText(str(17));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "haying_time")
    {
        root->vJob(haying_time) = 1;
        root->incTime(40);
        root->setImage(media(5));
        root->setText(str(28));
        makeActBtn("field",act(4));
    }
    if(action == "field")
    {
        root->changeLoc(lgadfield,0,"field");
    }
}

void GrandpaHelp::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"GrandpaHelp");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GrandpaHelp::actionHandler);
    root->addActions(btn);
}

QString GrandpaHelp::str(int id)
{
    QString str[30];
    str[0] = "Вы подошли к дедушке и спросили не нужна ли ему какая-либо помощь. Дедушка подумал немного и сказал:";
    str[1] = "<npc>- Конечно внучка, нужно во дворе навести порядок.</npc>";
    str[2] = "Вооружившись граблями, вы принялись за уборку двора. После того как двор приобрел божеский вид, вы довольная собой поставили грабли в сарай и отправились по своим делам.";
    str[3] = "Вооружившись лопатой, вы принялись очищать двор от снега. После того как двор приобрел божеский вид, вы довольная собой поставили лопату в сарай и отправились по своим делам.";
    str[4] = "<npc>- Конечно Света, нужно дров для печки принести.</npc>";
    str[5] = "Вы быстро оделись, и быстро сбегав к сараю за дровами вернулись обратно."
        "<hero>- Все, деда, принесла,</hero> - сказали вы дедушке."
        "<npc>- Быстро ты, однако,</npc> - посмотрев на вас ответил он с улыбкой. <npc>- Вот что значит молодость. Беги, гуляй, на сегодня работы нет больше.</npc>";
    str[6] = "<npc>- Конечно внучка, ступай в сарай, покорми Буяна.</npc>";
    str[7] = "Вы пошли в сарай кормить коня.";
    str[8] = "<npc>- Внучка, сходи-ка в сарай, покормить Зорьку нужно.</npc>";
    str[9] = "Вы пошли в сарай где вас уже заждалась Зорька.";
    str[10] = "<npc>- Конечно внучка, ступай в сарай, нужно Буяна расчесать.</npc>";
    str[11] = "Вы пошли в сарай расчесывать коня.";
    str[12] = "<npc>- Конечно внучка, ступай в сарай, покорми кабана.</npc>";
    str[13] = "Вы пошли в сарай кормить кабана.";
    str[14] = "<npc>- Сегодня нет работы внучка, отдыхай.</npc>";
    str[15] = "<npc>- Света, внучка, отведи коня на поле, а то у меня сегодня ноги болят. А вечером я его сам заберу.</npc>";
    str[16] = "<npc>- Светуля у меня сегодня болят ноги. Так что, внучка, отведи корову на поле и отдай в стадо к пастухам, вечером они её сами пригонят домой.</npc>";
    str[17] = "Вы пошли в сарай где стоит конь.";
    str[18] = "Вы пошли в сарай где стоит Зорька.";
    str[19] = "<npc>- Света, внучка, сегодня пришла наша очередь коров пасти. Так что, внучка, поешь быстренько, бери Зорьку и веди на поле. А я пойду туда сразу, стадо встречать.</npc>";
    str[20] = "<npc>- Света, внучка, сегодня пришла наша очередь коров пасти. Так что, внучка, поешь быстренько, беги на поле стадо встречать. А я пригоню туда Зорьку.</npc>";
    str[21] = "Быстро перекусив вы пошли в сарай где стоит Зорька. Бабушка еще вам положила в сумку бутерброд и бутылку воды на обед.";
    str[22] = "Быстро перекусив вы побежали на поле, где уже собиралось деревенское стадо. Бабушка еще вам положила в сумку бутерброд и бутылку воды на обед.";
    str[23] = "<npc>- Внучка, сегодня хорошая погода. Отведи Буяна на речку, искупай его. Да и сама искупаешься.</npc>";
    str[24] = "<npc>- Света, внучка, сходи-ка в лес за грибами. Что-то грибочков жареных захотелось.</npc>"
        "<hero>- А сколько нужно, деда?</hero> - спросили вы."
        "<npc>- Да " + intQStr(root->vJob(grandpa_boletus)) + " кг будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
    str[25] = "<npc>- Света, внучка, сходи-ка в лес за ягодами. Бабушка варенья наварит.</npc>"
              "<hero>- А сколько нужно, деда?</hero> - спросили вы."
              "<npc>- Да " + intQStr(root->vJob(grandpa_bilberry)) + " кг будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
    str[26] = "<npc>- Света, внучка, сходи-ка в лес за ягодами и грибами. Бабушка супа грибного сварит, да и ягод свежих поедим.</npc>"
              "<hero>- А сколько нужно, деда?</hero> - спросили вы."
              "<npc>- Да " + intQStr(root->vJob(grandpa_boletus)) + " кг грибов и " + intQStr(root->vJob(grandpa_bilberry)) + " кг ягод будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
    str[27] = "<npc>- Внучка, сегодня сенокос. Надо идти на поле и помочь.</npc>"
              "<hero>- Хорошо, деда,</hero> - ответили вы. Потом, взяв грабли, отправились на поле ";
    str[28] = "Вы взяли грабли и пошли на поле, где уже собирались остальные местные жители.";
    return str[id];
}

QString GrandpaHelp::act(int id)
{
    QString act[20];
    act[0] = "Убирать двор";
    act[1] = "Уйти";
    act[2] = "Принести дрова";
    act[3] = "Идти в сарай";
    act[4] = "Далее";
    act[5] = "Идти ";
    if(root->vJob(graze_cow_exp) == 0)
        act[5] += "в сарай";
    else
        act[5] += "на поле";
    act[6] = "Идти на поле";
    return act[id];
}

QString GrandpaHelp::media(int id)
{
    QString med[7];
    med[0] = "data/npc/gadukino/grandpa/grandpa1.jpg";
    med[1] = "data/actions/clean_yard1.jpg";
    med[2] = "data/actions/clean_yard2.jpg";
    med[3] = "data/locations/gadukino/go_yard.jpg";
    med[4] = "data/locations/gadukino/gadfield/cow_go_field.jpg";
    med[5] = "data/locations/gadukino/gadfield/go_gadfield.jpg";
    med[6] = "data/locations/gadukino/go_yard_winter.jpg";
    return med[id];
}

void GrandpaHelp::fnGrandpaHelping()
{
    int help = root->vEvent(grandpahelping);
    if(help == 0 || help == 6 || help == 12 || help == 22)
    {
        root->setText(str(1));
        makeActBtn("clean_yard",act(0));
    }
    if(help == 1 || help == 7)
    {
        root->setText(str(4));
        makeActBtn("take_firewood",act(2));
    }
    if(help == 2)
    {
        root->setText(str(6));
        makeActBtn("feed_horse",act(3));
    }
    if(help == 3)
    {
        root->setText(str(8));
        makeActBtn("feed_cow",act(3));
    }
    if(help == 4)
    {
        root->setText(str(10));
        makeActBtn("comb_horse",act(3));
    }
    if(help == 5 || help == 13 || help == 23)
    {
        root->setText(str(12));
        makeActBtn("feed_boar",act(4));
    }
    if(help == 8 || help == 14 || help == 24)
    {
        if(root->getWeek() > 5 || root->getWeek() == 0)
        {
            root->setText(str(10));
            makeActBtn("comb_horse",act(3));
        }
        else
            no_job_today();
    }
    if(help == 9 || help == 15 || help == 25)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setText(str(15));
            makeActBtn("horse_field",act(3));
        }
        else
            no_job_today();
    }
    if(help == 10 || help == 16 || help == 26)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setText(str(16));
            makeActBtn("cow_field",act(3));
        }
        else
            no_job_today();
    }
    if(help == 11 || help == 17 || help == 27)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            if(root->vJob(graze_cow_exp) == 0)
                root->setText(str(19));
            if(root->vJob(graze_cow_exp) > 0)
                root->setText(str(20));
            makeActBtn("graze_cow",act(5));
        }
        else
            no_job_today();
    }
    if(help == 18 || help == 28)
    {
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && (root->getWeek() == 0 || root->getWeek() > 5))
        {
            root->setText(str(23));
            makeActBtn("horse_river",act(3));
        }
        else
            no_job_today();
    }
    if(help == 19 || help == 29)
    {
        if(root->vJob(go_in_boletus) == 0 && root->vJob(go_in_bilberry) == 0 && root->vJob(go_in_boletus_bilberry) == 0)
        {
            root->vJob(grandpa_boletus) = getRandInt(2,3);
            root->vJob(go_in_boletus) = 1;
            root->setText(str(24));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 20 || help == 30)
    {
        if(root->vJob(go_in_boletus) == 0 && root->vJob(go_in_bilberry) == 0 && root->vJob(go_in_boletus_bilberry) == 0)
        {
            root->vJob(grandpa_bilberry) = getRandInt(3,5);
            root->vJob(go_in_bilberry) = 1;
            root->setText(str(25));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 21 || help == 31)
    {
        if(root->vJob(go_in_boletus) == 0 && root->vJob(go_in_bilberry) == 0 && root->vJob(go_in_boletus_bilberry) == 0)
        {
            root->vJob(grandpa_boletus) = getRandInt(2,3);
            root->vJob(grandpa_bilberry) = getRandInt(2,3);
            root->vJob(go_in_boletus_bilberry) = 1;
            root->setText(str(26));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 32)
    {
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setText(str(27));
            makeActBtn("haying_time",act(6));
        }
        else
            no_job_today();
    }
}

void GrandpaHelp::genimage()
{
    QString add;
    if(root->getMonth() < 4 || root->getMonth() > 10)
        root->setImage(media(6));
    else
        root->setImage(media(3));
}

void GrandpaHelp::no_job_today()
{
    root->setText(str(14));
    makeActBtn("back_to_loc",act(1));
}
