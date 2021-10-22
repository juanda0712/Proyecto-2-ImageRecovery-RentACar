#include <QApplication>
#include "MyApplication.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MyApplication app;
    return QApplication::exec();
}
