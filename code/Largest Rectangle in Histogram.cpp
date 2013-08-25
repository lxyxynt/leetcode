class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int m = height.size();
        if (m==0) return 0;
        int ans = 0;
        stack<int> heightStack, idNumber;
        for (int j=1;j<=m;++j){
            int tot = j;
            while (!heightStack.empty() && heightStack.top()>height[j-1]){
                int now = heightStack.top();
                int sum = j-idNumber.top();
                tot = idNumber.top();
                heightStack.pop();
                idNumber.pop();
                ans=max(ans, sum*now);
            }
            heightStack.push(height[j-1]);    
            idNumber.push(tot);
        }
        while (!heightStack.empty()){
            int now = heightStack.top();
            int sum = m+1-idNumber.top();
            heightStack.pop();
            idNumber.pop();
            ans=max(ans, sum*now);
        }
        return ans;
    }
};