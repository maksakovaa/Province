#include "swampevents.h"
#include "../../menu/buttons.h"
#include "../../game.h"
#include "../../locations/gadukino/backwater.h"

SwampEvents::SwampEvents(Game *ptr): root(ptr){}

void SwampEvents::start(QString arg)
{
    actionHandler(arg);
}

void SwampEvents::actionHandler(QString action)
{
    if(action == "dress_after_backwater")
    {
        root->vStatus(clothesbackwater) = 0;
        root->vStatus(swamp_clothes) = 0;
        root->changeLoc(root->getCurLoc());
    }
    if(action == "backwater_ralax")
    {
        root->incTime(5);
        root->vEvent(hantersRape) = 3;
        root->setImage(media(0));
        root->setText(str(0));
        root->startEvent(eHanters);
    }
    if(action == "hunter_looks")
    {
        root->incTime(5);
        root->vEvent(hantersday) = root->getDay();
        root->setImage(media(1));
        root->setText(str(1));
        if(root->vStatus(clothesswamphouse) == 1 && root->vStatus(clearClothes) == 0)
            makeActBtn("wear_cloth",act(0));
        else
            makeActBtn("hide",act(1));
        if(root->vStatus(shamelessFlag) > 0)
            makeActBtn("stay_nude",act(2));
    }
    if(action == "wear_cloth")
    {
        root->redressOld();
        root->setImage(media(2));
        root->setText(str(2));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "hide")
    {
        root->incTime(1);
        root->setImage(media(3));
        root->setText(str(3));
        makeActBtn("backwater",act(3));
    }
    if(action == "stay_nude")
    {
        root->vEvent(hanterslut) += 1;
        root->vEvent(hanterknowday) = root->getDay();
        root->setImage(media(4));
        root->setText(str(4));
        makeActBtn("backwater",act(3));
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "backwater")
    {
        root->changeLoc(lbackwater);
    }
}

void SwampEvents::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "swampevents");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SwampEvents::actionHandler);
    root->addActions(btn);
}

QString SwampEvents::str(int id)
{
    QString str[5];
    str[0] = "Сделав свои дела вы присели на берегу отдохнуть.";
    str[1] = "Находясь у затона в чем мать родила, вы вдруг понимаете, что не одни тут. Обернувшись, вы увидели кого-то из охотников. Он просто стоял и смотрел, практически не различимый в своем камуфляже на фоне кустов и деревьев.";
    str[2] = "Вы, сломя голову, кинулись к своей одежде, и в темпе принялись одеваться. Когда, уже одевшись, вы оглянулись, кроме вас у затона никого больше не было.";
    str[3] = "Вы кое-как прикрыв грудь и промежность юркнули в ближайшие кусты. Когда, справившись с испугом и смущением, вы оттуда выглянули, кроме вас у затона никого больше не было.";
    str[4] = "Вы решили, что стеснятся вам нечего, и остались перед мужчиной как есть, полностью обнаженная. Мужчина еще с минуту разглядывал вас, потом хмыкнув голосом Андрея, развернулся и ушел прочь.";
    return str[id];
}

QString SwampEvents::act(int id)
{
    QString str[4];
    str[0] = "Одеться";
    str[1] = "Спрятаться";
    str[2] = "Остаться голышом";
    str[3] = "Далее";
    return str[id];
}

QString SwampEvents::media(int id)
{
    QString med[20];
    med[0] = "data/sex/hantersex/backwaterrelax.jpg";
    med[1] = "data/locations/gadukino/swamp/hunter_looks.jpg";
    med[2] = "data/locations/gadukino/swamp/swampbackwaternude1.jpg";
    med[3] = "data/locations/gadukino/swamp/swampbackwaternude2.jpg";
    med[4] = "data/locations/gadukino/swamp/swampbackwaternude3.jpg";
    return med[id];
}
