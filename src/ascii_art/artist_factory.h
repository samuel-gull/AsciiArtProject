//
// Created by samuel on 20.01.22.
//

#ifndef ASCIIARTPROJECT_ARTIST_FACTORY_H
#define ASCIIARTPROJECT_ARTIST_FACTORY_H

#include "artist_base.h"
#include "common_types.h"

class ArtistFactory{

public:
    static std::shared_ptr<ArtistBase> createArtist(ArtistType artist_type);
};

#endif //ASCIIARTPROJECT_ARTIST_FACTORY_H
