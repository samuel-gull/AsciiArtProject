//
// Created by samuel on 06.01.22.
//

#ifndef ASCII_QT_MAIN_WINDOW_H
#define ASCII_QT_MAIN_WINDOW_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "ascii_art_generator.h"


class AsciiArtMainWindow : public QWidget {

Q_OBJECT

public:
    explicit AsciiArtMainWindow(QWidget *parent = nullptr);
    virtual ~AsciiArtMainWindow() {} ;

    void createLeftGroupBox();
    void createCentralGroupBox();
    void createRightGroupBox();

    void setupMainLayout();

private slots:
    void selectImage();
    void saveImage();
//    void openSettings();
    void createAsciiArt();

private:

    QGroupBox* left_group_box_;
    QGroupBox* central_group_box_;
    QGroupBox* right_group_box_;

    QLabel* model_image_label_;
    QLabel* art_image_label_;

    QPixmap* model_image_pixmap_;
    QPixmap* art_image_pixmap_;
    QImage* art_image_;

    QPushButton* select_file_button_;
    QPushButton* save_file_button_;
    QPushButton* settings_button_;
    QPushButton* create_art_button_;

    QString* selected_image_file_;

    AsciiArtGenerator art_generator_;
};


#endif //ASCII_QT_MAIN_WINDOW_H
