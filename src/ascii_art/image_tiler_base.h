//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_IMAGE_TILER_BASE_H
#define ASCIIARTPROJECT_IMAGE_TILER_BASE_H

#include <opencv2/core/core.hpp>
#include <deque>

#include "common_types.h"
#include "patch.h"
#include "feature.h"
#include "basis_image.h"

class ImageTilerBase {
public:
//    virtual void createPatches(){};
    virtual void createPatches(const cv::Mat &img, std::vector<std::shared_ptr<PatchBase>>& patches) = 0;
};


#endif //ASCIIARTPROJECT_IMAGE_TILER_BASE_H
