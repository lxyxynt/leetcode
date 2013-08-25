class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size()!=s2.size()) return false;
        if (s1 == s2) return true;
        map<char, int> M;
        for (int i=0;i<s1.size();++i) M[s1[i]]++;
        for (int i=0;i<s2.size();++i){
            if (M[s2[i]]==0) return false;
            M[s2[i]]--;
        }
        string s11,s12,s21,s22;
        for (int i=1;i<s1.size();++i){
            s11 = s1.substr(0, i);
            s12 = s1.substr(i);
            s21 = s2.substr(0, i);
            s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s22 = s2.substr(0, s2.size()-i);
            s21 = s2.substr(s2.size()-i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
    }
};