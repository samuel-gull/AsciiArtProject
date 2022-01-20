//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H
#define ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H


#include <opencv2/core/core.hpp>

#include "common_types.h"

class FeatureExtractorBase{
public:
    void extract(const cv::Mat& img, BaseFeature* feature){};

};

#endif //ASCIIARTPROJECT_FEATURE_EXTRACTOR_BASE_H
