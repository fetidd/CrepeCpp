#include "pch.h"
import std;
import Useful;
import UsefulTest;

using namespace std;
using namespace UsefulTestNS;

TEST(usefulUnitTests, splitStrCases) {
    EXPECT_EQ(1, 2);
    //EXPECT_EQ(Functions::splitStr("\n"),                    createVector<string>());
    //EXPECT_EQ(Functions::splitStr("one\ntwo"),              createVector("one", "two"));
    //EXPECT_EQ(Functions::splitStr("one\ntwo\n"),            createVector("one", "two"));
    //EXPECT_EQ(Functions::splitStr("one\ntwo\nthree"),       createVector("one", "two", "three"));
    //EXPECT_EQ(Functions::splitStr("one\ntwo\nthree\n"),     createVector("one", "two", "three"));
    //EXPECT_EQ(Functions::splitStr("\none\ntwo\nthree\n"),   createVector("one", "two", "three"));
}

//TEST(usefulUnitTests, formatVecCases) {
//    TestList<vector<string>, string, string> tests{
//      {{}, "", ""},
//      {{"one"}, ", ", "'one'"},
//      {{"one", "two"}, ", ", "'one', 'two'"},
//    };
//    for (auto [input, join_str, exp] : tests) {
//        EXPECT_EQ(exp, Functions::formatVec(input, join_str));
//    }
//}
//
//TEST(usefulUnitTests, readFileCases) {
//    TestList<string, vector<string>> tests{
//      {"../tests/test_file.txt", {"line 1", "line 2", "line 3"}},
//    };
//    for (auto& [input, exp] : tests) {
//        EXPECT_EQ(exp, Functions::readFile(input));
//    }
//}
//
//TEST(usefulUnitTests, readFileFileNotFound) {
//    EXPECT_THROW({
//      try {
//        Functions::readFile("nope.txt");
//      } catch (const std::exception& e) {
//        EXPECT_STREQ("File nope.txt does not exist", e.what());
//        throw;
//      }
//     }, std::invalid_argument);
//}
//
//TEST(usefulUnitTests, searchForPatternCases) {
//    TestList<vector<string>, string, vector<string>> tests{
//      {std::vector<std::string>{}, std::string{""}, std::vector<std::string>{}},
//      {{"hello my name is Ben"}, "", {"hello my name is Ben"}},
//      {{"hello my name is Ben"}, "!!?!#", {}},
//      {{"hello my name is Ben"}, "Ben", {"hello my name is Ben"}},
//      {{"hello my name is Ben"}, "NotBen", {}},
//      {{"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}, "hello my.* name is .+", {"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}},
//      {{"hello my name is Ben", "hello my brother's name is George", "hello my mother's name is Mary"}, "hello my.* name is .*e.*", {"hello my name is Ben", "hello my brother's name is George"}},
//    };
//    for (auto [lines, pattern, exp] : tests) {
//        EXPECT_EQ(exp, Functions::searchForPattern(lines, pattern));
//    }
//}