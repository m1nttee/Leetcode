class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flipsCount = 0;
        while (c > 0 || a > 0 || b > 0) {
            int cr = c % 2;
            c = c / 2;
            int ar = a % 2;
            a = a / 2;
            int br = b % 2;
            b = b / 2;

            if (ar == 0 && br == 0 && cr == 1) {
                flipsCount++;
            }
            if ((ar == 1 || br == 1) && cr == 0) {
                flipsCount += ar + br;
            }
        }
        return flipsCount;
    }
};