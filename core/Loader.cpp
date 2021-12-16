//
// Created by vuniverse on 12/7/21.
//

#include "Loader.h"
#include "../utility/random_body.h"

namespace {
    std::size_t number_of_files_in_directory(const std::filesystem::path &path) {
        using std::filesystem::directory_iterator;
        return std::distance(directory_iterator(path), directory_iterator{});
    }
}

std::string Loader::load(const std::string& way)
{
    auto i = random_int(0,number_of_files_in_directory(way));
    for(auto& x : (std::filesystem::directory_iterator(way))){
        --i;
        if (i == 0) {
            return x.path();
        }
    }
    return std::filesystem::directory_iterator(way)->path();
}

std::string Loader::load(Stars star)
{
    std::string way {};
    switch (star) {
        case Stars::White:
            way = "../resources/celestial_bodies/stars/white";
            break;
        case Stars::Red:
            way = "../resources/celestial_bodies/stars/red";
            break;
        case Stars::Blue:
            way = "../resources/celestial_bodies/stars/blue";
            break;
        case Stars::Purple:
            way = "../resources/celestial_bodies/stars/purple";
            break;
        case Stars::Other:
            way = "../resources/celestial_bodies/stars/other";
            break;
        case Stars::Black:
            way = "../resources/celestial_bodies/stars/black";
            break;
    }
    return load(way);
}

std::string  Loader::load(Planets planet)
{
    std::string way {};
    switch (planet) {
        case Planets::Wet:
            way = "../resources/celestial_bodies/planets/terran_wet";
            break;
        case Planets::Dry:
            way = "../resources/celestial_bodies/planets/terran_dry";
            break;
        case Planets::Islands:
            way = "../resources/celestial_bodies/planets/islands";
            break;
        case Planets::Stone:
            way = "../resources/celestial_bodies/planets/no_atmosphere";
            break;
        case Planets::Gas:
            way = "../resources/celestial_bodies/planets/gas_giant_1";
            break;
        case Planets::Rings:
            way = "../resources/celestial_bodies/planets/gas_giant_2";
            break;
        case Planets::Ice:
            way = "../resources/celestial_bodies/planets/ice";
            break;
        case Planets::Lava:
            way = "../resources/celestial_bodies/planets/lava";
            break;
    }
    return load(way);
}

std::string  Loader::load(Moons moon)
{
    std::string way {};
    switch (moon) {
        case Moons::Stone:
            way = "../resources/celestial_bodies/planets/no_atmosphere";
            break;
        case Moons::Gas:
            way = "../resources/celestial_bodies/planets/gas_giant_1";
            break;
        case Moons::Ice:
            way = "../resources/celestial_bodies/planets/ice";
            break;
        case Moons::Dry:
            way = "../resources/celestial_bodies/planets/terran_dry";
            break;
    }
    return load(way);
}
/*    for ( auto& item : fs::directory_iterator( dir ) ){
        std::string s=item.path();
        uint16_t size = std::filesystem::file_size(s);
        std::FILE *file = std::fopen( s.c_str(), "rb");

        path = ParsePath(s);
        table.write( path.first, path.second, size, file);
        std::fclose( file );
    }*/
std::string  Loader::load(Asteroid asteroids)
{
    std::string way {};
    switch (asteroids) {
        case Asteroid::Classic:
            way = "../resources/celestial_bodies/asteroids";
            break;
        case Asteroid::Ore:
            way = "../resources/celestial_bodies/asteroids"; //TODO create texture
            break;
        case Asteroid::Material:
            way = "../resources/celestial_bodies/asteroids";
            break;
    }
    return load(way);
}