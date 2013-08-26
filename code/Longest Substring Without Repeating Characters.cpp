class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> M;
        int head=0, ans=0;
        for (int tail=0;tail<s.size();++tail){
            M[s[tail]]++;
            while (M[s[tail]]>1){
                M[s[head]]--;
                head++;
            }
            ans = max(ans, tail-head+1);
        }
        return ans;
    }
};