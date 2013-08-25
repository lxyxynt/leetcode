/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    unordered_map<int, int> index;
    TreeNode *build(vector<int> &preorder, int l, int r, int offset){
        if (l == r) return NULL;
        int rootVal = preorder[l];
        int sum = index[rootVal] - offset;
        TreeNode *root = new TreeNode(rootVal);
        root->left  = build(preorder, l + 1, l + sum + 1, offset);
        root->right = build(preorder, l + sum + 1, r, offset + sum + 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        index.clear();
        for (int i=0;i<inorder.size();++i) 
            index[inorder[i]] = i;
        return build(preorder, 0, inorder.size(), 0);
    }
};