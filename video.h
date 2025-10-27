#ifndef VIDEO_H
#define VIDEO_H

#include <QMediaPlayer>
#include <QWidget>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
class QGraphicsVideoItem;
QT_END_NAMESPACE

class Video: public QWidget
{
    Q_OBJECT
public:
    Video(QWidget *parent = nullptr);
    void setQUrl(const QString& url);
private:
    QMediaPlayer *m_mediaPlayer = nullptr;
    QVideoWidget* videoWidget = nullptr;
};

#endif // VIDEO_H
