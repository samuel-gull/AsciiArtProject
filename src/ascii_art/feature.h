//
// Created by samuel on 25.01.22.
//

#ifndef ASCIIARTPROJECT_FEATURE_H
#define ASCIIARTPROJECT_FEATURE_H

#include <vector>
#include <memory>

#include "common_types.h"
#include <boost/any.hpp>

struct BaseFeature{
    virtual double getDistance(const BaseFeature* other_feature) = 0;
    virtual double getDistance(std::shared_ptr<BaseFeature> other_feature) = 0;
    virtual std::string print() = 0;
};


struct IntensityFeature : public BaseFeature{
    double intensity = -1;

    double getDistance(const BaseFeature* other_feature) override;
    double getDistance(std::shared_ptr<BaseFeature> other_feature) override;
    std::string print();
};


//struct GradientFeature : public BaseFeature{
//    double grad_x;
//    double grad_y;
//    double getDistance(const GradientFeature& other_feature);
//};
//
//
//struct IntensityAndGradientFeature : public BaseFeature{
//    double grad_x;
//    double grad_y;
//
//    double intensity;
//
//    double getDistance(const IntensityAndGradientFeature& other_feature);
//};

#endif //ASCIIARTPROJECT_FEATURE_H
