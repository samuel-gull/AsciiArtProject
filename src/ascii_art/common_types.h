

#ifndef ASCII_ART_PROJECT_COMMON_TYPES_H
#define ASCII_ART_PROJECT_COMMON_TYPES_H

struct BaseSymbol {
    std::string character;
    int ascii_int_value;
    int height;
    int width;
};

struct BaseImage{
    cv::Mat image;
    double intesity_original;
    double intesity_mapped;
};

struct ImagePatch{
    cv::Mat image;
    double intensity;
    int x_coord;
    int y_coord;

    int size_x;
    int size_y;
};

#endif //ASCII_ART_PROJECT_COMMON_TYPES_H
