#include "video.h"
#include <QScreen>
#include <QStandardPaths>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QMediaMetaData>

Video::Video(QWidget *parent): QWidget(parent)
{
    m_vplayer = new QMediaPlayer(parent);
    m_video = new QVideoWidget(parent);
    m_vplayer->setVideoOutput(m_video);
    m_vplayer->setLoops(-1);
}

void Video::setQUrl(const QString &url, int width, int height)
{
    this->setFixedSize(width,height);
    m_video->setFixedSize(width,height);
    m_vplayer->setSource(QUrl(url));
    m_vplayer->play();
}

