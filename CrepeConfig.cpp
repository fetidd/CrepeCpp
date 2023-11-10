#include "CrepeConfig.h"

const std::string& CrepeConfig::getPattern()
{
    return this->pattern;
}

const std::string& CrepeConfig::getSearchFile()
{
    return this->search_file;
}

void CrepeConfig::setPattern(std::string ptn)
{
    this->pattern = ptn;
}

[[nodiscard]] Result<void> CrepeConfig::setSearchFile(std::string path)
{
    if (path.size() == 0) return std::unexpected(InvalidArgument());
    this->search_file = path;
    return {};
}

Result<void> CrepeConfig::parse(std::vector<std::string>& args)
{
    if (args.size() < 3) throw std::invalid_argument("Need at least two arguments (pattern then file to search in)");
    auto did_set = this->setSearchFile(args[2]);
    if (!did_set) return did_set;
    this->setPattern(args[1]);
    return {};
}

Result<CrepeConfig> create(std::vector<std::string>& args) {
    if (args.size() < 3) {
        return std::unexpected(InvalidArgument());
    }
    else {
        CrepeConfig cc;
        auto res = cc.parse(args); if (!res) return std::unexpected(res.error());
        return cc;
    }
}