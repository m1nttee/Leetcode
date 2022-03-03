/**
 * @author aiinirii
 */
public class Q0009IsPalindrome {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            int y = 0;
            int ox = x;
            while (ox != 0) {
                y *= 10;
                y += ox % 10;
                ox /= 10;
            }
            return x == y;
        }
    }
}
