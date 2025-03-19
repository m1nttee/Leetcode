cmake_minimum_required(VERSION 3.30)
project(Leetcode)

set(CMAKE_CXX_STANDARD 23)

add_executable(Leetcode
    Leetcode/src/Q1768MergeStringsAlternately.cpp
        Leetcode/src/Q1071GCDOfStrings.cpp
        Leetcode/src/Q1431KidsWithCandies.cpp
        Leetcode/src/Q605CanPlaceFlowers.cpp
        Leetcode/src/Q345ReverseVowelsOfAString.cpp
        Leetcode/src/Q151ReverseWordsInAString.cpp
        Leetcode/src/Q238ProductOfArrayExpectSelf.cpp
        Leetcode/src/Q334IncreasingTripletSubsequence.cpp)
