//
// Created by samuel on 13.01.22.
//

#include "feature_extractor.h"
#include <iostream>
#include <memory>

void FeatureExtractorIntensity::extract(const cv::Mat &img, BaseFeature *feature) {

    dynamic_cast<IntensityFeature*>(feature)->intensity = cv::mean(img)[0];
}

void FeatureExtractorIntensity::extract(const cv::Mat &img, std::shared_ptr<BaseFeature>& feature) {

    if(feature) {
        dynamic_pointer_cast<IntensityFeature>(feature)->intensity = cv::mean(img)[0];
    } else {
        feature.reset(new IntensityFeature());
        dynamic_pointer_cast<IntensityFeature>(feature)->intensity = cv::mean(img)[0];
    }
}

std::shared_ptr<BaseFeature>  FeatureExtractorIntensity::computeFeature(const cv::Mat &img) {
    IntensityFeature feature;
    feature.intensity = cv::mean(img)[0];
    std::cout << feature.intensity << std::endl;
    return std::make_shared<IntensityFeature>(feature);
}



