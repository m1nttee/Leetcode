//
// Created by AIINIRII on 2025/3/18.
//

#include <iostream>
#include<string>
#include<numeric>

using namespace std;

class Solution {
public:
    bool isDividedByString(string divisorStr, string str) {
        while (!str.empty() && str.length() >= divisorStr.length()) {
            // when find out it's not dividable, exit
            if (str.substr(0, divisorStr.length()) != divisorStr) {
                return false;
            }

            // otherwise, substr the str with divisorStr
            str = str.substr(divisorStr.length());
        }
        return str.empty();
    }

    string gcdOfStrings(string str1, string str2) {
        // find the gcd length of two strings
        size_t gcdLength = gcd(str1.length(), str2.length());

        for (size_t factor = gcdLength; factor > 0; --factor) {
            if (gcdLength % factor == 0) {
                // find the gcd string for two string
                string str1GCDStr = str1.substr(0, factor);
                string str2GCDStr = str2.substr(0, factor);

                // if the gcd string of two string is the divisor
                if (isDividedByString(str1GCDStr, str1) && isDividedByString(str2GCDStr, str2) && str1GCDStr == str2GCDStr) {
                    return str1GCDStr;
                }
            }
        }

        return "";
    }
};

// int main(int argc, char *argv[]) {
//     Solution solution = Solution();
//     string str1 = "AAACCC";
//     string str2 = "AAA";
//     std::cout << solution.gcdOfStrings(str1, str2);
// }
