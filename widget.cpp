#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>
#include "widget.h"

void data2image(double *data, int data_width, int start_col, QImage *image){
    int ind;
    int rgb;
    QRgb value;
    for(int row=0;row<image->height();row++){
        for(int col=0;col<image->width();col++){
            ind = data_width*row+col+start_col;
            rgb = data[ind];
            value = qRgb(rgb,rgb,rgb);
            image->setPixelColor(col,row,value);
        }
    }
}

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    data_width = 1080;
    data_height = 120;
    data = (double *)malloc(sizeof(double)*data_width*data_height);
    for(int row=0;row<data_height;row++){
        for(int col=0;col<data_width;col++){
            data[data_width*row+col] = QRandomGenerator::global()->bounded(0, 255);
        }
    }

    fixed_width = 315;
    fixed_height = data_height;

    image = new QImage(fixed_width, fixed_height, QImage::Format_RGB888);
    image->fill(Qt::white);
    setFixedSize(fixed_width, fixed_height);

    start_col = 0;
}

Widget::~Widget()
{
    delete image;
    free(data);
}

void Widget::paintEvent(QPaintEvent *)
{
    data2image(data, data_width, start_col, image);

    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        if(start_col+1 <= data_width-fixed_width)
        {
            start_col += 1;
            update();
        }
        break;
    case Qt::Key_Right:
        if(start_col-1 >= 0){
            start_col -= 1;
            update();
        }
        break;
    }
}
