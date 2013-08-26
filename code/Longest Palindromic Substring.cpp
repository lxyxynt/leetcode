class Solution {
public:
    string longestPalindrome(string s) {
        if (s=="") return s;
        static bool f[1111][1111];      
        memset(f,false,sizeof(f));
        int l1=0, l2=1; 
        for (int i=0;i<s.size();++i) f[i][i] = true;
        for (int i=1;i<s.size();++i) 
            if (s[i-1]==s[i]){
                l1=i-1;l2=2;
                f[i-1][i]=true;
            }
        for (int i=3;i<=s.size();++i)
            for (int j=0;j+i-1<s.size();++j){
                int k = j+i-1;
                if (f[j+1][k-1] && s[j]==s[k]){
                    f[j][k]=true;
                    l1=j;l2=i;
                }
            }
        return s.substr(l1,l2);
    }
};