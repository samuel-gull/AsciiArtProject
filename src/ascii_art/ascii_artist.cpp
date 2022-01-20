//
// Created by samuel on 12.01.22.
//

#include "ascii_artist.h"


void AsciiArtist::loadModelImage(const std::string &model_image_path) {
    cv::cvtColor(cv::imread(model_image_path), model_image_, cv::COLOR_BGR2GRAY);
}

//template<>
//void ArtistBase::extractBaseFeatures() {

    /* maybe multithread this */
//    for (auto& base : base_images_){
//        FeatureExtractor a(feature_type_);
//        FeatureExtractor::computeFeatures<a.ftype>(base.image, &base.intesity_original);
//    }
//}

void AsciiArtist::createBaseImages() {}
void AsciiArtist::extractBaseFeatures() {}
void AsciiArtist::applyDefaultConfig() {}
void AsciiArtist::findClosestBaseImage() {}



