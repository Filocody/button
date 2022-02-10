#include "mainwindow.h"
#include "./ui_mainwindow.h"

Button::Button(QWidget *parent)
{
    setParent(parent);
    setToolTip("Push!");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    image = unpressed_button;
    setGeometry(image.rect());
    move(0, 0);
    QObject::connect(this, &QPushButton::released, this, &Button::setUp);
    QObject::connect(this, &QPushButton::pressed, this, &Button::setDown);
}

void Button::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), image);
}

QSize Button::sizeHint() const
{
    return QSize(100, 100);
}

QSize Button::minimumSizeHint() const
{
    return sizeHint();
}

void Button::keyPressEvent(QKeyEvent *e)
{
    setDown();
}
