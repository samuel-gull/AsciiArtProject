//
// Created by samuel on 12.01.22.
//

#include "artist_base.h"


cv::Mat ArtistBase::getResultingImage() {
    return resulting_image_;
}

void ArtistBase::extractModelFeatures() {

    /* maybe multithread this */
    for (auto& patch : model_image_patches_){
        feature_extractor_->extract(patch.image, &patch.feature);
    }
}

void ArtistBase::extractBasisFeatures() {

    /* maybe multithread this */
    for (auto& patch : model_image_patches_){
        feature_extractor_->extract(patch.image, &patch.feature);
    }
}

void ArtistBase::createModelImagePatches() {

    image_tiler_->createPatches(model_image_, &model_image_patches_);
}

void ArtistBase::changeFeatureExtractorType(FeatureExtractorType new_type) {
    feature_extractor_type_ = new_type;
}

void ArtistBase::resetFeatureExtractor() {
    feature_extractor_ = FeatureExtractorFactory::createFeatureExtractor(feature_extractor_type_);
}

void ArtistBase::changeImageTilerType(TilerType new_type) {
    tiler_type_ = new_type;
}

void ArtistBase::resetImageTiler() {
    image_tiler_ = TilerFactory::createTiler(tiler_type_);
}

