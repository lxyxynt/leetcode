class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        vector<int> spaces;
        vector<string> word;
        int i = 0;
        while (i<words.size()){
            spaces.clear();
            word.clear();
            word.push_back(words[i]);
            int len = words[i].size();
            ++i;
            while (i<words.size() && words[i].size() + 1 + len <= L){
                word.push_back(words[i]);
                spaces.push_back(1);
                len += words[i].size() + 1;
                ++i;
            }
            string ret = word[0];
            if (word.size()==1){
                while (ret.size()<L) ret += " ";
                ans.push_back(ret);
                continue;
            }
            if (i == words.size()){
                for (int j=1;j<word.size();++j) ret += " " + word[j];
                while (ret.size()<L) ret += " ";
                ans.push_back(ret);
                continue;
            }
            for (int j=0;j+len<L;++j) spaces[j%spaces.size()] ++;
            for (int j=1;j<word.size();++j){
                while (spaces[j-1]--) ret += " ";
                ret += word[j];
            }
            ans.push_back(ret);
        }
        return ans;
    }
};
