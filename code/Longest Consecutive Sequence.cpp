class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> M;
        M.clear();
        for (int i=0;i<num.size();++i) M[num[i]]=1;
        int ans = 0;
        for (int i=0;i<num.size();++i){
            if (M[num[i]]==0) continue;
            int ret = 1;
            for (int k=1;M.find(num[i]-k)!=M.end();++k){
                M[num[i]-k] = 0;
                ++ret;
            }
            for (int k=1;M.find(num[i]+k)!=M.end();++k){
                M[num[i]+k] = 0;
                ++ret;
            } 
            ans = max(ans, ret);
        }
        return ans;
    }
};
