vector<vector<string>> ans;
unordered_set<string> D;
unordered_map<string, int> M;
unordered_map<string, vector<string>> pre;
string S,T;
int Max;
class Solution {
public:
    void dfs(string s, list<string> path){
        if (s==S){
            vector<string> ret(path.begin(),path.end());
            ans.push_back(ret);
            return;
        }
        vector<string> nxt = pre[s];
        for (int i=0;i<nxt.size();++i){
            path.push_front(nxt[i]);
            dfs(nxt[i],path);
            path.pop_front();
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        D = dict; S = start; T = end;
        queue<string> Q;
        while (!Q.empty()) Q.pop();
        M.clear();M[S]=0;Q.push(S);
        while (!Q.empty()){
            string s = Q.front();
            Q.pop();
            for (int i=0;i<s.size();++i){
                string t = s;
                for (char ch='a';ch<='z';++ch){
                    t[i]=ch;
                    if (dict.find(t)==dict.end()) continue;
                    if (M.find(t)==M.end()){
                        M[t]=M[s]+1;
                        Q.push(t);
                        vector<string> ret;
                        ret.clear();
                        ret.push_back(s);
                        pre[t]=ret;
                        continue;
                    }
                    if (M[t]==M[s]+1)
                        pre[t].push_back(s);
                }
            }
        }
        Max = M[T];
        list<string> ret;
        ret.clear();ans.clear();
        ret.push_back(T);
        dfs(T,ret);
        return ans;
    }
};
