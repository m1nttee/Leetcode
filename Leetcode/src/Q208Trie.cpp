#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Catigories {
    char value;
    bool isWord = false;
    vector<Catigories *> children;
};

class Trie {
    Catigories *root = nullptr;

public:
    Trie() {
        root = new Catigories();
        root->children = {};
        root->value = 0;
    }

    void insert(std::string word) {
        Catigories *cur = root;
        for (int i = 0; i < word.length(); i++) {
            bool findChar = false;
            for (auto child: cur->children) {
                if (child->value == word[i]) {
                    cur = child;
                    findChar = true;
                    break;
                }
            }
            if (!findChar) {
                auto newNode = new Catigories();
                newNode->value = word[i];
                newNode->children = {};
                cur->children.push_back(newNode);
                cur = newNode;
            }
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Catigories *cur = root;
        for (int i = 0; i < word.length(); i++) {
            bool findChar = false;
            for (auto child: cur->children) {
                if (child->value == word[i]) {
                    cur = child;
                    findChar = true;
                    break;
                }
            }
            if (!findChar) {
                return false;
            }
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        Catigories *cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            bool findChar = false;
            for (auto child: cur->children) {
                if (child->value == prefix[i]) {
                    cur = child;
                    findChar = true;
                    break;
                }
            }
            if (!findChar) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    auto trie = Trie();
    trie.insert("hello");
    std::cout << trie.search("hello") << std::endl;
    return 0;
}