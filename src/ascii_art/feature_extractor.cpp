//
// Created by samuel on 13.01.22.
//

#include "feature_extractor.h"


void FeatureExtractorIntensity::extract(const cv::Mat &img, IntensityFeature *feature) {
    feature->intensity = cv::mean(img)[0];
}


