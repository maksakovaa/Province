#include "grandpa.h"
#include "../../menu/buttons.h"
#include "../eventhandler.h"
#include "../../Functions.h"

Grandpa::Grandpa(EventHandler* ptr): root(ptr) {}

void Grandpa::start(QString arg)
{
    actionHandler("grandpa");
}

void Grandpa::actionHandler(QString action)
{
    if(action == "grandpa")
    {
        root->incTime(2);
        if(root->gVEvent(grandpatalkday) != root->vStatus(daystart))
            root->sVEvent(grandpatalk,0);
        if(root->getCurLoc() == lgadgarden)
        {
            if(root->getMonth() == 5 || root->getMonth() == 9)
                root->setImage(media(0));
            else
                root->setImage(media(1));
        }
        else if(root->getCurLoc() == lgaddvor)
            root->setImage(media(2));
        else if(root->getCurLoc() == lgadhouse && (root->getHour() == 7 || root->getHour() == 13 || root->getHour() == 18))
            root->setImage(media(3));
        else if(root->getCurLoc() == lgadsarai)
            root->setImage(media(4));
        else if(root->getCurLoc() == lgadukino)
        {
            if(root->getWeekNum() == 6)
                root->setImage(media(5));
            else
                root->setImage(media(6));
        }
        else
            root->setImage(media(7));
        root->setDesc(str(0));
        int val = root->gVQuest(grandpaQW);
        if(val < 20)
            root->addDesc(str(1));
        if(val >= 20 && val < 40)
            root->addDesc(str(2));
        if(val >= 40 && val < 60)
            root->addDesc(str(3));
        if(val >= 60 && val < 80)
            root->addDesc(str(4));
        if(val >= 80)
            root->addDesc(str(5));
        if(val < 0)
            root->sVQuest(grandpaQW,0);
        if(val > 100)
            root->sVQuest(grandpaQW,100);
        if(root->gVJob(go_in_boletus) == 1)
            root->addDesc(str(6));
        if(root->gVJob(go_in_bilberry) == 1)
            root->addDesc(str(7));
        if(root->gVJob(go_in_boletus_bilberry) == 1)
            root->addDesc(str(8));
        if(root->isNude())
        {
            root->sVEvent(grandpa_notalk,1);
            root->uVQuest(grandpaQW,-5);
            root->sVEvent(grandpaknownude,1);
            root->setDesc(str(9));
        }
        if(root->vStatus(cumFace) > 0 || root->vStatus(cumFrot) > 0)
        {
            root->sVEvent(grandpa_notalk,1);
            root->uVQuest(grandpaQW,-10);
            if(root->gVQuest(grandpaQW) < 40)
            {
                root->setDesc(str(10));
                if(root->gVEvent(grandpa_know) == 0)
                {
                    root->sVEvent(grandpa_know,1);
                    root->setDesc(str(11));
                }
                else
                    root->setDesc(str(12));
            }
            else
                root->setDesc(str(13));

        }
        if(root->vAddict(alko) > 0 && root->getAge() < 20)
        {
            if(root->vAddict(alko) < 3)
                root->setDesc(str(14));
            if(root->vAddict(alko) >= 3 && root->vAddict(alko) < 6)
            {
                root->uVQuest(grandpaQW,-1);
                root->sVEvent(grandpa_notalk,1);
                root->setDesc(str(15));
            }
            if(root->vAddict(alko) >= 6)
            {
                root->uVQuest(grandpaQW,-5);
                root->sVEvent(grandpa_notalk,1);
                root->setDesc(str(16));
            }
        }
        if(root->gVEvent(grandpahelpday) != root->vStatus(daystart) && !root->isNude() && root->gVEvent(grandpa_notalk) == 0 && root->gVEvent(grandmaknowsick) == 0 && root->vAddict(alko) < 3)
            makeActBtn("give_help",act(0));
        if(root->gVEvent(grandpatalkforest) == 0 && root->gVEvent(grandpa_notalk) == 0 && !root->isNude() && root->vAddict(alko) < 3)
            makeActBtn("ask_forest",act(1));
        if(root->getHour() >= root->gVEvent(grandpatalk) + 3 && root->gVEvent(grandpa_notalk) == 0 && !root->isNude() && root->vAddict(alko) < 3)
            makeActBtn("talk",act(3));
        makeActBtn("exit",act(4));
    }
    if(action == "give_help")
    {
        root->sVEvent(grandpahelpday,root->vStatus(daystart));
        root->startEvent(eGrandPaHelp);
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc(),0);
    }
    if(action == "ask_forest")
    {
        root->sVEvent(grandpatalkforest,1);
        root->incTime(10);
        root->uVStatus(mood,5);
        root->uVEvent(goforest,1);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(7));
        root->setDesc(str(17));
        makeActBtn("back_to_loc",act(2));
    }
    if(action == "talk")
    {
        root->sVEvent(grandpatalk,root->getHour());
        root->sVEvent(grandpatalkday,root->getDay());
        root->incTime(10);
        root->uVStatus(mood,getRandInt(5,10));
        if(root->gVQuest(grandpaQW) < 60)
            root->uVQuest(grandpaQW,1);
        root->setImage(media(7));
        if(root->gVQuest(grandpaQW) < 60)
            root->setDesc(str(18));
        if(root->gVQuest(grandpaQW) >= 60)
            root->setDesc(str(19));
        makeActBtn("back_to_loc",act(2));
    }
    if(action == "exit")
    {
        if(root->vAddict(alko) < 6 && !root->isNude())
            actionHandler("back_to_loc");
        if(root->vAddict(alko) < 6 && root->isNude())
            root->changeLoc(lgadhouse,0);
        if(root->vAddict(alko) >= 6)
        {
            root->changeLoc(lgadhouse);
            root->sleep();
        }
    }
}

