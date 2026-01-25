#include "mirror.h"
#include "../game.h"
#include "../Functions.h"
#include "../menu/buttons.h"

Mirror::Mirror(Game *ptr): root(ptr)
{
    m_name = "mirror";
}

Mirror::~Mirror()
{

}

void Mirror::reloadActions()
{
    makeButtons();
}

QString Mirror::getName()
{
    return m_name;
}

QString Mirror::getImage()
{
    return root->getPlayerFace();
}

QString Mirror::getDesc()
{
    QString text = root->getHairDesc() + "<br>";
    text += root->getMakeupDesc() + "<br>";
    text += root->getLipsDesc() + "<br>";
    if(root->getItmCount(iCosmetic) > 0 || root->getItmCount(iCosmeticBig) > 0)
    {
        text += "Косметика " + intQStr(root->getItmCount(iCosmetic) + root->getItmCount(iCosmeticBig)) + "<br>";
    }
    else
    {
        text += "У вас нет косметики.<br>";
    }
    return text;
}

void Mirror::viewMirror()
{
    slotMirrorActHandler(actMirr0);
}


void Mirror::slotMirrorActHandler(MirrorActs act)
{
    current = act;
    root->clearActions();
    switch (act)
    {
    case actMirr0:
        {
            root->rendImagePage(root);
            root->getImagePtr()->setText(getImage());
            root->setText(str(actMirr0));
            makeButtons();
        }
        break;
    case actMirr1:
        {
            emit root->incTime(3);
            root->vBody(hairStatus) = 1;
            root->updateParams();
            root->setText(str(actMirr1));
            makeButtons();            
        }
        break;
    case actMirr2:
        {
            root->clearActions();
            root->incTime(3);
            root->vBody(makeup) = 1;
            root->updateParams();
            root->setImage("data/img/objects/mirror/mop_2.jpg");
            root->setText(str(actMirr2));
            makeButtons();
        }
        break;
    case actMirr3:
        {
            root->clearActions();
            makeButtons();
        }
        break;
    case actMirr4:
        {
            root->clearActions();
            root->incTime(3);
            if(root->getItmCount(iCosmeticBig) >= 1)
            {
                root->useItem(iCosmeticBig,1);
            }
            else
            {
                root->useItem(iCosmetic,1);
            }

            root->vBody(makeup) = 2;
            root->updateParams();
            root->setImage("data/img/objects/mirror/mop_2.jpg");
            root->setText(str(actMirr4));
            makeButtons();
        }
        break;
    case actMirr5:
        {
            root->clearActions();
            root->incTime(5);
            if(root->getItmCount(iCosmeticBig) >= 2)
            {
                root->useItem(iCosmeticBig, 2);
            }
            else
            {
                root->useItem(iCosmetic, 2);
            }
            root->vBody(makeup) = 3;
            emit root->updateParams();
            root->setImage("data/img/objects/mirror/mop_3.jpg");
            root->setText(str(actMirr5));
            makeButtons();
        }
        break;
    case actMirr6:
        {
            root->clearActions();
            root->incTime(3);
            if(root->getItmCount(iCosmeticBig) >= 3)
            {
                root->useItem(iCosmeticBig, 3);
            }
            else
            {
                root->useItem(iCosmetic, 3);
            }
            root->vBody(makeup) = 4;
            emit root->updateParams();
            root->setImage("data/img/objects/mirror/mop_4.jpg");
            root->setText(str(actMirr6));
            makeButtons();
        }
        break;
    case actMirr7:
        {
            root->clearActions();
            root->incTime(10);
            root->vBody(Body::eyeBrows) = 19;
            root->vStatus(Status::mood) -= 5;
            emit root->updateParams();
            root->setImage("data/img/objects/mirror/eyebrows.jpg");
            root->setText(str(actMirr7));
            makeButtons();
        }
        break;
    case actMirr8:
        {
            root->clearActions();
            root->incTime(10);
            root->useItem(iLipBalm, 1);
            root->vBody(Body::lipbalmstat) += 8;
            root->vStatus(Status::lipkoef) += 5;
            if (root->vStatus(Status::lipkoef) >= 50)
            {
                root->vStatus(Status::lipkoef) = 0;
                root->vBody(Body::lip) += 1;
            }
            emit root->updateParams();
            root->setImage("data/img/objects/mirror/wet_lips.jpg");
            root->setText(str(actMirr8));
            makeButtons();
        }
        break;
    case actMirr9:
        {
//            disconnect(root, &ObjViewForm::sigReload, this, &Mirror::reloadActions);
            root->changeLoc(root->getCurLoc());
        }
        break;
    }
}

