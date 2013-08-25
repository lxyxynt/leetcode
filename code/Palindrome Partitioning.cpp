bool g[2222][2222];
vector<vector<string>> ans;
string str;
class Solution {
public:
    void dfs(int k,vector<string> ret){
        if (k==str.size()){
            ans.push_back(ret);
            return;
        }
        for (int i=1;k+i-1<str.size();++i)
            if (g[k][i]){
                ret.push_back(str.substr(k,i));
                dfs(k+i,ret);
                ret.resize(ret.size()-1);
            }
    }
    vector<vector<string>> partition(string s) {
        str = s;
        memset(g,false,sizeof(g));
        for (int i=0;i<s.size();++i){
            g[i][1]=true;
            if (i && s[i-1]==s[i]) g[i-1][2]=true;
        }
        for (int i=1;i+2<=s.size();++i)
            for (int j=1;j+i<s.size();++j)
                if (g[j][i] && s[j-1]==s[j+i]) g[j-1][i+2]=true;
        vector<string> ret;
        ret.clear();ans.clear();
        dfs(0,ret);
        return ans;
    }
};
