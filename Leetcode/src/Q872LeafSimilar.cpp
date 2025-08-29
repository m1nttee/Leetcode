#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        std::vector<int> leaves1;
        std::vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        if (leaves1.size() != leaves2.size()) {
            return false;
        }

        while (!leaves1.empty()) {
            if (leaves1.back() != leaves2.back()) {
                return false;
            }
            leaves1.pop_back();
            leaves2.pop_back();
        }
        return true;
    }

    void dfs(TreeNode *cur, std::vector<int> &leaves) {
        if (cur->left == nullptr && cur->right == nullptr) {
            leaves.push_back(cur->val);
            return;
        }
        if (cur->left != nullptr) {
            dfs(cur->left, leaves);
        }
        if (cur->right != nullptr) {
            dfs(cur->right, leaves);
        }
    }
};
