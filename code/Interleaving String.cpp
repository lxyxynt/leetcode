class Solution {
public:
    bool f[1111][1111];
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        memset(f,false,sizeof(f));
        f[0][0]=true;
        for (int i=0;i<=s1.size();++i)
            for (int j=0;j<=s2.size();++j){
                if (!f[i][j]) continue;
                if (i<s1.size() && s1[i] == s3[i+j]) f[i+1][j] = true;
                if (j<s2.size() && s2[j] == s3[i+j]) f[i][j+1] = true;
            }
        return f[s1.size()][s2.size()];
    }
};