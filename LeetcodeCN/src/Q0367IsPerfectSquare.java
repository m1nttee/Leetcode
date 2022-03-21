/**
 * @author aiinirii
 */
public class Q0367IsPerfectSquare {
    public static void main(String[] args) {
        System.out.println(new Q0367IsPerfectSquare().isPerfectSquare(1000));
    }

    public boolean isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        int ans;
        while (left <= right) {
            ans = (right - left) / 2 + left;
            if ((long) ans * ans < num) {
                left = ans + 1;
            } else if ((long) ans * ans > num) {
                right = ans - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
