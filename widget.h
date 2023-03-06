#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QImage>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    int data_width;
    int data_height;
    double *data;

    int fixed_width;
    int fixed_height;
    QImage *image;

    int start_col;
};

#endif
