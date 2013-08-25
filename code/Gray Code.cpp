class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n<0) return ans;
        ans.push_back(0);
        for (int j=0;j<n;++j)
            for (int i=(1<<j)-1;i>=0;--i) 
                ans.push_back(ans[i]+(1<<j));
        return ans;
    }
};