export module CrepeConfig;
import std;
import Error;

export class CrepeConfig {
public:
    CrepeConfig() = default;
    CrepeConfig(std::vector<std::string>& args)
    {
        this->parse(args);
    }

    
    std::string getPattern()
    {
        return this->m_pattern;
    }
    
    std::string getSearchFile()
    {
        return this->m_search_file;
    }

private:
    std::string m_search_file;
    std::string m_pattern;
    bool        ignore_case;

    void setPattern(std::string ptn)
    {
        this->m_pattern = ptn;
    }

    Result<void> setSearchFile(std::string path)
    {
        if (path.size() == 0) return std::unexpected(InvalidArgument());
        this->m_search_file = path;
    }

    
    void parse(std::vector<std::string>& args)
    {
        if (args.size() < 3) throw std::invalid_argument("Need at least two arguments (pattern then file to search in)");
        this->setPattern(args[1]);
        this->setSearchFile(args[2]);
    }
};

export Result<CrepeConfig> create(std::vector<std::string>& args) {
    if (args.size() < 3) {
        return std::unexpected(InvalidArgument());
    }
    else {
        CrepeConfig cc(args);
        return cc;
    }
}