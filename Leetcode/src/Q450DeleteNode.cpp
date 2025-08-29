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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root != nullptr && root->val == key) {
            // remove root
            TreeNode *leftNode = root->left;
            if (!leftNode) {
                root = root->right;
            } else if (root->right) {
                root = root->right;
                TreeNode *insertNode = leftNode;
                while (insertNode->right != nullptr) {
                    insertNode = insertNode->right;
                }
                insertNode->right = root->left;
                root->left = leftNode;
            } else {
                root = root->left;
            }

            return root;
        }


        TreeNode *fatherNode = searchBST(root, key);
        if (fatherNode == nullptr) {
            return root;
        }
        if (fatherNode->left && fatherNode->left->val == key) {
            TreeNode *leftNode = fatherNode->left->left;
            if (!leftNode) {
                fatherNode->left = fatherNode->left->right;
            } else if (fatherNode->left->right) {
                fatherNode->left = fatherNode->left->right;
                TreeNode *insertNode = leftNode;
                while (insertNode->right != nullptr) {
                    insertNode = insertNode->right;
                }
                insertNode->right = fatherNode->left->left;
                fatherNode->left->left = leftNode;
            } else {
                fatherNode->left = fatherNode->left->left;
            }
        }
        if (fatherNode->right && fatherNode->right->val == key) {
            TreeNode *leftNode = fatherNode->right->left;
            if (!leftNode) {
                fatherNode->right = fatherNode->right->right;
            } else if (fatherNode->right->right) {
                fatherNode->right = fatherNode->right->right;
                TreeNode *insertNode = leftNode;
                while (insertNode->right != nullptr) {
                    insertNode = insertNode->right;
                }
                insertNode->right = fatherNode->right->left;
                fatherNode->right->left = leftNode;
            } else {
                fatherNode->right = fatherNode->right->left;
            }
        }
        return root;
    }

    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left && root->left->val == val) {
            return root;
        }
        if (root->right && root->right->val == val) {
            return root;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};
