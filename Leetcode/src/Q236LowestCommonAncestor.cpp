#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    TreeNode *father = nullptr;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return father;
    }

    int dfs(TreeNode *cur, TreeNode *p, TreeNode *q) {
        int count = 0;
        if (father || cur == nullptr) {
            return 0;
        }
        if (cur == p || cur == q) {
            count += 1;
        }
        count += dfs(cur->left, p, q);
        count += dfs(cur->right, p, q);
        if (!father && count == 2) {
            father = cur;
        }
        return count;
    }
};
