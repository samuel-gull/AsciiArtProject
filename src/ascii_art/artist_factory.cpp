//
// Created by samuel on 20.01.22.
//

#include "artist_factory.h"
#include "artist_base.h"
#include "ascii_artist.h"

std::shared_ptr<ArtistBase> ArtistFactory::createArtist(ArtistType artist_type) {

    switch (artist_type) {
        case ASCII:
            return std::shared_ptr<ArtistBase>(new AsciiArtist());
        case MOSAIC:
        case QR:
        default:
            return std::shared_ptr<ArtistBase>(new AsciiArtist());
    }
}