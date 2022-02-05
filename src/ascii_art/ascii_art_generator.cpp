//
//#include "ascii_art_generator.h"
//#include "common_types.h"
//
//AsciiArtGenerator::AsciiArtGenerator(){}
//
//
//void AsciiArtGenerator::loadTargetImage(const std::string& model_image_path) {
//
//    cv::cvtColor(cv::imread(model_image_path), model_image_, cv::COLOR_BGR2GRAY);
////    cv::resize(model_image_, model_image_, cv::Size(), 2,2);
//    model_image_size_x_ = model_image_.cols;
//    model_image_size_y_ = model_image_.rows;
//}
//
//void AsciiArtGenerator::createBaseCharacters() {
//
//    for(int i = 32; i<127;i++){
//        std::string character{(char)i};
//        auto textsize = cv::getTextSize(character, font_type_, 1, 1, 0);
//        base_characters_.emplace_back(BaseSymbol{character,i, textsize.height, textsize.width});
//    }
//    std::cout << "Number of base images created: " << base_characters_.size() << std::endl;
//}
//
//int AsciiArtGenerator::getMaxCharacterHeight() {
//    return std::max_element(base_characters_.begin(), base_characters_.end(),
//                                  [](const BaseSymbol& base1, const BaseSymbol& base2)
//                                  {return base1.height < base2.height;})->height;
//}
//
//int AsciiArtGenerator::getMaxCharacterWidth() {
//
//    return std::max_element(base_characters_.begin(), base_characters_.end(),
//                            [](const BaseSymbol& base1, const BaseSymbol& base2)
//                            {return base1.width < base2.width;})->width;
//}
//
//void AsciiArtGenerator::createBaseImages() {
//
//    auto h_max = getMaxCharacterHeight();
//    auto w_max = getMaxCharacterWidth();
//
//    float k_h = base_fill_ratio_*patch_size_y_/h_max;
//    float k_w = base_fill_ratio_*patch_size_x_/w_max;
//
//    float fontscale;
//    if (k_h < k_w){
//        fontscale = k_h;
//    } else{
//        fontscale = k_w;
//    }
//
//    for (const auto & base : base_characters_){
//        cv::Mat image(patch_size_y_, patch_size_x_, CV_8UC1,
//                      cv::Scalar(255 ));
//
//        if (!image.data) {
//            std::cout << "Could not open or"
//                      << " find the image"
//                      << std::endl;
////            raise some exception?!
//        }
//
//        cv::Point org((patch_size_x_-base.width*fontscale)/2,
//                      patch_size_y_ - (patch_size_y_-base.height*fontscale)/2);
//        cv::putText(image, base.character, org,
//                    font_type_, fontscale,
//                    cv::Scalar(0), 1, cv::LINE_AA);
//
//        auto intesity = cv::mean(image)[0];
//        base_images_.push_back(BaseImage{image, intesity, -1});
//        cv::imwrite("/home/samuel/Desktop/ascii_art_project/characters/character_" + std::to_string(base.ascii_int_value) + ".jpg", image);
//    }
//}
//
//void AsciiArtGenerator::createModelImagePatches() {
//
//    int num_patches_x = model_image_size_x_ / patch_size_x_;
//    int num_patches_y = model_image_size_y_ / patch_size_y_;
//
//    resulting_image_size_x_ = num_patches_x*patch_size_x_;
//    resulting_image_size_y_ = num_patches_y*patch_size_y_;
//
//    for (int i = 0; i<num_patches_x; i++){
//        for (int j = 0; j < num_patches_y; j++){
//
//            ImagePatch patch;
//            patch.x_coord = i*patch_size_x_;
//            patch.y_coord = j*patch_size_y_;
//            patch.image = model_image_(
//                    cv::Rect(
//                            patch.x_coord,patch.y_coord,
//                            patch_size_x_, patch_size_y_));
//            patch.intensity = cv::mean(patch.image)[0];
//
//            model_image_patches_.push_back(patch);
//        }
//    }
//    std::cout << "Nr. of patches x : " << num_patches_x << std::endl;
//    std::cout << "Nr. of patches y : " << num_patches_y << std::endl;
//    std::cout << "resulting image size x : " << resulting_image_size_x_ << std::endl;
//    std::cout << "resulting image size y : " << resulting_image_size_y_ << std::endl;
//}
//
//void AsciiArtGenerator::findClosestBaseImage(const ImagePatch& patch, BaseImage& base_image) {
//
//    auto closest_base = std::min_element(base_images_.begin(), base_images_.end(),
//                     [&](const BaseImage& base1, const BaseImage& base2){
//        return std::abs(base1.intesity_mapped - patch.intensity) < std::abs(base2.intesity_mapped - patch.intensity);
//    });
//
//    base_image = *closest_base;
//}
//
//void AsciiArtGenerator::createEmptyResultingImage() {
//
//    resulting_image_ = cv::Mat(resulting_image_size_y_, resulting_image_size_x_,
//                               CV_8UC1,  cv::Scalar(255 ));
//    std::cout << "Empty image created. Size is :" << resulting_image_size_x_ << "x" << resulting_image_size_y_ << std::endl;
//}
//
//void AsciiArtGenerator::remapIntensitiesOfBaseImages() {
//
//    auto i_max = std::max_element(base_images_.begin(), base_images_.end(),
//                                  [](const BaseImage& img1, const BaseImage& img2)
//                                  {return img1.intesity_original < img2.intesity_original;})->intesity_original;
//
//    auto i_min = std::min_element(base_images_.begin(), base_images_.end(),
//                                  [](const BaseImage& img1, const BaseImage& img2)
//                                  {return img1.intesity_original < img2.intesity_original;})->intesity_original;
//
//    for (auto& img: base_images_){
//        img.intesity_mapped = (img.intesity_original - i_min)*255/(i_max - i_min);
//
//    }
//}
//
//ImagePatch AsciiArtGenerator::getModelImagePatchFromContainer() {
//
//    ImagePatch patch = model_image_patches_.front();
//    model_image_patches_.pop_front();
//    return patch;
//}
//
//void AsciiArtGenerator::fillResultingImage() {
//
//    int counter = 0;
//    while(!model_image_patches_.empty()){
//        ImagePatch patch = getModelImagePatchFromContainer();
//        BaseImage base;
//        findClosestBaseImage(patch, base);
//        std::cout << "writing patch nr. " << counter <<
//                  " with coords :" << patch.x_coord << ", " << patch.y_coord << std::endl;
//        writeBaseImageToResultImage(patch.x_coord, patch.y_coord, base);
//        std::cout << "done" << std::endl;
//        counter++;
//    }
//}
//
//void AsciiArtGenerator::writeBaseImageToResultImage(const int& x_coord, const int& y_coord, const BaseImage& base) {
//
//    base.image.copyTo(
//            resulting_image_(
//                    cv::Rect(x_coord, y_coord, patch_size_x_, patch_size_y_)));
//
//}
//
//void AsciiArtGenerator::showResultingImage() {
//
//    cv::imwrite("/home/samuel/Pictures/ascii_art_project/models/example_01_ascii.jpg", resulting_image_);
////    cv::imshow("result", resulting_image_);
////    cv::waitKey(0);
//}
//
//cv::Mat AsciiArtGenerator::getResultingImage() {
//
//    return resulting_image_;
//}