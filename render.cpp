#include "render.h"
#include "menu/mainwindow.h"
#include "menu/ui_mainwindow.h"

Render::Render(QWidget *parent): root(parent){}

void Render::rendVideoPage(QObject* ptr)
{
    handler = ptr;
    resetCurrent();

    w = new QWidget(current);
    m_vplayer = new QMediaPlayer(w);
    m_video = new QVideoWidget(w);
    m_vplayer->setVideoOutput(m_video);
    m_vplayer->setLoops(-1);

    vidLayout = new QVBoxLayout;
    vidLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vidLayout->addWidget(m_video);
    vLayout->addLayout(vidLayout);
    textLbl = new QLabel;
    textLbl->setWordWrap(true);
    textLbl->setAlignment(Qt::AlignTop);
    vLayout->addWidget(textLbl);
    vLayout->setStretch(0,3);
    vLayout->setStretch(1,1);
}

void Render::rendImagePage(QObject* ptr)
{
    handler = ptr;
    resetCurrent();
    
    textLbl = new QLabel;
    textLbl->setWordWrap(true);
    textLbl->setAlignment(Qt::AlignTop);
    imageLbl = new QLabel;
    imageLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vLayout->addWidget(imageLbl);
    vLayout->addWidget(textLbl);
    vLayout->setStretch(0,3);
    vLayout->setStretch(1,1);
}

void Render::rendObjPage(QObject* ptr)
{
    handler = ptr;
    resetCurrent();
}

void Render::setImage(QString path)
{
    qDebug() << "Image: "<< path;
    imageLbl->setText("<img src='" + path + "'></img>");
}

void Render::setText(QString text)
{
    text.replace("<npc>","<span style='color:#800000; font-style: italic;'>");
    text.replace("</npc>","</span>");
    text.replace("<hero>","<span style='color:#000080; font-style: italic;'>");
    text.replace("</hero>","</span>");
    textLbl->setText(text);
}

void Render::addText(QString text)
{
    text.replace("<npc>","<span style='color:#800000; font-style: italic;'>");
    text.replace("</npc>","</span>");
    text.replace("<hero>","<span style='color:#000080; font-style: italic;'>");
    text.replace("</hero>","</span>");
    textLbl->setText(textLbl->text() + "<br>" + text);
}

void Render::setVideo(QString path, int width, int height)
{
    m_video->setFixedSize(width,height);
    m_vplayer->setSource(QUrl(path));
    m_vplayer->play();
}

void Render::addLayoutsInObjPage(QLayout *layout)
{
    vLayout->addLayout(layout);
}

void Render::addQWidgetInObjPage(QWidget *widget)
{
    vLayout->addWidget(widget);
}

QLabel *Render::getTextPtr()
{
    return textLbl;
}

QLabel *Render::getImagePtr()
{
    return imageLbl;
}

void Render::resetCurrent()
{
    if(vLayout != nullptr)
    {
        clearLayout(vLayout);
        delete vLayout;
    }
    if (current != nullptr)
    {
        delete current;
    }

    current = new QWidget;
    vLayout = new QVBoxLayout;
    current->setLayout(vLayout);
    ((MainWindow*)root)->ui->scrollArea->setWidget(current);
}

void Render::clearLayout(QLayout *layout)
{
    if (layout == NULL)
        return;
    QLayoutItem * item;
    while (item = layout->takeAt(0))
    {

        if (item->layout())
        {
            clearLayout(item->layout());
            item->layout()->deleteLater();
        }
        else if (item->widget())
        {
            item->widget()->deleteLater();
        }
        delete item;
    }
}
