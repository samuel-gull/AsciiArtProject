//
// Created by samuel on 12.01.22.
//

#include "artist_base.h"

ArtistBase::ArtistBase() :
    image_tiler_(TilerFactory::createTiler(tiler_type_)),
    feature_extractor_(FeatureExtractorFactory::createFeatureExtractor(feature_extractor_type_))
{}

cv::Mat ArtistBase::getResultingImage() {
    return resulting_image_;
}

void ArtistBase::extractModelFeatures() {

    /* maybe multithread this */
    for (auto& patch : model_image_patches_){
        feature_extractor_->extract(patch->image, patch->feature);
    }
}

void ArtistBase::extractBasisFeatures() {

    /* maybe multithread this */
    for (auto& img : basis_images_){
        feature_extractor_->extract(img->getImage(), img->feature);
    }
}

void ArtistBase::createModelImagePatches() {
    image_tiler_->createPatches(model_image_, model_image_patches_);
    std::cout << "number of patches: " << model_image_patches_.size() << std::endl;
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

std::shared_ptr<BasisImageBase> ArtistBase::findClosestBaseImage(const PatchBase& patch) {

    /* Todo: Readability sucks!!!*/

    auto closest_base = std::min_element(basis_images_.begin(), basis_images_.end(),
                                         [&](const std::shared_ptr<BasisImageBase>& basis1, const std::shared_ptr<BasisImageBase>& basis2){
                                             return basis1->feature->getDistance(patch.feature) <
                                             basis2->feature->getDistance(patch.feature);});

    return *closest_base;
}

std::shared_ptr<PatchBase> ArtistBase::getNextModelImagePatch() {
    auto patch = patches_queue_.front();
    patches_queue_.pop_front();
    return patch;
}
