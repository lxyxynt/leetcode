class Solution {
public:
    void dfs(vector<int> &ret, vector<vector<int> > &ans, int n, int k, int deep, int last){
        if (deep==k){
            ans.push_back(ret);
            return;
        }
        for (int i=last+1;i+k-deep-1<=n;++i){
            ret.push_back(i);
            dfs(ret, ans, n, k, deep+1, i);
            vector<int>::iterator it = ret.end();
            ret.erase(--it);
        }
            
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> ret;
        dfs(ret, ans, n, k, 0, 0);
        return ans;
    }
};