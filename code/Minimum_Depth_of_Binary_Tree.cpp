const int inf = 1999999999;
class Solution {
public:
    int dfs(TreeNode *root, int step){
        if (root->left == NULL && root->right == NULL) return step;
        int ret = inf;
        if (root->left  != NULL) 
            ret = min(ret, dfs(root->left,  step+1));
        if (root->right != NULL) 
            ret = min(ret, dfs(root->right, step+1));
        return ret;
    }
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return dfs(root, 1);
    }
};
