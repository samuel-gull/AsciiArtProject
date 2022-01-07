//
// Created by samuel on 06.01.22.
//

#include "main_window.h"
#include <iostream>
#include <QDebug>


AsciiArtMainWindow::AsciiArtMainWindow(QWidget *parent) :
        QWidget(parent),
        selected_image_file_(new QString),
        art_generator_(){

    createLeftGroupBox();
    createCentralGroupBox();
    createRightGroupBox();

    setupMainLayout();
}




void AsciiArtMainWindow::setupMainLayout() {

    auto *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(left_group_box_);
    mainLayout->addWidget(central_group_box_);
    mainLayout->addWidget(right_group_box_);

    setLayout(mainLayout);
    setWindowTitle("Ascii Art Generator");
    std::cout << "main layout created" << std::endl;
}

void AsciiArtMainWindow::createLeftGroupBox() {

    left_group_box_ = new QGroupBox(this);
    auto left_box_layout = new QVBoxLayout;

    model_image_label_ = new QLabel("Model Image", this);
    model_image_label_->setAlignment(Qt::AlignCenter);
    model_image_label_->setMinimumSize(500, 800);
    model_image_pixmap_ = new QPixmap();

    select_file_button_ = new QPushButton("Select Image", this);
    connect(select_file_button_, SIGNAL(clicked()),
            this, SLOT(selectImage()));

    left_box_layout->addWidget(model_image_label_, Qt::AlignHCenter);
    left_box_layout->addWidget(select_file_button_);
    left_group_box_->setLayout(left_box_layout);
    std::cout << "left layout created" << std::endl;
}

void AsciiArtMainWindow::createCentralGroupBox() {

    central_group_box_ = new QGroupBox(this);
    auto central_box_layout = new QVBoxLayout;
    central_group_box_->setMaximumSize(300, 600);

    settings_button_ = new QPushButton("Settings", this);
    create_art_button_ = new QPushButton("Run", this);
    connect(create_art_button_, SIGNAL(clicked()), this, SLOT(createAsciiArt()));

    central_box_layout->addWidget(settings_button_);
    central_box_layout->addWidget(create_art_button_);
    central_group_box_->setLayout(central_box_layout);
    std::cout << "central layout created" << std::endl;
}

void AsciiArtMainWindow::createRightGroupBox() {

    right_group_box_ = new QGroupBox(this);
    auto right_box_layout = new QVBoxLayout;

    art_image_pixmap_ = new QPixmap();
    art_image_ = new QImage();

    art_image_label_ = new QLabel("Art Image", this);
    art_image_label_->setAlignment(Qt::AlignCenter);
    art_image_label_->setMinimumSize(500, 800);
    save_file_button_ = new QPushButton("Save Image", this);
    connect(save_file_button_, SIGNAL(clicked()), this, SLOT(saveImage()));

    right_box_layout->addWidget(art_image_label_);
    right_box_layout->addWidget(save_file_button_);
    right_group_box_->setLayout(right_box_layout);

    std::cout << "right layout created" << std::endl;
}

void AsciiArtMainWindow::selectImage() {

    *selected_image_file_ = QFileDialog::getOpenFileName(this);
    std::cout << "selecting image" << std::endl;
    if(model_image_pixmap_->load(*selected_image_file_)){
        std::cout << " image loaded" << std::endl;
        *model_image_pixmap_ = model_image_pixmap_->scaled(model_image_label_->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
        model_image_label_->setPixmap(*model_image_pixmap_);
    }
    std::cout << selected_image_file_->toStdString() << std::endl;
}

void AsciiArtMainWindow::createAsciiArt() {

    if(selected_image_file_){
        art_generator_.loadTargetImage(selected_image_file_->toStdString());
        art_generator_.createModelImagePatches();
        art_generator_.createBaseCharacters();
        art_generator_.createBaseImages();
        art_generator_.remapIntensitiesOfBaseImages();
        art_generator_.createEmptyResultingImage();
        art_generator_.fillResultingImage();
        std::cout << " art created" << std::endl;
        cv::Mat art_mat = art_generator_.getResultingImage();
        std::cout << " art loaded" << std::endl;
        *art_image_ = QImage( art_mat.data,
               art_mat.cols,
               art_mat.rows,
               art_mat.step,
               QImage::Format_Grayscale8);
        std::cout << art_image_->format() << std::endl;
        std::cout << art_image_->width() << " "<< art_image_->height() << std::endl;

        *art_image_pixmap_ = QPixmap::fromImage(*art_image_);
        *art_image_pixmap_ = art_image_pixmap_->scaled(art_image_label_->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
        std::cout << " pixmap created" << std::endl;
        art_image_label_->setPixmap(*art_image_pixmap_);

    }

}

void AsciiArtMainWindow::saveImage() {
    QString save_file_name = QFileDialog::getSaveFileName(this, QString("Worksheet Files (*.png)"));
    std::cout << save_file_name.toStdString() << std::endl;
    art_image_->save(save_file_name + QString(".png"));
}

