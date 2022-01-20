//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_TILER_FACTORY_H
#define ASCIIARTPROJECT_TILER_FACTORY_H

#include "image_tiler_base.h"
#include "common_types.h"

class TilerFactory{

public:
    static std::shared_ptr<ImageTilerBase> createTiler(TilerType tiler_type);


};

#endif //ASCIIARTPROJECT_TILER_FACTORY_H
