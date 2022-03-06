/**
 * @author aiinirii
 */
public class Q1754LargestMerge {
    public String largestMerge(String word1, String word2) {
        int i = 0, j = 0;
        StringBuilder stringBuilder = new StringBuilder();
        while (word1.length() > i || word2.length() > j) {
            if (word1.substring(i).compareTo(word2.substring(j)) < 0) {
                stringBuilder.append(word2.charAt(j));
                j++;
            } else {
                stringBuilder.append(word1.charAt(i));
                i++;
            }
        }
        return stringBuilder.toString();
    }
}
