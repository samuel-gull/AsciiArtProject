//
// Created by samuel on 12.01.22.
//

#include "rectangular_grid_tiler.h"


void RectangularGridTiler::createPatches(const cv::Mat& img,
                                         std::deque<PatchBase>* patches) {

    patches->clear();

    auto patch_width = RectangularImagePatch::patch_size.width;
    auto patch_height = RectangularImagePatch::patch_size.height;

    int num_patches_x = img.cols / patch_width;
    int num_patches_y = img.rows / patch_height;

    for (int i = 0; i<num_patches_x; i++){
        for (int j = 0; j < num_patches_y; j++){
            RectangularImagePatch patch;
            patch.x_coord = i*patch_width;
            patch.y_coord = j*patch_height;
            patch.image = img(cv::Rect(patch.x_coord,patch.y_coord,
                                       patch_width, patch_height));
            patches->push_back(patch);
        }
    }
}