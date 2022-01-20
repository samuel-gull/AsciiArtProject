//
// Created by samuel on 20.01.22.
//

#include "feature_extractor_factory.h"
#include "feature_extractor.h"

std::shared_ptr<FeatureExtractorBase> FeatureExtractorFactory::createFeatureExtractor(
        FeatureExtractorType extractor_type) {

    switch (extractor_type) {
        case INTENSITY:
            return std::make_shared<FeatureExtractorIntensity>();
        default:
            return std::make_shared<FeatureExtractorIntensity>();
    }
}