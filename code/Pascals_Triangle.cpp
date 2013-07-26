class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        vector<int> ans;
        ret.clear();ans.clear();
        if (!numRows) return ret;
        ans.push_back(1);
        ret.push_back(ans);
        for (int i=0;i+1<numRows;++i){
            ans.push_back(1);
            for (int j=i;j;--j) ans[j]+=ans[j-1];
            ret.push_back(ans);
        }
        return ret;
    }
};
