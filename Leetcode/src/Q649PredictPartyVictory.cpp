//
// Created by Mingtian Chen on 2025/5/8.
//

#include <queue>
#include <string>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> rQ;
        std::queue<int> dQ;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                rQ.push(i);
            } else if (senate[i] == 'D') {
                dQ.push(i);
            }
        }

        while (!rQ.empty() && !dQ.empty()) {
            std::queue<int> newRQ;
            std::queue<int> newDQ;

            while (!rQ.empty() && !dQ.empty()) {
                auto rQElement = rQ.front();
                auto dQElement = dQ.front();
                rQ.pop();
                dQ.pop();

                if (rQElement < dQElement) {
                    newRQ.push(rQElement);
                }
                if (dQElement < rQElement) {
                    newDQ.push(dQElement);
                }
                // impossible equal
            }

            if (!rQ.empty()) {
                while (!rQ.empty() && !newDQ.empty()) {
                    newRQ.push(rQ.front());
                    rQ.pop();
                    newDQ.pop();
                }
            }

            if (!dQ.empty()) {
                while (!dQ.empty() && !newRQ.empty()) {
                    newDQ.push(dQ.front());
                    dQ.pop();
                    newRQ.pop();
                }
            }

            rQ = newRQ;
            dQ = newDQ;
        }

        if (!dQ.empty()) {
            return "Dire";
        }

        return "Radiant";
    }
};
