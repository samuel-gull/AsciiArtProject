
#ifndef ASCII_ART_PROJECT_ASCII_ART_GENERATOR_H
#define ASCII_ART_PROJECT_ASCII_ART_GENERATOR_H

#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <deque>
#include <functional>
#include <chrono>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>





#include "common_types.h"

class AsciiArtGenerator{

public:
    AsciiArtGenerator();

    void createBaseCharacters();
    void createBaseImages();
    void loadTargetImage(const std::string& model_image_path);

    void findClosestBaseImage(const ImagePatch& patch, BaseImage& base_image);
    void createModelImagePatches();
    ImagePatch getModelImagePatchFromContainer();
    void writeBaseImageToResultImage(const int& x_coord, const int& y_coord, const BaseImage& base);
    void fillResultingImage();
    void showResultingImage();
    cv::Mat getResultingImage();
    void createEmptyResultingImage();

    void remapIntensitiesOfBaseImages();

    int getMaxCharacterHeight();
    int getMaxCharacterWidth();

private:

    std::deque<ImagePatch> model_image_patches_;

    cv::Mat resulting_image_;
    cv::Mat model_image_;

    float base_fill_ratio_ = 1.0;

    int patch_size_x_ = 10;
    int patch_size_y_ = 15;

    int model_image_size_x_;
    int model_image_size_y_;

    int resulting_image_size_x_;
    int resulting_image_size_y_;

    std::vector<BaseImage> base_images_;
    std::vector<BaseSymbol> base_characters_;

    cv::HersheyFonts font_type_ = cv::FONT_HERSHEY_TRIPLEX;
};

#endif //ASCII_ART_PROJECT_ASCII_ART_GENERATOR_H
