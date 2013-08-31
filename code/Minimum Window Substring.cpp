class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, int> M, Hash;
        int head = 0, sum = 0, ans = 0, len = S.size() + 1, now;
        for (int i=0;i<T.size();++i) Hash[T[i]]++;
        for (int i=0;i<S.size();++i){
            if (Hash.find(S[i])==Hash.end()) continue;
            now = (++M[S[i]]);
            if (now == Hash[S[i]]) sum += now;
            while (sum == T.size()){
                if (i-head+1<len){
                    len = i-head+1;
                    ans = head;
                }
                now = (--M[S[head]]);
                if (now+1 == Hash[S[head]]) sum -= now+1;
                ++head;
            }
        }
        if (len>S.size()) return "";
        return S.substr(ans, len);
    }
};
