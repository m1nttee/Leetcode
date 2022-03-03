import java.util.Stack;

/**
 * @author aiinirii
 */
public class Q0020IsValid {
    public static void main(String[] args) {
        new Q0020IsValid().isValid("{(())}[()]");
    }

    public boolean isValid(String s) {
        if (s.length() % 2 == 1) {
            return false;
        }

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                Character pC = stack.pop();
                if (!(pC == '(' && c == ')'
                        || pC == '[' && c == ']'
                        || pC == '{' && c == '}')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
