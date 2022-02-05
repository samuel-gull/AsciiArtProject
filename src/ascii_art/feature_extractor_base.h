//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H
#define ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H


#include <opencv2/core/core.hpp>

#include "common_types.h"
#include "patch.h"
#include "feature.h"
#include "basis_image.h"

class FeatureExtractorBase{
public:
    virtual void extract(const cv::Mat& img, BaseFeature* feature) = 0;
    virtual void extract(const cv::Mat& img, std::shared_ptr<BaseFeature>& feature) = 0;

    virtual std::shared_ptr<BaseFeature> computeFeature(const cv::Mat& img) = 0;


};

#endif //ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H
