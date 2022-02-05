//
// Created by samuel on 25.01.22.
//

#ifndef ASCIIARTPROJECT_BASIS_IMAGE_H
#define ASCIIARTPROJECT_BASIS_IMAGE_H

#include <opencv2/core/core.hpp>

#include "common_types.h"
#include "feature.h"

struct BasisImageBase{
    std::shared_ptr<BaseFeature> feature;
    virtual ~BasisImageBase() = default;
    virtual cv::Mat getImage() const = 0;
};

struct CharacterImage : public BasisImageBase{
    cv::Mat image;
    std::shared_ptr<BaseFeature> feature_original;

    cv::Mat getImage() const override;
};


#endif //ASCIIARTPROJECT_BASIS_IMAGE_H
