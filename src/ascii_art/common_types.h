

#ifndef ASCII_ART_PROJECT_COMMON_TYPES_H
#define ASCII_ART_PROJECT_COMMON_TYPES_H

#include <vector>
#include <string>

enum ArtistType {ASCII, MOSAIC, QR};
enum TilerType {RECTANGLE_GRID};
enum BaseCreatorType{ASCII_CHARACTER, IMAGE_FOLDER, HADAMARD};
enum FeatureExtractorType{INTENSITY, GRADIENT, INTENSITY_AND_GRADIENT};


struct ImageSize{
    int width;
    int height;
};

struct BaseSymbol {
    std::string character;
    int ascii_int_value;
    int height;
    int width;
};


struct BaseImagePath{
    std::string image_path;
    double intesity_original;
    double intesity_mapped;
};





#endif //ASCII_ART_PROJECT_COMMON_TYPES_H
