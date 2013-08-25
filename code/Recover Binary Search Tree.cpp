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
    
    void checkBST(TreeNode *root, TreeNode *&prev, TreeNode *&t1, TreeNode *&t2){
        if (root == NULL) return;
        checkBST(root->left,  prev, t1, t2);
        if (prev!=NULL && root->val < prev->val){
            t2 = root;
            if (t1 == NULL) t1 = prev;
        }
        prev = root;
        checkBST(root->right, prev, t1, t2);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *t1 = NULL, *t2 = NULL;
        checkBST(root, prev, t1, t2);
        swap(t1->val, t2->val);
    }
};