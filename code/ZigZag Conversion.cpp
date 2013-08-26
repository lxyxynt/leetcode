class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows==1) return s;
        static string ans[111111];
        for (int i=1;i<=nRows;++i) ans[i]="";
        int kind = 1, delta;
        for (int i=0;i<s.size();++i){
            if (kind == 1) delta = 1;
            if (kind == nRows) delta = -1;
            ans[kind]+=s[i];
            kind += delta;
        }
        string ret = "";
        for (int i=1;i<=nRows;++i) ret += ans[i];
        return ret;
    }
};