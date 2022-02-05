//
// Created by samuel on 25.01.22.
//
#include <vector>
#include "feature.h"
#include <iostream>



double IntensityFeature::getDistance(const BaseFeature* other_feature) {

    return std::abs(intensity-dynamic_cast<const IntensityFeature*>(other_feature)->intensity);
}

double IntensityFeature::getDistance(const std::shared_ptr<BaseFeature> other_feature) {

    return std::abs(intensity-std::dynamic_pointer_cast<const IntensityFeature>(other_feature)->intensity);
}

std::string IntensityFeature::print() {
    return std::string("Intensity:") + std::to_string(intensity);
}
//
//double GradientFeature::getDistance(const GradientFeature &other_feature) {return -1;}
//
//
//double IntensityAndGradientFeature::getDistance(const IntensityAndGradientFeature &other_feature) {return -1;}

