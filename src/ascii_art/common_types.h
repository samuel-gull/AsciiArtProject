

#ifndef ASCII_ART_PROJECT_COMMON_TYPES_H
#define ASCII_ART_PROJECT_COMMON_TYPES_H


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

//struct BaseImage{
//    cv::Mat image;
//    double intesity_original;
//    double intesity_mapped;
//};



struct BaseImagePath{
    std::string image_path;
    double intesity_original;
    double intesity_mapped;
};

//struct ImagePatch{
//    cv::Mat image;
//    double intensity;
//    int x_coord;
//    int y_coord;
//
//    int size_x;
//    int size_y;
//};


struct BaseFeature{

};

struct IntensityFeature : public BaseFeature{
    double intensity;
};

struct GradientFeature : public BaseFeature{
    double grad_x;
    double grad_y;
};

struct IntensityAndGradientFeature : public BaseFeature{
    double grad_x;
    double grad_y;

    double intensity;
};

struct BasisImageBase{
    BaseFeature feature_original;
};

struct BaseImage : public BasisImageBase{
    cv::Mat image;
    BaseFeature feature_mapped;
};

struct PatchBase{
    BaseFeature feature;
    cv::Mat image;
};

struct RectangularImagePatch : public PatchBase{

    int x_coord;
    int y_coord;
    static ImageSize patch_size;
};


#endif //ASCII_ART_PROJECT_COMMON_TYPES_H
