const int inf = 1999999999;
int ans;
class Solution {
public:
    int dfs(TreeNode *root){
        if (root == NULL) return 0;
        int ret = 0;
        int ans1 = 0, ans2 = 0;
        if (root->left != NULL)
            ans1 = max(ans1, dfs(root->left));
        if (root->right != NULL)
            ans2 = max(ans2, dfs(root->right));
        ret = max(ret, max(ans1, ans2));
        ans = max(ans, ans1 + ans2 + root->val);
        return ret + root->val;
    }
    int maxPathSum(TreeNode *root) {
        ans = -inf;
        dfs(root);
        return ans;
    }
};
