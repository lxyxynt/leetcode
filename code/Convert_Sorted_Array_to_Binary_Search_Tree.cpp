class Solution {
public:
    TreeNode *build(vector<int> &num, int l, int r){
        if (l >= r) return NULL;
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        root->left  = build(num, l, mid);
        root->right = build(num, mid+1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size());
    }
};
