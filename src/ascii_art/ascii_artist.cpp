//
// Created by samuel on 12.01.22.
//

#include "ascii_artist.h"


AsciiArtist::AsciiArtist() {


}

void AsciiArtist::createEmptyResultingImage() {

    resulting_image_ = cv::Mat(model_image_.rows, model_image_.cols,
                               CV_8UC1,  cv::Scalar(255 ));

}

void AsciiArtist::loadModelImage(const std::string &model_image_path) {
    cv::cvtColor(cv::imread(model_image_path), model_image_, cv::COLOR_BGR2GRAY);
}

void AsciiArtist::createBaseCharacters() {

    for(int i = 32; i<127;i++){
        std::string character{(char)i};
        auto textsize = cv::getTextSize(
                character, font_type_, 1, 1, 0);
        base_characters_.emplace_back(
                BaseSymbol{character,i, textsize.height, textsize.width});
    }
    std::cout << "Number of base images created: " << base_characters_.size() << std::endl;
}

int AsciiArtist::getMaxCharacterHeight() {
    return std::max_element(base_characters_.begin(), base_characters_.end(),
                            [](const BaseSymbol& base1, const BaseSymbol& base2)
                            {return base1.height < base2.height;})->height;
}

int AsciiArtist::getMaxCharacterWidth() {

    return std::max_element(base_characters_.begin(), base_characters_.end(),
                            [](const BaseSymbol& base1, const BaseSymbol& base2)
                            {return base1.width < base2.width;})->width;
}

void AsciiArtist::createBasisImages() {

    auto h_max = getMaxCharacterHeight();
    auto w_max = getMaxCharacterWidth();

    int patch_size_x = RectangularImagePatch::patch_size.width;
    int patch_size_y = RectangularImagePatch::patch_size.height;

    float k_h = base_fill_ratio_*patch_size_x/w_max;
    float k_w = base_fill_ratio_*patch_size_y/h_max;

    float fontscale;
    if (k_h < k_w){
        fontscale = k_h;
    } else{
        fontscale = k_w;
    }

    for (const auto & base : base_characters_){
        cv::Mat image(patch_size_y,
                      patch_size_x,
                      CV_8UC1,
                      cv::Scalar(255 ));

        if (!image.data) {
            std::cout << "Could not open or"
                      << " find the image"
                      << std::endl;
//            raise some exception?!
        }

        cv::Point org((patch_size_x-base.width*fontscale)/2,
                      patch_size_y - (patch_size_y-base.height*fontscale)/2);

        cv::putText(image, base.character, org,
                    font_type_, fontscale,
                    cv::Scalar(0), 1, cv::LINE_AA);

        CharacterImage char_img;
        char_img.image = image;
        basis_images_.push_back(std::make_shared<CharacterImage>(char_img));
//        cv::imwrite("/home/samuel/Desktop/ascii_art_project/characters/character_" + std::to_string(base.ascii_int_value) + ".jpg", basis_images_.back()->getImage());
     }
}

void AsciiArtist::applyTransform() {

    RectangularImagePatch::patch_size = ImageSize{60,80};

    createEmptyResultingImage();
    createBaseCharacters();
//    std::cout << "characters created" << std::endl;
    createBasisImages();

//    std::cout << "basis images created" << std::endl;
    createModelImagePatches();
//    std::cout << "patches created" << std::endl;
    extractModelFeatures();
//    std::cout << "model features extracted" << std::endl;
    extractBasisFeatures();
    remapIntensityFeatures();
//    std::cout << "basis features extracted" << std::endl;

    patches_queue_.clear();
    std::move(model_image_patches_.begin(),
              model_image_patches_.end(),
              std::back_inserter(patches_queue_));

    std::cout << "queue filled" << std::endl;

    /*Todo: multithred this*/

    int counter = 0;
    while(!patches_queue_.empty()){
        std::cout << "queue size is " << patches_queue_.size() << std::endl;
        auto patch = getNextModelImagePatch();
        std::cout << "got patch from queue" << std::endl;
        auto base = findClosestBaseImage(*patch);
        std::cout << "found closest base" << std::endl;
//        std::cout << "base size: " << base->getImage().rows << "x" << base->getImage().cols << std::endl;
//        std::cout << "target size: " << resulting_image_.rows << "x" << resulting_image_.cols << std::endl;

        if (patch){
//            std::cout << "patch size: " << patch->image.rows << "x" << patch->image.cols << std::endl;
        } else {
            std::cout << "patch nullptr " << std::endl;
        }

        patch->fillTarget(*base, resulting_image_);

        counter++;
    }
}


void AsciiArtist::remapIntensityFeatures() {

    std::cout << "get max iterator" << std::endl;
    auto iterator_max = std::max_element(basis_images_.begin(), basis_images_.end(),
                                  [](std::shared_ptr<BasisImageBase>& img1, std::shared_ptr<BasisImageBase>& img2)
                                  {

        return std::dynamic_pointer_cast<IntensityFeature>(img1->feature)->intensity
                                          < std::dynamic_pointer_cast<IntensityFeature>(img2->feature)->intensity;});


    auto max_intensity = std::dynamic_pointer_cast<IntensityFeature>((*iterator_max)->feature)->intensity;


    auto iterator_min = std::min_element(basis_images_.begin(), basis_images_.end(),
                                         [](const std::shared_ptr<BasisImageBase>& img1, const std::shared_ptr<BasisImageBase>& img2)
                                         {return std::dynamic_pointer_cast<const IntensityFeature>(img1->feature)->intensity
                                                 < std::dynamic_pointer_cast<const IntensityFeature>(img2->feature)->intensity;});

    auto min_intensity = std::dynamic_pointer_cast<IntensityFeature>((*iterator_min)->feature)->intensity;

    for (auto& basis : basis_images_){
        auto i = std::dynamic_pointer_cast<IntensityFeature>(std::dynamic_pointer_cast<const CharacterImage>(basis)->feature);
        i->intensity = (i->intensity - min_intensity)*255/(max_intensity - min_intensity);
    }
}




