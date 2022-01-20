//
// Created by samuel on 12.01.22.
//

#ifndef ASCIIARTPROJECT_ASCII_ARTIST_H
#define ASCIIARTPROJECT_ASCII_ARTIST_H

#include "artist_base.h"

class AsciiArtist : public ArtistBase {

public:
    struct Config{

    };

    void loadModelImage(const std::string& model_image_path) override;

//    void extractBasisFeatures() override;

    void createBaseImages() override;
    void findClosestBaseImage() override;
    void applyDefaultConfig() override;

private:

    Config config_;
    Config default_config_backup_;

    std::vector<BaseSymbol> base_characters_;


};


#endif //ASCIIARTPROJECT_ASCII_ARTIST_H
