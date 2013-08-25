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
    vector<deque<int> > ans;
    void zigzagLevelOrder_work(TreeNode *root, int deep){
        if (root == NULL) return;
        if (ans.size() <= deep){
            deque<int> temp;
            temp.clear();
            ans.push_back(temp);
        } 
        if (deep&1){
            ans[deep].push_front(root->val);
        }else{
            ans[deep].push_back(root->val);
        }
        zigzagLevelOrder_work(root->left , deep+1);
        zigzagLevelOrder_work(root->right, deep+1);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        ans.clear();
        zigzagLevelOrder_work(root, 0);
        vector<vector<int> > ret;
        ret.clear();
        for (int i=0;i<ans.size();++i){
            vector<int> temp(ans[i].begin(), ans[i].end());
            ret.push_back(temp);
        }
        return ret;
    }
};