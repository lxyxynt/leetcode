vector<vector<int> > ans;
class Solution {
public:
    void dfs(TreeNode *root, int deep){
        if (root == NULL) return;
        if (ans.size() < deep){
            vector<int> ret;
            ret.clear();
            ans.push_back(ret);
        }
        ans[deep-1].push_back(root->val);
        dfs(root->left,  deep+1);
        dfs(root->right, deep+1);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        ans.clear();
        dfs(root, 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
