#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class Button : public QPushButton
{
    Q_OBJECT
private:
    QPixmap image;
    QPixmap unpressed_button = QPixmap(":/Buttons1.png");
    QPixmap pressed_button = QPixmap(":/Buttons2.png");
public:
    Button() = default;
    Button(QWidget *parent);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent* e) override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp()
    {
        image = unpressed_button;
        update();
    };
    void setDown(){
        image = pressed_button;
        update();
    };
};

#endif // MAINWINDOW_H
