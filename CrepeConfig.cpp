#include "CrepeConfig.h"

CrepeConfig::CrepeConfig(std::vector<std::string>& args)
{
    this->parse(args);
}


std::string CrepeConfig::getPattern()
{
    return this->m_pattern;
}

std::string CrepeConfig::getSearchFile()
{
    return this->m_search_file;
}


void CrepeConfig::setPattern(std::string ptn)
{
    this->m_pattern = ptn;
}

Result<void> CrepeConfig::setSearchFile(std::string path)
{
    if (path.size() == 0) return std::unexpected(InvalidArgument());
    this->m_search_file = path;
}


void CrepeConfig::parse(std::vector<std::string>& args)
{
    if (args.size() < 3) throw std::invalid_argument("Need at least two arguments (pattern then file to search in)");
    this->setPattern(args[1]);
    this->setSearchFile(args[2]);
}

Result<CrepeConfig> create(std::vector<std::string>& args) {
    if (args.size() < 3) {
        return std::unexpected(InvalidArgument());
    }
    else {
        CrepeConfig cc(args);
        return cc;
    }
}