void Grandpa::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"grandpa");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Grandpa::actionHandler);
    root->addActBtn(btn);
}

QString Grandpa::str(int id)
{
    QString str[20];
    str[0] = "Ваш дедушка, всю жизнь проработавший скотником в колхозе, а после его развала - ещё и в новообразованном ООО \"Скотолэнд\","
             " только недавно вышел на пенсию. У них с бабулей немалое хозяйство и много всякой живности: корова, конёк Буян, поросёнок, "
             "куры, не говоря уж про необходимых в деревне кота-мышелова и пса, охраняющего дом. За молоком, сметаной и яйцами к ним "
             "приезжают даже из города - так что старики особо не бедствуют.";
    str[1] = "У вас с ним ужасный скандал.";
    str[2] = "У вас с ним напряженные отношения.";
    str[3] = "У вас с ним нормальные отношения.";
    str[4] = "У вас с ним хорошие отношения.";
    str[5] = "У вас с ним отличные отношения.";
    str[6] = "Вы обещали принести дедушке " + intQStr(root->gVJob(grandpa_boletus)) + " кг грибов.";
    str[7] = "Вы обещали принести дедушке " + intQStr(root->gVJob(grandpa_bilberry)) + " кг ягод.";
    str[8] = "Вы обещали принести дедушке " + intQStr(root->gVJob(grandpa_boletus)) + " кг грибов и " + intQStr(root->gVJob(grandpa_bilberry)) + " кг ягод.";
    str[9] = "<npc>- Света, ты чего в таком виде разгуливаешь? Я ведь мужик, хоть и твой дед. А ну марш одеваться, пока бабка не увидела!</npc>";
    str[10] = "Дед посмотрел на вас гневным взглядом. На вас была заметна сперма.";
    str[11] = "<npc>- Света, это что такое на тебе? Я думаю, что у меня внучка приличная, а она ебется где-то. Пошла отсюда, глаза б мои тебя не видели!</npc>";
    str[12] = "<npc>- Опять где-то трахалась блядища малолетняя? Ты бы кончину то вытерла, а то вся деревня скоро будет знать, что ты шлюха... Пошла отсюда, глаза б мои тебя не видели!</npc>";
    str[13] = "Дед присмотрелся к вам внимательным взглядом. На вас была заметна сперма. Он нахмурился, но промолчал, и покачав головой пошел прочь.";
    str[14] = "Он принюхался к вам и хмыкнул. Но ничего не сказал.";
    str[15] = "Он принюхался и внимательно глянул на вас:"
              "<npc>- Света, да ты никак пьяная? Ты же еще так молодая совсем, зачем тебе это нужно? Иди приведи себя в порядок, пока бабка не увидела!</npc>";
    str[16] = "Он глянул на вас и удивлённо приподнял брови:"
              "<npc>- Света, да ты напилась как сапожник! Иди-ка ты отдохни, пока бабка тебя, такую красивую, не увидела!</npc>";
    str[17] = "<npc>- А что тут тут рассказывать внучка. Лес как лес. Большой правда. Если пойти вглубь, то без знания леса можно запросто заблудиться. Так что сначала лучше далеко не заходить, грибы с ягодами можно найти и на окраине леса. Правда не так много. В центре леса есть лесное болото, вот вокруг него можно много чего насобирать... и грибов, и ягод. Ночью по лесу вообще лучше не ходить, тут и зверь дикий напасть может, да и вообще места нехорошие."
              "- Если все таки заблудилась внучка, то по темноте лучше костер разведи, да посиди на одном месте до утра. Зверь лесной огня-то боится, близко даже не подходит."
              "- Да вот, еще... Ты в лес особо не наряжайся, попортишь всю свою красивую одежку. В лес лучше ходить в этих.... как их... в жинсах. Во!"
              "- Ну все Света, беги гуляй, все что знал я рассказал.";
    str[18] = "Вы, некоторое время, болтаете со своим дедушкой, но тот ворчит вам о том, что времена давно уже не те, и настоящего русского мужика сейчас днем с огнем не сыщешь.";
    str[19] = "Вы, некоторое время, весело болтаете со своим дедушкой. Он много шутит и рассказывает разные забавные случаи из своей жизни.";
    return str[id];
}

QString Grandpa::act(int id)
{
    QString act[20];
    act[0] = "Предложить помощь";
    act[1] = "Спросить про лес";
    act[2] = "Закончить";
    act[3] = "Поболтать";
    act[4] = "Уйти";
    return act[id];
}

QString Grandpa::media(int id)
{
    QString med[8];
    med[0] = "data/npc/gadukino/grandpa/grandpa_gadgarden.jpg";
    med[1] = "data/npc/gadukino/grandpa/grandpa_fruit_garden.jpg";
    med[2] = "data/npc/gadukino/grandpa/grandpa_gaddvor.jpg";
    med[3] = "data/npc/gadukino/grandpa/grandpa1.jpg";
    med[4] = "data/npc/gadukino/grandpa/grandpa_gadsarai.jpg";
    med[5] = "data/npc/gadukino/grandpa/grandpa_gadukino1.jpg";
    med[6] = "data/npc/gadukino/grandpa/grandpa_gadukino2.jpg";
    med[7] = "data/npc/gadukino/grandpa/grandpa.jpg";
    return med[id];
}
