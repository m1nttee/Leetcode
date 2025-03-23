//
// Created by AIINIRII on 2025/3/22.
//


#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> map1, map2;
        for (auto char1: word1) {
            map1[char1]++;
        }
        for (auto char2: word2) {
            map2[char2]++;
        }

        if (map1.size() != map2.size()) {
            return false;
        }

        for (auto pair: map1) {
            if (!map2.contains(pair.first)) {
                return false;
            }
        }

        unordered_map<int, int> countMap1, countMap2;
        for (auto pair: map1) {
            countMap1[pair.second]++;
        }
        for (auto pair: map2) {
            countMap2[pair.second]++;
        }

        if (countMap1.size() != countMap2.size()) {
            return false;
        }

        for (auto pair: countMap1) {
            if (countMap2[pair.first] != countMap1[pair.first]) {
                return false;
            }
        }

        return true;
    }
};

// int main(int argc, char *argv[]) {
//     Solution s;
//     std::cout <<
//         s.closeStrings(string("uuukuuuukkuusuususuuuukuskuusuuusuusuuuuuuk"),
//                            string("kssskkskkskssskksskskksssssksskksskskksksuu"))
//     << std::endl;
// }
