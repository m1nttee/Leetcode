import java.util.Arrays;
import java.util.HashSet;
import java.util.stream.Collectors;

/**
 * @author aiinirii
 */
public class I1713Respace {
    public static void main(String[] args) {
        System.out.println(new I1713Respace().respace(new String[]{"looked", "just", "like", "her", "brother"},
                "jesslookedjustliketimherbrother"));
    }

    public int respace(String[] dictionary, String sentence) {
        HashSet<String> dictionarySet = Arrays.stream(dictionary).collect(Collectors.toCollection(HashSet::new));
        int[] dp = new int[sentence.length() + 1];
        dp[0] = 0;
        for (int i = 1; i < sentence.length() + 1; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j < i + 1; j++) {
                if (dictionarySet.contains(sentence.substring(j - 1, i))) {
                    dp[i] = Math.min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[sentence.length()];
    }

}
