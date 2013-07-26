const int inf = 1999999999;
int f[2][11111];
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size()==0) return 0;
        f[0][0] = triangle[0][0];
        int p = 0;
        for (int i=1;i<triangle.size();++i){
            for (int j=0;j<=i;++j){
                if (j==i){                  
                    f[1-p][j] = f[p][j-1] + triangle[i][j];
                    continue;
                }
                if (j==0){
                    f[1-p][j] = f[p][j] + triangle[i][j];
                    continue;
                }
                f[1-p][j] = min(f[p][j-1], f[p][j]) + triangle[i][j];
            }
            p = 1-p;
        }
        int ans = inf;
        for (int i=0;i<triangle.size();++i) ans = min(ans, f[p][i]);
        return ans;
    }
};
