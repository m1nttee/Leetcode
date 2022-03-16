/**
 * @author aiinirii
 */
public class Q0208Trie {
    class Trie {

        TrieNode root;

        public Trie() {
            root = new TrieNode(false);
        }

        public void insert(String word) {
            TrieNode node = this.root;
            for (char c : word.toCharArray()) {
                // If this child is not initialized yet, initialize it!
                if (node.children[c - 'a'] == null) {
                    node.children[c - 'a'] = new TrieNode(false);
                }

                node = node.children[c - 'a'];
            }
            node.isWordEnd = true;
        }

        public boolean search(String word) {
            TrieNode node = this.root;
            for (char c : word.toCharArray()) {
                if (node.children[c - 'a'] == null) {
                    return false;
                }
                node = node.children[c - 'a'];
            }
            return node.isWordEnd;
        }

        public boolean startsWith(String prefix) {
            TrieNode node = this.root;
            for (char c : prefix.toCharArray()) {
                if (node.children[c - 'a'] == null) {
                    return false;
                }
                node = node.children[c - 'a'];
            }
            return true;
        }

        private class TrieNode {
            TrieNode[] children = new TrieNode[26];
            boolean isWordEnd;

            public TrieNode(boolean isWordEnd) {
                this.isWordEnd = isWordEnd;
            }
        }
    }
}
