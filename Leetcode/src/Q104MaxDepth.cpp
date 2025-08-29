#include <algorithm>
#include <stack>

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
    int maxDepth(TreeNode *root) {
        return dfs(root);
    }

    int dfs(TreeNode *cur) {
        if (cur == nullptr) {
            return 0;
        }
        int leftMax = dfs(cur->left) + 1;
        int rightMax = dfs(cur->right) + 1;
        return std::max(leftMax, rightMax);
    }
};
