//
// Created by samuel on 20.01.22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sth.h" resolved

#include "sth.h"

namespace Ui {

    sth::sth(QWidget *parent) :
            QWidget(parent), ui(new Ui::sth) {
        ui->setupUi(this);
    }

    sth::~sth() {
        delete ui;
    }
}

