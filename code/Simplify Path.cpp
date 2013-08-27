class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        vector<string>::iterator it;
        string tmp = "";
        for (int i=0;i<path.size();++i){
            if (path[i]=='/'){
                if (tmp!="" && tmp!="."){
                    if (tmp==".."){
                        if (ans.size()!=0){
                            it = ans.end();
                            --it;
                            ans.erase(it);
                        }
                    } else ans.push_back(tmp);
                }
                tmp = "";
            }else tmp += path[i];
        }
        if (tmp!="" && tmp!="."){
            if (tmp==".."){
                if (ans.size()!=0){
                    it = ans.end();
                    --it;
                    ans.erase(it);
                }
            }else ans.push_back(tmp);
        }
        if (ans.size()==0) return "/";
        string ret = "";
        for (int i=0;i<ans.size();++i) ret += "/" + ans[i];
        return ret;
    }
};
