#include <vector>
using namespace std;

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
    vector<int> result;

    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *cur, int depth) {
        if (cur == nullptr) {
            return;
        }

        // first element
        if (result.size() == depth) {
            result.push_back(cur->val);
        } else {
            result[depth] = cur->val;
        }

        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
};
