#include "grandpahelp.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

GrandpaHelp::GrandpaHelp(EventHandler* ptr): root(ptr) {}

void GrandpaHelp::start(QString arg)
{
    actionHandler("grandpahelp");
}

void GrandpaHelp::actionHandler(QString action)
{
    if(action == "grandpahelp")
    {
        root->setImage(media(0));
        root->setDesc(str(0));
        int mon = root->getMonth();
        if(mon >= 1 && mon <= 4)
            root->sVEvent(grandpahelping,getRandInt(0,5));
        if(mon == 5)
            root->sVEvent(grandpahelping,getRandInt(6,11));
        if(mon == 6 || mon == 9)
            root->sVEvent(grandpahelping,getRandInt(12,21));
        if(mon == 7 || mon == 8)
            root->sVEvent(grandpahelping,getRandInt(22,32));
        if(mon >= 10 && mon <= 12)
            root->sVEvent(grandpahelping,getRandInt(0,4));
        fnGrandpaHelping();
    }
    if(action == "clean_yard")
    {
        root->incTime(60);
        root->uVEvent(grandpahelp,1);
        root->uVQuest(grandpaQW,1);
        root->uVStatus(day_weight,-1);
        if(root->getMonth() >= 4 && root->getMonth() <= 10)
        {
            root->uVSkill(strenght,1);
            root->setImage(media(1));
            root->setDesc(str(2));
        }
        else
        {
            root->setImage(media(2));
            root->setDesc(str(3));
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
        root->uVEvent(grandpahelp,1);
        root->uVQuest(grandpaQW,1);
        genimage();
        root->setDesc(str(5));
        makeActBtn("gadhouse",act(1));
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "feed_horse")
    {
        root->sVJob(feed_horse,1);
        root->incTime(15);
        genimage();
        root->setDesc(str(7));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "gadsarai")
    {
        root->changeLoc(getLocId(action));
    }
    if(action == "feed_cow")
    {
        root->incTime(15);
        root->sVJob(feed_cow,1);
        genimage();
        root->setDesc(str(9));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "comb_horse")
    {
        root->sVJob(comb_horse,1);
        root->incTime(15);
        genimage();
        root->setDesc(str(11));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "feed_boar")
    {
        root->sVJob(feed_boar,1);
        root->incTime(15);
        genimage();
        root->setDesc(str(13));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "horse_field")
    {
        root->sVJob(horse_field,1);
        root->incTime(10);
        root->setImage(media(3));
        root->setDesc(str(17));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "cow_field")
    {
        root->sVJob(cow_field,1);
        root->incTime(10);
        root->setImage(media(3));
        root->setDesc(str(18));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "graze_cow")
    {
        root->sVJob(graze_cow,1);
        root->uVStatus(mood,20);
        root->uVStatus(health,10);
        root->sVStatus(cumLips,0);
        root->sVStatus(water,24);
        root->uVStatus(energy,10);
        if(root->vStatus(energy) > 24)
            root->uVStatus(day_weight,2);
        else if(root->vStatus(energy) > 15 && root->vStatus(energy) < 25)
            root->uVStatus(day_weight,1);
        root->incTime(20);
        //$inventory[5+'_count'] += 1
        //$inventory[6+'_count'] += 1
        if(root->gVJob(graze_cow_exp) == 0)
        {
            root->setImage(media(3));
            root->setDesc(str(21));
            makeActBtn("gadsarai",act(4));
        }
        else
        {
            root->setImage(media(4));
            root->setDesc(str(22));
            makeActBtn("graze_field",act(4));
        }
    }
    if(action == "graze_field")
    {
        root->changeLoc(lgadfield,0,action);
    }
    if(action == "horse_river")
    {
        root->sVJob(horse_river,1);
        root->incTime(10);
        root->setImage(media(3));
        root->setDesc(str(17));
        makeActBtn("gadsarai",act(4));
    }
    if(action == "haying_time")
    {
        root->sVJob(haying_time,1);
        root->incTime(40);
        root->setImage(media(5));
        root->setDesc(str(28));
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
    root->addActBtn(btn);
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
        "<npc>- Да " + intQStr(root->gVJob(grandpa_boletus)) + " кг будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
    str[25] = "<npc>- Света, внучка, сходи-ка в лес за ягодами. Бабушка варенья наварит.</npc>"
              "<hero>- А сколько нужно, деда?</hero> - спросили вы."
              "<npc>- Да " + intQStr(root->gVJob(grandpa_bilberry)) + " кг будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
    str[26] = "<npc>- Света, внучка, сходи-ка в лес за ягодами и грибами. Бабушка супа грибного сварит, да и ягод свежих поедим.</npc>"
              "<hero>- А сколько нужно, деда?</hero> - спросили вы."
              "<npc>- Да " + intQStr(root->gVJob(grandpa_boletus)) + " кг грибов и " + intQStr(root->gVJob(grandpa_bilberry)) + " кг ягод будет достаточно,</npc> - ответил дедушка. <npc>- Только смотри, не заблудись внучка.</npc>";
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
    if(root->gVJob(graze_cow_exp) == 0)
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
    int help = root->gVEvent(grandpahelping);
    if(help == 0 || help == 6 || help == 12 || help == 22)
    {
        root->setDesc(str(1));
        makeActBtn("clean_yard",act(0));
    }
    if(help == 1 || help == 7)
    {
        root->setDesc(str(4));
        makeActBtn("take_firewood",act(2));
    }
    if(help == 2)
    {
        root->setDesc(str(6));
        makeActBtn("feed_horse",act(3));
    }
    if(help == 3)
    {
        root->setDesc(str(8));
        makeActBtn("feed_cow",act(3));
    }
    if(help == 4)
    {
        root->setDesc(str(10));
        makeActBtn("comb_horse",act(3));
    }
    if(help == 5 || help == 13 || help == 23)
    {
        root->setDesc(str(12));
        makeActBtn("feed_boar",act(4));
    }
    if(help == 8 || help == 14 || help == 24)
    {
        if(root->getWeekNum() > 5 || root->getWeekNum() == 0)
        {
            root->setDesc(str(10));
            makeActBtn("comb_horse",act(3));
        }
        else
            no_job_today();
    }
    if(help == 9 || help == 15 || help == 25)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setDesc(str(15));
            makeActBtn("horse_field",act(3));
        }
        else
            no_job_today();
    }
    if(help == 10 || help == 16 || help == 26)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setDesc(str(16));
            makeActBtn("cow_field",act(3));
        }
        else
            no_job_today();
    }
    if(help == 11 || help == 17 || help == 27)
    {
        if(root->getHour() >= 6 && root->getHour() < 9)
        {
            if(root->gVJob(graze_cow_exp) == 0)
                root->setDesc(str(19));
            if(root->gVJob(graze_cow_exp) > 0)
                root->setDesc(str(20));
            makeActBtn("graze_cow",act(5));
        }
        else
            no_job_today();
    }
    if(help == 18 || help == 28)
    {
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && (root->getWeekNum() == 0 || root->getWeekNum() > 5))
        {
            root->setDesc(str(23));
            makeActBtn("horse_river",act(3));
        }
        else
            no_job_today();
    }
    if(help == 19 || help == 29)
    {
        if(root->gVJob(go_in_boletus) == 0 && root->gVJob(go_in_bilberry) == 0 && root->gVJob(go_in_boletus_bilberry) == 0)
        {
            root->sVJob(grandpa_boletus,getRandInt(2,3));
            root->sVJob(go_in_boletus,1);
            root->setDesc(str(24));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 20 || help == 30)
    {
        if(root->gVJob(go_in_boletus) == 0 && root->gVJob(go_in_bilberry) == 0 && root->gVJob(go_in_boletus_bilberry) == 0)
        {
            root->sVJob(grandpa_bilberry,getRandInt(3,5));
            root->sVJob(go_in_bilberry,1);
            root->setDesc(str(25));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 21 || help == 31)
    {
        if(root->gVJob(go_in_boletus) == 0 && root->gVJob(go_in_bilberry) == 0 && root->gVJob(go_in_boletus_bilberry) == 0)
        {
            root->sVJob(grandpa_boletus,getRandInt(2,3));
            root->sVJob(grandpa_bilberry,getRandInt(2,3));
            root->sVJob(go_in_boletus_bilberry,1);
            root->setDesc(str(26));
            makeActBtn("back_to_loc",act(1));
        }
        else
            no_job_today();
    }
    if(help == 32)
    {
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->getHour() >= 6 && root->getHour() < 9)
        {
            root->setDesc(str(27));
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
    root->setDesc(str(14));
    makeActBtn("back_to_loc",act(1));
}
