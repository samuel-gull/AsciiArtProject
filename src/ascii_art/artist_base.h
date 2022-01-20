//
// Created by samuel on 12.01.22.
//

#ifndef ASCIIARTPROJECT_ARTIST_BASE_H
#define ASCIIARTPROJECT_ARTIST_BASE_H

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
#include "rectangular_grid_tiler.h"
#include "feature_extractor.h"
#include "feature_extractor_factory.h"
#include "tiler_factory.h"

//template <typename T>
class ArtistBase{

public:

    virtual void createBaseImages() = 0;
    virtual void findClosestBaseImage() = 0;
    virtual void applyDefaultConfig() = 0;

    virtual void loadModelImage(const std::string& model_image_path) = 0;
    cv::Mat getResultingImage();

//    virtual void createModelImagePatches() = 0;
//    virtual void extractModelFeatures()= 0;
//    virtual void extractBasisFeatures() = 0;

    void createModelImagePatches();
    void extractModelFeatures();
    void extractBasisFeatures();

    void changeImageTilerType(TilerType new_type);
    void resetImageTiler();

    void changeFeatureExtractorType(FeatureExtractorType new_type);
    void resetFeatureExtractor();


//    void setImagePatchSize(const int& width, const int& hight);
//    void setBaseImageSize(const int& width, const int& hight);
//    void scaleModelImage();
//    void scaleArtImage();

protected:
    cv::Mat model_image_;
    cv::Mat resulting_image_;
    TilerType tiler_type_ = RECTANGLE_GRID;
    FeatureExtractorType feature_extractor_type_ = INTENSITY;

    std::shared_ptr<ImageTilerBase> image_tiler_;
    std::shared_ptr<FeatureExtractorBase> feature_extractor_;

private:

    std::deque<PatchBase> model_image_patches_;

    ImageSize model_image_size_;
    ImageSize art_image_size_;
    ImageSize patch_size_{30,50};

    std::vector<BasisImageBase> base_images_;

};

#endif //ASCIIARTPROJECT_ARTIST_BASE_H
