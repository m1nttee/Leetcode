/**
 * @author aiinirii
 */
public class Q0006Convert {
    public String convert(String s, int numRows) {
        String ans;
        if (numRows == 1) {
            ans = s;
        } else if (numRows == 2) {
            StringBuilder stringBuilderOdd = new StringBuilder();
            StringBuilder stringBuilderEven = new StringBuilder();
            boolean isOdd = true;
            for (char c : s.toCharArray()) {
                if (isOdd) {
                    stringBuilderOdd.append(c);
                    isOdd = false;
                } else {
                    stringBuilderEven.append(c);
                    isOdd = true;
                }
            }
            ans = stringBuilderOdd.append(stringBuilderEven).toString();
        } else {
            int length = s.length();
            if (length <= numRows) {
                ans = s;
            } else {
                // find k
                int k = (length - 3) / (2 * numRows - 4);
                // calculate the rest num for the kth group
                int restNum = length - (2 * k * numRows - 2 * k + 1) + 1;

                // fake string
                s += " ".repeat((2 * numRows - 2) - restNum);

                StringBuilder stringBuilder = new StringBuilder();
                for (int i = 0; i <= k; i++) {
                    char c = s.charAt(2 * i * numRows - 2 * i);
                    if (c != ' ') {
                        stringBuilder.append(c);
                    }
                }
                for (int r = 1; r <= numRows - 2; r++) {
                    for (int i = 0; i <= k; i++) {
                        char c1 = s.charAt(2 * i * numRows - 2 * i + 2 + (r - 1) - 1);
                        char c2 = s.charAt(2 * (i + 1) * numRows - 2 * i - 2 - (r - 1) - 1);
                        if (c1 != ' ') {
                            stringBuilder.append(c1);
                        }
                        if (c2 != ' ') {
                            stringBuilder.append(c2);
                        }
                    }
                }
                for (int i = 0; i <= k; i++) {
                    char c = s.charAt((2 * i + 1) * numRows - 2 * i - 1);
                    if (c != ' ') {
                        stringBuilder.append(c);
                    }
                }
                ans = stringBuilder.toString();
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        new Q0006Convert().convert("PAYPALISHIRING", 4);
    }
}
