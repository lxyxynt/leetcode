vector<TreeNode*> ans;
class Solution {
public:
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        ans.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode *root) {
        ans.clear();
        dfs(root);
        for (int i=0;i+1<ans.size();++i){
            ans[i]->left  = NULL;
            ans[i]->right = ans[i+1];
        }
    }
};
