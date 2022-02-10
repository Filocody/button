#include <QApplication>
#include "mainwindow.h"
#include <QMediaPlayer>
#include <QMediaContent>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    Button button(&window);
    auto *player = new QMediaPlayer();
    player->setVolume(100);
    QObject::connect(&button, &QPushButton::pressed, [player] {
        player->setMedia(QUrl("qrc:/click_pressed.mp3"));
        player->play();});
    QObject::connect(&button, &QPushButton::released, [player] {
        player->setMedia(QUrl("qrc:/click_released.mp3"));
        player->play();});
    window.setFixedSize(150, 150);
    window.move(1200, 500);
    window.show();

    return QApplication::exec();
}
