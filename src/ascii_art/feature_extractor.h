//
// Created by samuel on 13.01.22.
//

#ifndef ASCIIARTPROJECT_FEATURE_EXTRACTOR_H
#define ASCIIARTPROJECT_FEATURE_EXTRACTOR_H

#include <opencv2/core/core.hpp>
#include <unordered_map>
#include <functional>

#include "common_types.h"
#include "feature_extractor_base.h"

class FeatureExtractorIntensity : public FeatureExtractorBase {

public:
    void extract(const cv::Mat &img, BaseFeature* feature) override;
    void extract(const cv::Mat &img, std::shared_ptr<BaseFeature>& feature) override;

    std::shared_ptr<BaseFeature>  computeFeature(const cv::Mat& img) override;

};

















//
//
//class other {
//public:
//    other(){
//        FeatureType ft = INTENSITY;
//        int a;
//        auto f = &FeatureExtractor::computeFeatures<intensity_feature>;
////        void (*f)() = &computeFeatures;
//        extraction_map_[INTENSITY] = f;
//    }
//
//    std::unordered_map<FeatureType, void (FeatureExtractor::*)(cv::Mat&, feature_base&)> extraction_map_;
//
////    }
//};

#endif //ASCIIARTPROJECT_FEATURE_EXTRACTOR_H
