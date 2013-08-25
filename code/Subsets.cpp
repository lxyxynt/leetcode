class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        sort(S.begin(), S.end());
        int n = S.size();
        for (int sta=0;sta<(1<<n);++sta){
            vector<int> ret;
            for (int i=0;i<n;++i)
                if (sta&(1<<i)) ret.push_back(S[i]);
            ans.push_back(ret);
        }
        return ans;
    }
};