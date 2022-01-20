//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_IMAGE_TILER_BASE_H
#define ASCIIARTPROJECT_IMAGE_TILER_BASE_H

#include <opencv2/core/core.hpp>
#include <deque>

#include "common_types.h"

class ImageTilerBase {
public:
//    virtual void createPatches(){};
    virtual void createPatches(const cv::Mat &img, std::deque<PatchBase>* patches){};
};


#endif //ASCIIARTPROJECT_IMAGE_TILER_BASE_H
