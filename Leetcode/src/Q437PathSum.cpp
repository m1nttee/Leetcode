#include <stack>
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
    int pathSum(TreeNode *root, int targetSum) {
        std::vector<long> ansList;
        return dfs(root, ansList, targetSum);
    }

    long dfs(TreeNode *cur, std::vector<long> &ansList, int target) {
        int count = 0;
        if (cur == nullptr) {
            return 0;
        }
        for (long & i : ansList) {
            i += cur->val;
            if (i == target) {
                count++;
            }
        }
        ansList.push_back(cur->val);
        if (cur->val == target) {
            count++;
        }
        count += dfs(cur->left, ansList, target);
        count += dfs(cur->right, ansList, target);
        ansList.pop_back();
        for (long & i : ansList) {
            i -= cur->val;
        }

        return count;
    }
};
