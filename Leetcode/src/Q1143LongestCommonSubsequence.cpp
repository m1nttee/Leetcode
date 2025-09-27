#include <string>
#include <__memory/shared_ptr.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int res[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            res[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            res[0][j] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    res[i][j] = res[i - 1][j - 1] + 1;
                } else {
                    res[i][j] = max(res[i - 1][j], res[i][j - 1]);
                }
            }
        }
        return res[m][n];
    }
};