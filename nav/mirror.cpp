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

QString Mirror::getName()
{
    return m_name;
}

QString Mirror::getImage()
{
    return ((MainWindow*)root->root)->m_player->getPlayerFace();
}

QString Mirror::getDesc()
{
    QString text = ((MainWindow*)root->root)->m_player->getHairDesc() + "<br>";
    text += ((MainWindow*)root->root)->m_player->getMakeupDesc() + "<br>";
    text += ((MainWindow*)root->root)->m_player->getLipsDesc() + "<br>";
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
    root->ui->labelObjImage->setText(getImage());
    root->ui->labelObjDesc->setText(getDesc());
    if(root->getVBody(hairStatus) == 0 && ((MainWindow*)root->root)->page4->isHapri())
    {
        makeMirrorActBtn("Причесаться");
    }
    if(root->getVBody(makeup) != 1)
    {
        makeMirrorActBtn("Стереть макияж");
    }
    if(root->getVBody(makeup) == 1 && (root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig)) > 0)
    {
        makeMirrorActBtn("Нанести макияж");
    }
    if (root->getVBody(Body::eyeBrows) >= 0 && root->getVBody(Body::eyeBrows) <= 10)
    {
        makeMirrorActBtn("Выщипывать брови");
    }
    if (root->getItmCount(Items::lipBalm) > 0 && root->getVBody(Body::lipbalmstat) <= 0)
    {
        makeMirrorActBtn("Намазать губы увлажняющим бальзамом");
    }
}


void Mirror::slotMirrorActHandler(QString actName)
{
    if(actName == "Причесаться")
    {
        emit root->sigSpendTime(3);
        root->setVBody(hairStatus, 1);
        emit root->sigUpdParams();
        root->ui->labelObjDesc->setText("Вы расчесали волосы у зеркала");

        makeBackBtn("mirror");
    }
    if(actName == "Стереть макияж")
    {
        ClearLayout(root->m_actLayout);
        root->sigSpendTime(3);
        root->setVBody(makeup, 1);
        emit root->sigUpdParams();
        root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
        root->ui->labelObjDesc->setText("Вы быстро вытерли макияж.");

        makeBackBtn("mirror");
    }
    if(actName == "Нанести макияж")
    {
        ClearLayout(root->m_actLayout);

        makeMirrorActBtn("Лёгкий макияж");

        if(root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig) >= 2)
        {
            makeMirrorActBtn("Нормальный макияж");
        }

        if(root->getItmCount(Items::cosmetic) + root->getItmCount(Items::cosmeticBig) >= 3)
        {
            makeMirrorActBtn("Вызывающий макияж");
        }
        makeBackBtn("mirror");
    }
    if(actName == "Лёгкий макияж")
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
        ((MainWindow*)root->root)->m_player->setVBody(makeup, 2);
        emit root->sigUpdParams();
        root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
        root->ui->labelObjDesc->setText("Вы легонечко подвели глаза и немного подкрасили губы.");

        makeBackBtn("mirror");
    }
    if(actName == "Нормальный макияж")
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
        root->ui->labelObjDesc->setText("Вы накрасили губы, подвели глаза и наложили тени.");

        makeBackBtn("mirror");
    }
    if(actName == "Вызывающий макияж")
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
        root->ui->labelObjDesc->setText("Вы густо накрасили глаза, наложили тени и тушь для ресниц, накрасили контур губ карандашом и губы помадой.");

        makeBackBtn("mirror");
    }

    if(actName == "Выщипывать брови")
    {
        ClearLayout(root->m_actLayout);
        root->sigSpendTime(10);
        root->setVBody(Body::eyeBrows, 19);
        root->updVStatus(Status::mood, -5);
        emit root->sigUpdParams();
        root->ui->labelObjImage->setText("<img src=':/img/objects/mirror/eyebrows.jpg'></img>");
        root->ui->labelObjDesc->setText("Вы выщипали ненужные волоски на бровях придав им красивый контур. Правда это довольно больно.");

        makeBackBtn("mirror");
    }

    if(actName == "Намазать губы увлажняющим бальзамом")
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
        root->ui->labelObjDesc->setText("Вы намазали губы увлажняющим бальзамом.");

        makeBackBtn("mirror");
    }
}


void Mirror::makeMirrorActBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText(text);
    connect(btnx, &ObjActionButton::sigAction, this, &Mirror::slotMirrorActHandler);
    root->m_actLayout->addWidget(btnx);
}

void Mirror::makeBackBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText("Назад");
    connect(btnx, &ObjActionButton::sigAction, root, &ObjViewForm::slotViewObj);
    root->m_actLayout->addWidget(btnx);
}
