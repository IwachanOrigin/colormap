
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>

const unsigned int MAX_X = 512;
const unsigned int MAX_Y = 512;

const int Y = 128;
const int CR = 255;
const int CB = 255;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    scene.clear();

    uchar rData[MAX_X * MAX_Y] = {};
    uchar gData[MAX_X * MAX_Y] = {};
    uchar bData[MAX_X * MAX_Y] = {};
    makeColorMap(rData, gData, bData, MAX_X, MAX_Y);
    unsigned char *pR = &rData[0];
    unsigned char *pG = &gData[0];
    unsigned char *pB = &bData[0];
    QImage image(MAX_X, MAX_Y, QImage::Format_RGB32);
    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            int r = (int)*(pR++);
            int g = (int)*(pG++);
            int b = (int)*(pB++);
            image.setPixel(j, i, qRgb(r, g, b));
        }
    }

    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene.addItem(image_item);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::makeColorMap(unsigned char* rimage
                      , unsigned char* gimage
                      , unsigned char* bimage
                      , int xsize
                      , int ysize)
{
    // rimage, gimage, bimage is a one-dimensional array.
    // If the data in the first column is written, the data in the second column must be written xsize(=512) bytes ahead.

    // Fix the y direction and write data in the x direction.
    // 'i' is y direction
    for (int i = 0; i < ysize; i++)
    {
        // 'j' is x direction
        for (int j = 0; j < xsize; j++)
        {
            int y = Y;
            int cb = (int)((float)(j - xsize / 2) / (float)xsize * CB);
            int cr = (int)((float)(ysize / 2 - i) / (float)ysize * CR);
            int g = (int)(y - 0.29 / 0.587 * cr - 0.114 / 0.587 * cb);
            int r = cr + y;
            int b = cb + y;
            // r
            if ((r <= 255) && (r >= 0)
                && (g <= 255) && (g >= 0)
                && (b <= 255) && (b >= 0))
            {
                rimage[i * xsize + j] = r;
                gimage[i * xsize + j] = g;
                bimage[i * xsize + j] = b;
            }
            else
            {
                rimage[i * xsize + j] = 0;
                gimage[i * xsize + j] = 0;
                bimage[i * xsize + j] = 0;
            }
        }
    }
}
