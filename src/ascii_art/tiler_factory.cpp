//
// Created by samuel on 20.01.22.
//

#include "tiler_factory.h"

#include <memory>
#include "image_tiler_base.h"
#include "rectangular_grid_tiler.h"

std::shared_ptr<ImageTilerBase> TilerFactory::createTiler(TilerType tiler_type) {

    switch (tiler_type) {
        case RECTANGLE_GRID:
            return std::make_shared<RectangularGridTiler>();
        default:
            return std::make_shared<RectangularGridTiler>();
    }
}
