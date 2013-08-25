/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;
class Solution {
public:
    void dfs(TreeNode *root, int ret){
        if (root == NULL) return;
        ret = ret * 10 + root->val;
        bool flag = false;
        if (root->left != NULL){
            dfs(root->left,  ret);
            flag = true;
        }
        if (root->right != NULL){
            dfs(root->right, ret);
            flag = true;
        }
        if (!flag) ans += ret;
    }
    int sumNumbers(TreeNode *root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
