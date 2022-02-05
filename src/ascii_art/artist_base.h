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
#include "patch.h"
#include "feature.h"
#include "basis_image.h"
#include "rectangular_grid_tiler.h"
#include "feature_extractor.h"
#include "feature_extractor_factory.h"
#include "tiler_factory.h"

class ArtistBase{

public:
    ArtistBase();
    virtual ~ArtistBase() = default;

    virtual void createBasisImages() = 0;
    virtual void createEmptyResultingImage() = 0;
    virtual std::shared_ptr<PatchBase> getNextModelImagePatch();
    std::shared_ptr<BasisImageBase> findClosestBaseImage(const PatchBase& patch);


    virtual void loadModelImage(const std::string& model_image_path) = 0;
    cv::Mat getResultingImage();

    virtual void applyTransform() = 0;

    void createModelImagePatches();
    void extractModelFeatures();
    void extractBasisFeatures();

    void changeImageTilerType(TilerType new_type);
    void resetImageTiler();

    void changeFeatureExtractorType(FeatureExtractorType new_type);
    void resetFeatureExtractor();


protected:
    cv::Mat model_image_;
    cv::Mat resulting_image_;

    TilerType tiler_type_ = RECTANGLE_GRID;
    FeatureExtractorType feature_extractor_type_ = INTENSITY;

    std::shared_ptr<ImageTilerBase> image_tiler_;
    std::shared_ptr<FeatureExtractorBase> feature_extractor_;

    std::vector<std::shared_ptr<BasisImageBase>> basis_images_;
    std::vector<std::shared_ptr<PatchBase>> model_image_patches_;
    std::deque<std::shared_ptr<PatchBase>> patches_queue_;
private:

    ImageSize model_image_size_;
    ImageSize art_image_size_;
    ImageSize patch_size_{30,50};
};

#endif //ASCIIARTPROJECT_ARTIST_BASE_H
