class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()==0) return 0;
        int ans = 0;
        int pre = prices[0];
        for (int i=1;i<prices.size();++i){
            while (i<prices.size() && prices[i]>=prices[i-1]) ++i;
            ans += prices[i-1]-pre;
            if (i<prices.size()) pre = prices[i];
        }
        return ans;
    }
};
