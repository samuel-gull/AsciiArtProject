//
// Created by samuel on 25.01.22.
//

#include "patch.h"
#include "iostream"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

ImageSize RectangularImagePatch::patch_size{30,40};

void RectangularImagePatch::fillTarget(const BasisImageBase& basis, cv::Mat& res_image) {

    cv::Mat basis_resized = basis.getImage();
    if(basis_resized.rows != patch_size.height || basis_resized.cols != patch_size.width){

        basis_resized = basis_resized.reshape(0, patch_size.height);

        float basis_aspect = basis_resized.rows/basis_resized.cols;
        float patch_aspect = patch_size.height/patch_size.width;
        if(basis_aspect != patch_aspect) {

            /* Basis Image has the wrong aspect ratio -> crop it */
            int pad_x = (basis_resized.cols - patch_size.width) / 2;
            cv::Rect roi(pad_x, 0, patch_size.width, patch_size.height);
            basis_resized = basis_resized(roi);
        }
    }
    basis_resized.copyTo(res_image(cv::Rect(x_coord, y_coord,
                                               patch_size.width, patch_size.height)));

}
