class Solution {
public:
    int ladderLength(string S, string T, unordered_set<string> &dict) {
        queue<string> Q;
        unordered_map<string, int> M;
        while (!Q.empty()) Q.pop();
        M.clear();M[S]=0;Q.push(S);
        while (!Q.empty()){
            string s = Q.front();
            Q.pop();
            for (int i=0;i<s.size();++i){
                string t = s;
                for (char ch='a';ch<='z';++ch){
                    t[i]=ch;
                    if (t==T) return M[s]+2;
                    if (dict.find(t)==dict.end()) continue;
                    if (M.find(t)!=M.end()) continue;
                    M[t]=M[s]+1;
                    Q.push(t);
                }
            }
        }
        return 0;
    }
};
