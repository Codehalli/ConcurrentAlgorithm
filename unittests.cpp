//ECE  3574 Project 4
//purpose of the program is apply cuccurent  sorting
//By Pranav Rao
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <string>
#include <sstream>

#include "cqsort.hpp"

template <typename T>
bool is_sorted(const T &vec) {
    for (auto i = 1; i < vec.size(); ++i) {
        if (vec[i-1] > vec[i]) {
            return false;
        }
    }
    return true;
}

//Modified for my own testing
TEST_CASE( "Sequential sort of a vector ints", "[cqsort]" ) {
    // test vector
    std::vector<int> v = {4, 2, 3, 1};
    
    // cqsort for a int vector with zero additional thread
    CQSort<std::vector<int>> cqsort(0);
    
    // sort
    cqsort(v);
    
    // test
    REQUIRE(is_sorted(v) == true);
}
//Modified for my own testing
TEST_CASE( "sort the string", "[cqsort]" ) {
    // test vector
    std::vector<std::string> v = {"d", "c", "a", "b"};
    
    // cqsort for a string vector with zero additional thread
    CQSort<std::vector<std::string>> cqsort(0);
    
    // sort
    cqsort(v);
    
    // test
    REQUIRE(is_sorted(v) == true);
}
//Modified for my own testing
TEST_CASE( "Parallel sort of a vector of ints 2", "[cqsort]" ) {
    // test vector
    std::vector<int> v = {4, 3, 2, 1};
    
    // cqsort for a int vector with two additional threads
    CQSort<std::vector<int>> cqsort(2);
    
    // sort
    cqsort(v);
    
    // test
    REQUIRE(is_sorted(v) == true);
}
//Modified for my own testing
TEST_CASE( "ort the string 2", "[cqsort]" ) {
    // test vector
    std::vector<std::string> v = {"d", "c", "b", "a"};
    
    // cqsort for a string vector with two additional threads
    CQSort<std::vector<std::string>> cqsort(2);
    
    // sort
    cqsort(v);
    
    // test
    REQUIRE(is_sorted(v) == true);
}
