#include "wardrobe.h"
#include "Functions.h"
#include "objviewform.h"
#include "ui_objviewform.h"
#include "cloth.h"
#include <QMessageBox>
#include "../customshadoweffect.h"

Wardrobe::Wardrobe(QWidget* ptr): m_size(0)
{
    root = (ObjViewForm*)ptr;
    connect(root->ui->labelHeader, &QLabel::linkActivated, this, &Wardrobe::slotHeader);
}

QString Wardrobe::getName()
{
    return QString();
}

QString Wardrobe::getImage()
{
    return QString();
}

QString Wardrobe::getDesc()
{
    return QString();
}

void Wardrobe::viewWardrobe()
{
    slotActHandler(actWardr0);
}

void Wardrobe::addCloth(Cloth* thing, int count)
{
    if(thing->getClothType() == ClothType::Main)
    {
        ClothMain* ptr = (ClothMain*)thing;
        if(ptr->m_size == -1)
            ptr->m_size = m_size;
        m_storage[ptr] += count;
    }
    else
        m_storage[thing] += count;
}

Cloth* Wardrobe::wearCloth(Cloth* thing)
{
    m_storage[thing] -= 1;
    return thing;
}

void Wardrobe::reloadActions()
{
    makeButtons();
}

void Wardrobe::slotUpdSize(int size)
{
    m_size = size;
}

void Wardrobe::slotActHandler(WardrActs act)
{
    current = act;
    ClearLayout(root->m_actLayout);
    
    switch (act)
    {
    case actWardr0:
    case actWardr5:
    case actWardr11:
        {
            root->ui->stackedWidgetObjForm->setCurrentIndex(1);
            makeButtons();
            root->ui->labelHeader->setText(warStr(actWardr6));
            root->ui->labelHeader->setText(root->ui->labelHeader->text() + "<br>");

            if (!m_layouts.empty())
            {
                for (int i = 0; i < m_layouts.size(); i++)
                {
                    ClearLayout(m_layouts[i]);
                    delete m_layouts[i];
                }
                m_layouts.clear();
            }

            int layoutIndex = 0;
            int elementCounter = 0;
            for (const auto &i : m_storage)
            {
                if (i.first->getClothType() == ClothType::Main && i.second > 0)
                {
                    if (m_layouts.empty())
                    {
                        initNewLayout();
                    }
                    if (elementCounter % 3 == 0 && layoutIndex + 1 >= m_layouts.size())
                    {
                        initNewLayout();
                        layoutIndex++;
                    }
                    ClothForm *form = genForm((ClothMain *)i.first);
                    connect(form, &ClothForm::sigCloth, this, &Wardrobe::clothFormHandler);
                    m_layouts.back()->addWidget(form);
                    elementCounter++;
                }
            }
        }
        break;
    case actWardr2:
        {
            root->ui->stackedWidgetObjForm->setCurrentIndex(0);
            root->player()->redressMain(nullptr);
            root->ui->labelObjImage->setText("<img src=':/img/clothing/0/0.jpg'></img>");
            root->ui->labelObjDesc->setText(warStr(actWardr3));
            makeButtons();
        }
        break;
    case actWardr4:
        {
            QString loc = root->getCurLoc()->getLocId();
            ClothMain* cur = (ClothMain*)root->player()->getCloth(ClothType::Main);
            if (cur != nullptr && cur->getClothGroup() > ClothGroup::swimsuit)
            {
                finalize();
            }
            else if(root->getVStatus(shamelessFlag) >= 2 && loc == "my_bedr_parents" || loc == "bedr" || loc == "korr")
            {
                finalize();
            }
            else
            {
                root->ui->labelHeader->setText(root->ui->labelHeader->text() + warStr(actWardr1));
            }
        }
        break;
    case actWardr7:
        {
            root->videoWidg->setQUrl("qrc:/img/clothing/0/0.webm",900,460);
            root->player()->redressPanties(nullptr);
            root->ui->labelVideoDesc->setText(warStr(actWardr9));
            makeButtons();
            root->ui->stackedWidgetObjForm->setCurrentIndex(2);
        }
        break;
    case actWardr8:
        {
            root->videoWidg->setQUrl("qrc:/img/clothing/0/6.webm",872,600);
            root->player()->redressPanties(m_panties);
            root->ui->labelVideoDesc->setText(warStr(actWardr10));
            makeButtons();
            root->ui->stackedWidgetObjForm->setCurrentIndex(2);
        }
        break;
    case actWardr12:
    {
        ClearLayout(root->m_actLayout);
        root->ui->stackedWidgetObjForm->setCurrentIndex(1);
        makeButtons();

        if (!m_layouts.empty())
        {
            for (int i = 0; i < m_layouts.size(); i++)
            {
                ClearLayout(m_layouts[i]);
                delete m_layouts[i];
            }
            m_layouts.clear();
        }

        int layoutIndex = 0;
        int elementCounter = 0;
        for (const auto &i : m_trash)
        {
            if (m_layouts.empty())
            {
                initNewLayout();
            }
            if (elementCounter % 3 == 0 && layoutIndex + 1 >= m_layouts.size())
            {
                initNewLayout();
                layoutIndex++;
            }
            ClothFormTrash *form = genTrashForm((ClothMain *)i);
            connect(form, &ClothFormTrash::sigCloth, this, &Wardrobe::clotTrashHandler);
            m_layouts.back()->addWidget(form);
            elementCounter++;
        }
    }
    break;
    }
}

