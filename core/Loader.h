//
// Created by vuniverse on 12/7/21.
//

#pragma once

#include <filesystem>
#include "Metadata.h"
#include "../utility/typedefs_and_globals.h"

namespace Loader{
    [[nodiscard]] std::string load(Stars);
    [[nodiscard]] std::string load(Planets);
    [[nodiscard]] std::string load(Moons);
    [[nodiscard]] std::string load(Asteroid);
    [[nodiscard]] std::string load(const std::string& way);
};