void Mirror::makeButtons()
{
    if (current == MirrorActs::actMirr0)
    {
        if (root->vBody(hairStatus) == 0 && root->isHapri())
        {
            makeMirrorActBtn(actMirr1);
        }
        if (root->vBody(makeup) != 1)
        {
            makeMirrorActBtn(actMirr2);
        }
        if (root->vBody(makeup) == 1 && (root->getItmCount(iCosmetic) + root->getItmCount(iCosmeticBig)) > 0)
        {
            makeMirrorActBtn(actMirr3);
        }
        if (root->vBody(Body::eyeBrows) >= 0 && root->vBody(Body::eyeBrows) <= 10)
        {
            makeMirrorActBtn(actMirr7);
        }
        if (root->getItmCount(iLipBalm) > 0 && root->vBody(Body::lipbalmstat) <= 0)
        {
            makeMirrorActBtn(actMirr8);
        }
        makeMirrorActBtn(actMirr9);
    }
    else if (current == MirrorActs::actMirr3)
    {
        makeMirrorActBtn(actMirr4);

        if (root->getItmCount(iCosmetic) + root->getItmCount(iCosmeticBig) >= 2)
        {
            makeMirrorActBtn(actMirr5);
        }

        if (root->getItmCount(iCosmetic) + root->getItmCount(iCosmeticBig) >= 3)
        {
            makeMirrorActBtn(actMirr6);
        }
        makeMirrorActBtn(actMirr0);
    }
    else
    {
        makeMirrorActBtn(actMirr0);
    }
    
}

void Mirror::makeMirrorActBtn(MirrorActs act)
{
    MirrActionButton* btn = new MirrActionButton(actStr(act), act);
    connect(btn, &MirrActionButton::sigAction, this, &Mirror::slotMirrorActHandler);
    root->addActions(btn);
}

QString Mirror::actStr(MirrorActs type)
{
    QString str[10];
    str[actMirr0] = "Назад";
    str[actMirr1] = "Причесаться";
    str[actMirr2] = "Стереть макияж";
    str[actMirr3] = "Нанести макияж";
    str[actMirr4] = "Лёгкий макияж";
    str[actMirr5] = "Нормальный макияж";
    str[actMirr6] = "Вызывающий макияж";
    str[actMirr7] = "Выщипывать брови";
    str[actMirr8] = "Намазать губы увлажняющим бальзамом";
    str[actMirr9] = "Назад";

    return str[type];
}

QString Mirror::str(MirrorActs type)
{   
    QString str[9];
    str[actMirr0] = getDesc();
    str[actMirr1] = "Вы расчесали волосы у зеркала";
    str[actMirr2] = "Вы быстро вытерли макияж.";
    str[actMirr3] = "";
    str[actMirr4] = "Вы легонечко подвели глаза и немного подкрасили губы.";
    str[actMirr5] = "Вы накрасили губы, подвели глаза и наложили тени.";
    str[actMirr6] = "Вы густо накрасили глаза, наложили тени и тушь для ресниц, накрасили контур губ карандашом и губы помадой.";
    str[actMirr7] = "Вы выщипали ненужные волоски на бровях придав им красивый контур. Правда это довольно больно.";
    str[actMirr8] = "Вы намазали губы увлажняющим бальзамом.";
    return str[type];
}
