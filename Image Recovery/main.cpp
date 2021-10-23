#include <QApplication>
#include "MyApplication.h"
#include "genetic_algorithm/ImageCompleter.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MyApplication app;
    ImageCompleter genetics;
    printf("ULTIMO ID: %d\n", genetics.getConcreteIndividual(5).getId());
    return QApplication::exec();
}
