#ifndef RENDER_H
#define RENDER_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>

class Render
{
public:
    Render(QWidget* parent = nullptr);
    void rendVideoPage(QObject* ptr);
    void rendImagePage(QObject* ptr);
    void rendObjPage(QObject* ptr);
    void setImage(QString path);
    void setText(QString text);
    void addText(QString text);
    void setVideo(QString path, int width, int height);
    void addLayoutsInObjPage(QLayout* layout);
    void addQWidgetInObjPage(QWidget* widget);
    QLabel* getTextPtr();
    QLabel* getImagePtr();
private:
    void resetCurrent();
    void clearLayout(QLayout* layout);
    QWidget* root;
    QWidget* current = nullptr;
    QWidget* w = nullptr;
    QVBoxLayout* vLayout = nullptr;
    QVBoxLayout* vidLayout = nullptr;
    QLabel* textLbl;
    QLabel* imageLbl;
    QMediaPlayer* m_vplayer = nullptr;
    QVideoWidget* m_video = nullptr;
    QObject* handler;
};

#endif // RENDER_H
