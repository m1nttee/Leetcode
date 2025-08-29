#include <algorithm>
#include <queue>

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
    int maxPathLength = 0;

    int longestZigZag(TreeNode *root) {
        dfs(root, false, 0);
        return maxPathLength;
    }

    void dfs(TreeNode *cur, bool isLeft, int step) {
        if (cur == nullptr) {
            return;
        }
        maxPathLength = std::max(maxPathLength, step);

        if (isLeft && cur->left != nullptr) {
            dfs(cur->left, false, step + 1);
        }
        if (isLeft && cur->right != nullptr) {
            dfs(cur->right, true, 1);
        }
        if (!isLeft && cur->right != nullptr) {
            dfs(cur->right, true, step + 1);
        }
        if (!isLeft && cur->left != nullptr) {
            dfs(cur->left, false, 1);
        }
    }
};
