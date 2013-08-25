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
    TreeNode *build(vector<int> &postorder, int l, int r, int offset){
        if (l == r) return NULL;
        int rootVal = postorder[r-1];
        int sum = index[rootVal] - offset;
        TreeNode *root = new TreeNode(rootVal);
        root->left  = build(postorder, l, l + sum, offset);
        root->right = build(postorder, l + sum, r - 1, offset + sum + 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        index.clear();
        for (int i=0;i<inorder.size();++i) 
            index[inorder[i]] = i;
        return build(postorder, 0, inorder.size(), 0);
    }
};