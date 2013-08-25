class Solution {
public:
    bool dfs(TreeNode *root, int now, int sum){
        now += root->val;
        if (root->left == NULL && root->right == NULL) return (now == sum);
        bool ret = false;
        if (root->left  != NULL)
            ret |= dfs(root->left,  now, sum);
        if (root->right != NULL)
            ret |= dfs(root->right, now, sum);  
        return ret;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return dfs(root, 0, sum);
    }
};
