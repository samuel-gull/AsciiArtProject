#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

#include "main_window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AsciiArtMainWindow window;
    window.show();
    return a.exec();
}
