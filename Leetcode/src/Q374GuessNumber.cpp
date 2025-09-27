/**
* Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n + 1, g = (low + high) / 2;
        int guessRes = guess(g);
        while (guessRes != 0) {
            if (guessRes > 0) {
                low = g;
                g = (low + high) / 2;
            } else {
                high = g;
                g = (high + low) / 2;
            }
            guessRes = guess(g);
        }
        return g;
    }
};