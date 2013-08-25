class Solution {
public:
    vector<TreeNode *> generate(int l, int r){
        vector<TreeNode *> ret;
        ret.clear();
        if (r <= l){
            ret.push_back(NULL);
            return ret;
        }
        for (int rooVal = l; rooVal < r; ++rooVal){
            vector<TreeNode *> chl = generate(l, rooVal);
            vector<TreeNode *> chr = generate(rooVal+1, r);
            for (int i=0;i<chl.size();++i)
                for (int j=0;j<chr.size();++j){
                    TreeNode *root = new TreeNode(rooVal);
                    root->left  = chl[i];
                    root->right = chr[j];
                    ret.push_back(root);
                }
        }
        return ret;   
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n+1);
    }
};