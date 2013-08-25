int f[2][1500];
class Solution {
public:
    int numDistinct(string S, string T) {
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        int p = 0;
        for (int i=1;i<=S.size();++i){
            f[1-p][0] = 1;
            for (int j=1;j<=T.size();++j){
                f[1-p][j] = f[p][j];
                if (S[i-1]==T[j-1]) f[1-p][j] += f[p][j-1];
            }
            p = 1-p;
        }
        return f[p][T.size()];
    }
};
