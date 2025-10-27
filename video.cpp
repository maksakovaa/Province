#include "video.h"
#include <QScreen>
#include <QGraphicsVideoItem>
#include <QStandardPaths>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>

Video::Video(QWidget *parent): QWidget(parent)
{
    m_mediaPlayer = new QMediaPlayer(parent);
    videoWidget = new QVideoWidget(parent);
    m_mediaPlayer->setVideoOutput(videoWidget);
    m_mediaPlayer->setLoops(-1);
}

void Video::setQUrl(const QString &url)
{
    QUrl link = QUrl(url);
    m_mediaPlayer->setSource(link);
    videoWidget->setFixedSize(900,600);
    m_mediaPlayer->play();
}

