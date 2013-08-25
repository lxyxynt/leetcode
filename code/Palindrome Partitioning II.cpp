bool g[2222][2222];
int f[2222];
class Solution {
public:
    int minCut(string s) {
        memset(g,false,sizeof(g));
        for (int i=0;i<s.size();++i){
            g[i][1]=true;
            if (i && s[i-1]==s[i]) g[i-1][2]=true;
        }
        for (int i=1;i+2<=s.size();++i)
            for (int j=1;j+i<s.size();++j)
                if (g[j][i] && s[j-1]==s[j+i]) g[j-1][i+2]=true;
        memset(f,10,sizeof(f));
        f[0]=0;
        for (int i=1;i<=s.size();++i)
            for (int j=0;j<i;++j)
                if (g[j][i-j]) f[i]=min(f[i],f[j]+1);
        return f[s.size()]-1;
    }
};