void Wardrobe::clothFormHandler(Cloth *cloth, QString action)
{
    if(action == "wear")
    {
        root->player()->redressMain(cloth);
    }
    else if(action == "fit")
    {

    }
    else if(action == "trash")
    {
        m_trash.push_back(cloth);
        m_storage[cloth] = 0;
    }
    else if(action == "remove")
    {
        m_storage[cloth] = 0;
    }
    slotActHandler(actWardr0);
}

void Wardrobe::clotTrashHandler(Cloth *cloth, QString action)
{
    if(action == "toWardrobe")
    {
        m_storage[cloth]++;
        for(int i = 0; i < m_trash.size(); i++)
        {
            if(m_trash[i] == cloth)
            {
                m_trash.erase(m_trash.begin() + i);
            }
        }
    }
    else if(action == "remove")
    {
        for(int i = 0; i < m_trash.size(); i++)
        {
            if(m_trash[i] == cloth)
            {
                delete m_trash[i];
                m_trash.erase(m_trash.begin() + i);
            }
        }
    }
    slotActHandler(actWardr12);
}

void Wardrobe::slotHeader(QString act)
{
    if (act == warStr(12))
    {
        slotActHandler(actWardr12);
    }
    
}

ClothForm *Wardrobe::genForm(ClothMain *cloth)
{
    ClothForm* ptr = new ClothForm(cloth, root->getVBody(hips));
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(6.0);
    bodyShadow->setColor(QColor(0, 0, 0, 80));
    ptr->setGraphicsEffect(bodyShadow);
    return ptr;
}

ClothFormTrash *Wardrobe::genTrashForm(ClothMain *cloth)
{
    ClothFormTrash* ptr = new ClothFormTrash(cloth);
    CustomShadowEffect *bodyShadow = new CustomShadowEffect();
    bodyShadow->setBlurRadius(20.0);
    bodyShadow->setDistance(6.0);
    bodyShadow->setColor(QColor(0, 0, 0, 80));
    ptr->setGraphicsEffect(bodyShadow);
    return ptr;
}

void Wardrobe::initNewLayout()
{
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setAlignment(Qt::AlignLeft);
    m_layouts.push_back(layout);
    root->ui->ObjListLayout->addLayout(m_layouts.back());
}

