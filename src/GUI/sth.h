//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_STH_H
#define ASCIIARTPROJECT_STH_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {

class sth : public QWidget {
    Q_OBJECT

public:
    explicit sth(QWidget *parent = nullptr);

    ~sth() override;

private:
    sth *ui;
};

}
QT_END_NAMESPACE


#endif //ASCIIARTPROJECT_STH_H
