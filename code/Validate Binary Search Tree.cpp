/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    const int inf = 1<<30;
    bool checkBST(TreeNode *root, int low, int up){
        if (root == NULL) return true;
        if (root->val <= low || root->val >= up) return false;
        if (!checkBST(root->left,  low, root->val)) return false;
        if (!checkBST(root->right, root->val, up)) return false;
        return true;
    }
    bool isValidBST(TreeNode *root) {
        return checkBST(root, -inf, inf);
    }
};