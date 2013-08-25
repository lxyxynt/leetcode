class Solution {
public:
    void dfs(string s, vector<string> &ans, int total, int lastPosition){
        if (total == 3){
            string now = s.substr(lastPosition+1, s.size()-lastPosition);
            if (now[0]=='0' && now.size()!=1) return;
            if (atoi(now.c_str())>255) return;
            ans.push_back(s);
            return;
        }
        for (int i=lastPosition+1;i+3-total<s.size();++i){
            string now = s.substr(lastPosition+1, i-lastPosition);
            if (now[0]=='0' && now.size()!=1) continue;
            if (atoi(now.c_str())>255) return;
            dfs(s.substr(0,i+1)+"."+s.substr(i+1), ans, total+1, i+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size()>12 || s.size()<4) return ans;
        dfs(s, ans, 0, -1);
        return ans;
    }
};