void Wardrobe::initWarDrobe()
{
    m_size = root->getVBody(hips);
    ClothMain* first = new ClothMain(3, ClothGroup::sundress, "Сарафан",0,-99);
    ClothMain* second = new ClothMain(4, ClothGroup::schoolUniform, "Школьная форма",0,-99);
    ClothMain* third = new ClothMain(getRandInt(10,29), ClothGroup::sportsSuit, "Спортивный костюм");
    ClothMain* four = new ClothMain(getRandInt(30,49), ClothGroup::jeans, "Джинсы");
    m_panties = new ClothPanties(ClothType::Panties);

    addCloth(first,1);
    addCloth(second,1);
    addCloth(third,1);
    addCloth(four,1);
    addCloth(m_panties,3);
    root->player()->wearClothes(first);
    root->player()->wearClothes(m_panties);
}

void Wardrobe::finalize()
{
    disconnect(root, &ObjViewForm::sigReload, this, &Wardrobe::reloadActions);
	// clothesswamphouse = 0
	// clothesbackwater = 0
	// clothesforest = 0
	// swamp_clothes = 0
	if (root->getVStatus(dirtyClothes) > 0) root->setVStatus(dirtyClothes,0);
    root->changeLoc(root->getCurLoc(),1);
}

int Wardrobe::countPanties()
{
    int result = 0;
    if(root->isPanties())
    {
        result += root->player()->getCloth(ClothType::Panties)->getCondition();
        result += m_storage[m_panties] * 500;
    }
    else
    {
        result += m_panties->getCondition();
        result += (m_storage[m_panties] - 1) * 500;
    }
    return result;
}

void Wardrobe::makeButtons()
{
    if (current == actWardr0 || current == actWardr5 || current == actWardr11)
    {
        if (root->getCloth(ClothType::Main) != nullptr)
        {
            ClothMain *upPtr = (ClothMain *)root->getCloth(ClothType::Main);
            if (root->getCurLoc()->getLocId() != "gschool")
                makeActBtn(actWardr2);
            if (upPtr->getClothGroup() >= sundress && root->getCloth(ClothType::Panties) != nullptr)
                makeActBtn(actWardr7);
            else if (upPtr->getClothGroup() >= sundress && root->getCloth(ClothType::Panties) == nullptr && m_storage[m_panties] > 0)
                makeActBtn(actWardr8);
        }
        makeActBtn(actWardr4);
    }
    else if (current == actWardr2)
    {
        makeActBtn(actWardr5);
    }
    else if (current == actWardr7 || current == actWardr8)
    {
        makeActBtn(actWardr5);
    }
    else if(current == actWardr12)
    {
        makeActBtn(actWardr11);
    }
}

void Wardrobe::makeActBtn(WardrActs act)
{
    WardrActionButton* btnx = new WardrActionButton(warStr(act), act);
    connect(btnx, &WardrActionButton::sigAction, this, &Wardrobe::slotActHandler);
    root->m_actLayout->addWidget(btnx);
}

QString Wardrobe::warStr(int index)
{
    QString str[13];
    str[0] = "";
    str[1] = "<p style='color:red; font-size: 30px;'>Вы стесняетесь в таком виде появиться в комнате.</p>";
    str[2] = "Снять одежду";
    str[3] = "Вы полностью разделись";
    str[4] = "Выйти";
    str[5] = "Назад";
    str[6] = "<p style=\"text-align:center\"><strong>Ваш размер: " + intQStr(root->player()->getVBody(hips)) + "</strong><br>На верхней полке лежит купальник.<br>У вас есть еще " + intQStr(countPanties()) + " ед. трусиков.<br>Внизу шкафа стоит <a href='trashbag'>корзина со старой одеждой</a></p>";
    str[7] = "Снять трусики";
    str[8] = "Надеть трусики";
    str[9] = "Вы сняли трусики.";
    str[10] = "Вы надели трусики.";
    str[11] = "В шкаф";
    str[12] = "trashbag";
    return str[index];
}
