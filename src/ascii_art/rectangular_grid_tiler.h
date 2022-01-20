//
// Created by samuel on 12.01.22.
//

#ifndef ASCIIARTPROJECT_RECTANGULAR_GRID_TILER_H
#define ASCIIARTPROJECT_RECTANGULAR_GRID_TILER_H

#include <opencv2/core/core.hpp>

#include "common_types.h"
#include "image_tiler_base.h"

class RectangularGridTiler : public ImageTilerBase{

public:

    void createPatches(const cv::Mat& img,
                       std::deque<PatchBase>* patches) override;

};

//class RectangularGridTiler : public ImageTilerBase<RectangularImagePatch>{
//
//public:
//
//     void createPatches(const cv::Mat& img,
//                        std::vector<RectangularImagePatch>& patches) override;
//
//};


#endif //ASCIIARTPROJECT_RECTANGULAR_GRID_TILER_H
