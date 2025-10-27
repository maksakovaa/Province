#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QWidget>
#include <QString>
#include <iostream>

int getRandInt(int min, int max);
int getItemArr(int arr[], int arr_size, int id);
QString letgoda(int age);
QString letgoda2(int age);
QString intQStr(int value);
void makeLink(QString& txt, const QString& link);
QString makeImg(QString path);
QString makeImage(QString path, bool isDay, bool isSnow);
QString styleForBar(int value, int maxv, int type);
int getSexuality();
int genDick(int arg = 0);
void ClearLayout(QLayout* layout);

#endif
