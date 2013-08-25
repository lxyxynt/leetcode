class Solution {
public:
    bool isPalindrome(string t) {
        string s = "";
        for (int i=0;i<t.size();++i){
            if (isalpha(t[i])) s+=tolower(t[i]);
            if (isdigit(t[i])) s+=t[i];
        }
        bool flag = true;
        for (int i=0;flag && i<s.size()/2;++i)
            if (s[i]!=s[s.size()-i-1]) flag = false;
        return flag;
    }
};
