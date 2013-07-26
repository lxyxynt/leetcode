const int inf = 1999999999;
int pre[1111111],suf[1111111];
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()==0) return 0;
        int Min = prices[0]; pre[0] = 0;
        for (int i=1;i<prices.size();++i){
            pre[i] = max(pre[i-1], prices[i]-Min);
            Min = min(Min, prices[i]);
        }
        int Max = prices[prices.size()-1]; suf[prices.size()-1] = 0;
        for (int i=prices.size()-2;i>=0;--i){
            suf[i] = max(suf[i+1], Max-prices[i]);
            Max = max(Max, prices[i]);
        }
        int ans = 0;
        for (int i=0;i<prices.size();++i) ans=max(ans,pre[i]+suf[i]);
        return ans;
    }
};
