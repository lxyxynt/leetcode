class Solution {
public:
    int f[111111];
    int numDecodings(string s) {
        if (s.size()==0) return 0;
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=s.size();++i)
            for (int j=1;j<=2;++j){
                if (i-j<0) continue;
                string now = s.substr(i-j, j);
                if (now[0] == '0') continue;
                if (atoi(now.c_str())>26) continue;
                f[i] = f[i] + f[i-j];
            }
        return f[s.size()];
    }       
};