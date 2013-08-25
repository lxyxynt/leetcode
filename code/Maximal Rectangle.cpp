class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) return 0;
        static int height[1111][1111];
        memset(height, 0, sizeof(height));
        int n=matrix.size(), m=matrix[0].size();
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                if (matrix[i-1][j-1]=='1') height[i][j]=height[i-1][j]+1;
                else height[i][j]=0;
        int ans = 0;
        stack<int> heightStack, idNumber;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                int tot = j;
                while (!heightStack.empty() && heightStack.top()>height[i][j]){
                    int now = heightStack.top();
                    int sum = j-idNumber.top();
                    tot = idNumber.top();
                    heightStack.pop();
                    idNumber.pop();
                    ans=max(ans, sum*now);
                }
                heightStack.push(height[i][j]);    
                idNumber.push(tot);
            }
            while (!heightStack.empty()){
                int now = heightStack.top();
                int sum = m+1-idNumber.top();
                heightStack.pop();
                idNumber.pop();
                ans=max(ans, sum*now);
            }
        }
        return ans;
    }
};