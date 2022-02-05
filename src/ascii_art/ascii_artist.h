//
// Created by samuel on 12.01.22.
//

#ifndef ASCIIARTPROJECT_ASCII_ARTIST_H
#define ASCIIARTPROJECT_ASCII_ARTIST_H

#include <opencv2/highgui/highgui.hpp>

#include "artist_base.h"

class AsciiArtist : public ArtistBase {

public:
    AsciiArtist();

    void loadModelImage(const std::string& model_image_path) override;

    void createBasisImages() override;
    void createEmptyResultingImage() override;

    void applyTransform() override;

    int getMaxCharacterHeight();
    int getMaxCharacterWidth();
    void createBaseCharacters();

    void remapIntensityFeatures();

private:

    std::vector<BaseSymbol> base_characters_;
    cv::HersheyFonts font_type_ = cv::FONT_HERSHEY_TRIPLEX;
    float base_fill_ratio_ = 1;
};


#endif //ASCIIARTPROJECT_ASCII_ARTIST_H
