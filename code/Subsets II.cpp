class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        set<vector<int> > hash;
        vector<vector<int> > ans;
        sort(S.begin(), S.end());
        int n = S.size();
        for (int sta=0;sta<(1<<n);++sta){
            vector<int> ret;
            for (int i=0;i<n;++i)
                if (sta&(1<<i)) ret.push_back(S[i]);
            if (hash.find(ret)==hash.end()){
                ans.push_back(ret);
                hash.insert(ret);
            }
        }
        return ans;
    }
};