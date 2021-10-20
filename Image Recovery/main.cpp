#include <QApplication>
#include "MyApplication.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MyApplication app;
    ImageLoader::loadImage("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images.png", app.window);
    return QApplication::exec();
}
