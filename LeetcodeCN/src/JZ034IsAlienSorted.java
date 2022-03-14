import java.util.HashMap;
import java.util.Map;

import static java.lang.CharSequence.compare;

/**
 * @author aiinirii
 */
public class JZ034IsAlienSorted {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Character> orderMap = new HashMap<>();
        char ic = 'a';
        for (char oC : order.toCharArray()) {
            orderMap.put(oC, ic);
            ic++;
        }
        for (int i = 0; i < words.length; i++) {
            StringBuilder newString = new StringBuilder();
            for (char jc : words[i].toCharArray()) {
                newString.append(orderMap.get(jc));
            }
            words[i] = newString.toString();
        }
        for (int i = 0; i < words.length - 1; i++) {
            if (compare(words[i], words[i + 1]) > 0) {
                return false;
            }
        }
        return true;
    }

}
