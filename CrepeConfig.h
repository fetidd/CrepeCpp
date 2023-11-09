#pragma once

#include <string>
#include <vector>
#include <expected>

#include "Error.h"

class CrepeConfig {
public:
    CrepeConfig() = default;
    CrepeConfig(std::vector<std::string>& args);

    
    std::string getPattern();
    
    std::string getSearchFile();

private:
    std::string m_search_file;
    std::string m_pattern;
    bool        ignore_case;

    void setPattern(std::string ptn);

    Result<void> setSearchFile(std::string path);

    
    void parse(std::vector<std::string>& args);
};

Result<CrepeConfig> create(std::vector<std::string>& args);