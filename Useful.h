#pragma once

#include <vector>
#include <string>
#include <expected>
#include <fstream>
#include <regex>

#include "Error.h"

/* Split a string into a vector of sub strings at the provided split character. Defaults to splitting at newlines (\\n) */
std::vector<std::string> splitStr(std::string input, char split_char = '\n');

/* Format a vector of strings into a nice printable string */
std::string formatVec(std::vector<std::string>& vec, std::string join_str = ", ");

/* Read a file into a vector of lines */
Result<std::vector<std::string>> readFile(std::string file_path);

/* Given a vector of strings, return a vector of strings that match the provided regex pattern */
std::vector<std::string> searchForPattern(std::vector<std::string>& lines, std::string pattern_str);
