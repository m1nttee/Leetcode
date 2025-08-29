#include <vector>
#include <arm/limits.h>

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
    std::vector<int> result;

    int maxLevelSum(TreeNode *root) {
        dfs(root, 0);
        int maxIndex = 0;
        for (int i = 1; i < result.size(); ++i) {
            if (result[i] > result[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex + 1; // level is index + 1
    }

    void dfs(TreeNode *cur, int depth) {
        if (cur == nullptr) {
            return;
        }
        // first element
        if (depth == result.size()) {
            result.push_back(cur->val);
        } else {
            result[depth] += cur->val;
        }

        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
};
