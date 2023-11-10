#include <iostream>
#include "Useful.h"
#include "Error.h"
#include "CrepeConfig.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> arguments(argv, argv + argc);
    auto config_result = create(arguments);
    if (config_result) { // program is configured correctly
        auto& cfg = config_result.value();
        auto lines_res = readFile(cfg.getSearchFile());
        if (!lines_res) {
            std::cout << lines_res.error().message << std::endl;
            return 1;
        }
        auto& lines = lines_res.value();

        // logic based on arg flags should decide how to search for the pattern e.g. case, regex

        auto found = searchForPattern(lines, cfg.getPattern());
        std::cout << formatVec(found) << std::endl;
        return 0;
    }
    else {
        std::cout << config_result.error().message << std::endl;
        return 1;
    }
}
