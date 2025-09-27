#include <algorithm>
#include <vector>

using namespace std;

struct TrieNode {
    bool isWord = false;
    vector<TrieNode *> children{vector<TrieNode *>(26, nullptr)};
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *cur = root;
        for (auto ch: word) {
            if (cur->children[ch - 'a'] == nullptr) {
                TrieNode *node = new TrieNode();
                cur->children[ch - 'a'] = node;
                cur = node;
                continue;
            }
            cur = cur->children[ch - 'a'];
        }
        cur->isWord = true;
    }

    vector<string> findWithPrefix(string &prefix) {
        TrieNode *cur = root;
        for (auto ch: prefix) {
            if (cur->children[ch - 'a'] == nullptr) {
                return vector<string>();
            }
            cur = cur->children[ch - 'a'];
        }
        vector<string> res = vector<string>();
        dfs(cur, prefix, res);
        return res;
    }

    void dfs(TrieNode *cur, string &prefix, vector<string> &res) {
        if (res.size() >= 3) {
            return;
        }
        if (!cur) {
            return;
        }
        if (cur->isWord) {
            res.push_back(prefix);
            if (res.size() >= 3) {
                return;
            }
        }
        for (int i = 0; i < cur->children.size(); ++i) {
            prefix.push_back(char('a' + i));
            dfs(cur->children[i], prefix, res);
            prefix.pop_back();
        }
    }
};

class Solution {
public:
    vector<std::vector<string> > suggestedProducts(vector<string> &products, string searchWord) {
        vector<vector<string> > res = vector<vector<string> >();
        Trie trie = Trie();
        for (const string &word: products) {
            trie.insert(word);
        }

        string prefix = "";
        for (int i = 0; i < searchWord.length(); ++i) {
            vector<string> subRes = vector<string>();
            prefix.push_back(searchWord[i]);
            subRes = trie.findWithPrefix(prefix);
            res.push_back(subRes);
        }
        return res;
    }
};
