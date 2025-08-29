#include <arm/limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* cur, int goodVal) {
        if (cur == nullptr) {
            return 0;
        }
        int goodCount = 0;
        if (cur->val >= goodVal) {
            goodCount += 1;
            goodVal = cur->val;
        }
        goodCount += dfs(cur->left, goodVal);
        goodCount += dfs(cur->right, goodVal);
        return goodCount;
    }
};