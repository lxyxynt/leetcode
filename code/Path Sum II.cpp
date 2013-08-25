vector<vector<int> > ans;
vector<int> path;
class Solution {
public:
    void dfs(TreeNode *root, int now, int sum){
        now += root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
            if (now == sum) ans.push_back(path);
            path.resize(path.size()-1);
            return;
        }
        if (root->left  != NULL) dfs(root->left,  now, sum);
        if (root->right != NULL) dfs(root->right, now, sum);  
        path.resize(path.size()-1);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ans.clear();path.clear();
        if (root != NULL) dfs(root, 0, sum);
        return ans;
    }
};
