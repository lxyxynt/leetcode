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
    bool checkSymmetric(TreeNode *root1, TreeNode *root2){
        if (root1==NULL && root2==NULL) return true;
        if (root1!=NULL && root2==NULL) return false;
        if (root1==NULL && root2!=NULL) return false;
        if (root1->val != root2->val) return false;
        if (!checkSymmetric(root1->left, root2->right)) return false;
        if (!checkSymmetric(root1->right, root2->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode *root) {
        return checkSymmetric(root, root);
    }
};