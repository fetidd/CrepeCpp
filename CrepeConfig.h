#pragma once

#include <string>
#include <vector>
#include <expected>

#include "Error.h"

class CrepeConfig {
public:
    const std::string& getPattern();
    const std::string& getSearchFile();
    Result<void> parse(std::vector<std::string>& args);

private:
    std::string search_file{ "" };
    std::string pattern{ "" };
    bool        ignore_case{ false };
    bool        use_regex{ false };

    void setPattern(std::string ptn);
    [[nodiscard]] Result<void> setSearchFile(std::string path);
    
};

Result<CrepeConfig> create(std::vector<std::string>& args);