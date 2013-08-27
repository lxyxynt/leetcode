class Solution {
public:
    int minDistance(string word1, string word2) {
        static int f[1111][1111];
        int n = word1.size(), m = word2.size();
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                f[i][j] = n+m;
        for (int i=0;i<=n;++i) f[i][0]=i;
        for (int i=0;i<=m;++i) f[0][i]=i;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j){
                f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
                if (word1[i-1]==word2[j-1]) f[i][j]=min(f[i][j], f[i-1][j-1]);
            }
        return f[n][m];
    }
};
