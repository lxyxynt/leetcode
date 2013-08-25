class Solution {
public:
    void traversal(TreeNode *root, vector<int> &inorder){
        if (root == NULL) return;
        traversal(root->left,  inorder);
        inorder.push_back(root->val);
        traversal(root->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        inorder.clear();
        traversal(root, inorder);
        return inorder;
    }
};