//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_FEATURE_EXTRACTOR_FACTORY_H
#define ASCIIARTPROJECT_FEATURE_EXTRACTOR_FACTORY_H

#include "feature_extractor_base.h"

class FeatureExtractorFactory{
public:

    static std::shared_ptr<FeatureExtractorBase> createFeatureExtractor(FeatureExtractorType extractor_type);
};
#endif //ASCIIARTPROJECT_FEATURE_EXTRACTOR_FACTORY_H
