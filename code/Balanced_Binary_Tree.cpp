class Solution {
public:
    pair<bool,int> dfs(TreeNode *root, int step){
        if (root == NULL) return make_pair(true, step);
        pair<bool,int> ret1 = dfs(root->left,  step+1);
        pair<bool,int> ret2 = dfs(root->right, step+1);
        return make_pair(ret1.first&&ret2.first&&abs(ret1.second-ret2.second)<=1, 
                        max(ret1.second,ret2.second));
    }
    bool isBalanced(TreeNode *root) {
        return dfs(root, 0).first;
    }
};