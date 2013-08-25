/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > ans;
    void zigzagLevelOrder_work(TreeNode *root, int deep){
        if (root == NULL) return;
        if (ans.size() <= deep){
            vector<int> temp;
            temp.clear();
            ans.push_back(temp);
        } 
        ans[deep].push_back(root->val);
        zigzagLevelOrder_work(root->left , deep+1);
        zigzagLevelOrder_work(root->right, deep+1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        ans.clear();
        zigzagLevelOrder_work(root, 0);
        return ans;
    }
};
    