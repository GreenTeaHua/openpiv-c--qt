#include "generategrid.h"

#include <QColor>
#include <QImage>
#include <iostream>
#include <QPoint>
#include <QList>
#include <QRect>

#include "settings.h"

QList<QPoint> generateGrid(QImage *maskData, Settings *settings)
{
    QList<QPoint> grid;

    int i, j, m, n, count;

    int cAlpha;
    QColor color;
    QRect rect = settings->roi();

    int xSpacing = settings->deltaX();
    int ySpacing = settings->deltaY();

    int _intLengthX = settings->intLengthX();
    int _intLengthY = settings->intLengthY();

    //int imageWidth = settings->imageSize().width();
    //int imageHeight = settings->imageSize().height();

    for (i = rect.top(); i <= (rect.bottom() - _intLengthY); i = i + ySpacing)
    {
        for (j = rect.left(); j <= (rect.right() - _intLengthX); j = j + xSpacing)
        {
            if (!maskData->isNull())
            {
                count = 0;
                for (m = i; m < (i + _intLengthY); m++)
                {
                    for (n = j; n < (j + _intLengthX); n++)
                    {
                        cAlpha = color.fromRgba(maskData->pixel(n,m)).alpha();
                        if (cAlpha != 0) count++;
                    }
                }
                if (count == 0) grid.append(QPoint(j,i));
            }
            else
            {
                grid.append(QPoint(j,i));
            }
        }
    }

    return grid;
}

QList<QPoint> generateGrid(Settings *settings)
{
    QList<QPoint> grid;

    int i, j;

    QRect rect = settings->roi();

    int xSpacing = settings->deltaX();
    int ySpacing = settings->deltaY();

    int _intLengthX = settings->intLengthX();
    int _intLengthY = settings->intLengthY();

    //int imageWidth = settings->imageSize().width();
    //int imageHeight = settings->imageSize().height();

    for (i = rect.top(); i <= (rect.bottom() - _intLengthY); i = i + ySpacing)
    {
        for (j = rect.left(); j <= (rect.right() - _intLengthX); j = j + xSpacing)
        {
            grid.append(QPoint(j,i));
        }
    }

    return grid;
}
