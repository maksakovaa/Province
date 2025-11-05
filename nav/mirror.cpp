#include "mirror.h"
#include "objviewform.h"
#include "ui_objviewform.h"
#include "../Functions.h"

#include <mainwindow.h>

Mirror::Mirror(QWidget* ptr)
{
    root = (ObjViewForm*)ptr;
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
    return root->player()->getPlayerFace();
}

QString Mirror::getDesc()
{
    QString text = root->player()->getHairDesc() + "<br>";
    text += root->player()->getMakeupDesc() + "<br>";
    text += root->player()->getLipsDesc() + "<br>";
    if(root->getItmCount(Items::cosmetic) > 0 || root->getItmCount(Items::cosmeticBig) > 0)
    {
        text += "Косметика " + intQStr(root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig)) + "<br>";
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
    ClearLayout(root->m_actLayout);
    switch (act)
    {
    case actMirr0:
        {
            root->ui->stackedWidgetObjForm->setCurrentIndex(0);
            root->ui->labelObjImage->setText(getImage());
            root->ui->labelObjDesc->setText(str(actMirr0));
            makeButtons();
        }
        break;
    case actMirr1:
        {
            emit root->sigSpendTime(3);
            root->setVBody(hairStatus, 1);
            emit root->sigUpdParams();
            root->ui->labelObjDesc->setText(str(actMirr1));
            makeButtons();            
        }
        break;
    case actMirr2:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(3);
            root->setVBody(makeup, 1);
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr2));
            makeButtons();
        }
        break;
    case actMirr3:
        {
            ClearLayout(root->m_actLayout);
            makeButtons();
        }
        break;
    case actMirr4:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(3);
            if(root->getItmCount(cosmeticBig) >= 1)
            {
                root->useItem(cosmeticBig,1);
            }
            else
            {
                root->useItem(cosmetic,1);
            }

            root->setVBody(makeup, 2);
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr4));
            makeButtons();
        }
        break;
    case actMirr5:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(5);
            if(root->getItmCount(cosmeticBig) >= 2)
            {
                root->useItem(cosmeticBig, 2);
            }
            else
            {
                root->useItem(cosmetic, 2);
            }
            root->setVBody(makeup, 3);
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_3.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr5));
            makeButtons();
        }
        break;
    case actMirr6:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(3);
            if(root->getItmCount(cosmeticBig) >= 3)
            {
                root->useItem(cosmeticBig, 3);
            }
            else
            {
                root->useItem(cosmetic, 3);
            }
            root->setVBody(makeup, 4);
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_4.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr6));
            makeButtons();
        }
        break;
    case actMirr7:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(10);
            root->setVBody(Body::eyeBrows, 19);
            root->updVStatus(Status::mood, -5);
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/eyebrows.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr7));
            makeButtons();
        }
        break;
    case actMirr8:
        {
            ClearLayout(root->m_actLayout);
            root->sigSpendTime(10);
            root->useItem(Items::lipBalm, 1);
            root->updVBody(Body::lipbalmstat, 8);
            root->updVStatus(Status::lipkoef, 5);
            if (root->getVStatus(Status::lipkoef) >= 50)
            {
                root->setVStatus(Status::lipkoef, 0);
                root->updVBody(Body::lip, 1);
            }
            emit root->sigUpdParams();
            root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/wet_lips.jpg'></img>");
            root->ui->labelObjDesc->setText(str(actMirr8));
            makeButtons();
        }
        break;
    case actMirr9:
        {
            disconnect(root, &ObjViewForm::sigReload, this, &Mirror::reloadActions);
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    }
}

void Mirror::makeButtons()
{
    if (current == MirrorActs::actMirr0)
    {
        if (root->getVBody(hairStatus) == 0 && root->isHapri())
        {
            makeMirrorActBtn(actMirr1);
        }
        if (root->getVBody(makeup) != 1)
        {
            makeMirrorActBtn(actMirr2);
        }
        if (root->getVBody(makeup) == 1 && (root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig)) > 0)
        {
            makeMirrorActBtn(actMirr3);
        }
        if (root->getVBody(Body::eyeBrows) >= 0 && root->getVBody(Body::eyeBrows) <= 10)
        {
            makeMirrorActBtn(actMirr7);
        }
        if (root->getItmCount(Items::lipBalm) > 0 && root->getVBody(Body::lipbalmstat) <= 0)
        {
            makeMirrorActBtn(actMirr8);
        }
        makeMirrorActBtn(actMirr9);
    }
    else if (current == MirrorActs::actMirr3)
    {
        makeMirrorActBtn(actMirr4);

        if (root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig) >= 2)
        {
            makeMirrorActBtn(actMirr5);
        }

        if (root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig) >= 3)
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
    root->m_actLayout->addWidget(btn);
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
