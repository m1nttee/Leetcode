import java.util.Objects;

/**
 * @author aiinirii
 */
public class Q0028StrStr {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) {
            return 0;
        } else {
            for (int i = 0; i <= haystack.length() - needle.length(); i++) {
                boolean isFound = true;
                for (int j = 0; j < needle.length(); j++) {
                    if (haystack.charAt(i + j) != needle.charAt(j)) {
                        isFound = false;
                        break;
                    }
                }
                if (isFound) {
                    return i;
                }
            }
            return -1;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Q0028StrStr().strStr("Mississippi", "Mississippi"));
    }
}
