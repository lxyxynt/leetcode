class Solution {
public:
    int dfs(TreeNode *root, int deep){
        if (root == NULL) return deep;
        return max(dfs(root->left,  deep+1), dfs(root->right, deep+1));
    }
    int maxDepth(TreeNode *root) {
        return dfs(root, 0);
    }
};
