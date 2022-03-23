/**
 * @author aiinirii
 */
public class Q0005LongestPalindrome {
    public static void main(String[] args) {
        System.out.println(new Q0005LongestPalindrome().longestPalindrome("ccc"));
    }

    public String longestPalindrome(String s) {
        int maxLen = 1;
        String maxLenStr = s.substring(0, 1);

        boolean dp[][] = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                maxLen = 2;
                maxLenStr = s.substring(i, i + 2);
            }
        }
        for (int k = 3; k <= s.length(); k++) {
            for (int i = 0; i < s.length() - k + 1; i++) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = k;
                        maxLenStr = s.substring(i, j + 1);
                    }
                }
            }
        }

        return maxLenStr;
    }
}
