//
// Created by samuel on 25.01.22.
//

#ifndef ASCIIARTPROJECT_PATCH_H
#define ASCIIARTPROJECT_PATCH_H

#include <opencv2/core/core.hpp>

#include "feature.h"
#include "common_types.h"
#include "basis_image.h"


struct PatchBase{
    virtual ~PatchBase() = default;
    std::shared_ptr<BaseFeature> feature;
    cv::Mat image;

    virtual void fillTarget(const BasisImageBase& basis, cv::Mat& res_image) = 0;
};

struct RectangularImagePatch : public PatchBase {

    int x_coord;
    int y_coord;
    static ImageSize patch_size;
    void fillTarget(const BasisImageBase& basis, cv::Mat& res_image) override;
};





#endif //ASCIIARTPROJECT_PATCH_H
