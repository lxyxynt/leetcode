const int inf = 1999999999;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int Min = inf, ans = 0;
        for (int i=0;i<prices.size();++i){
            ans = max(ans, prices[i]-Min);
            Min = min(Min, prices[i]);
        }
        return ans;
    }
};
