class Solution {
public:
    int reverse(int x) {
        char xstring[22];
        int flag = 1;
        if (x<0){
            sprintf(xstring, "%d", -x);
            flag=-1;
        }else sprintf(xstring, "%d", x);
        string s(xstring);
        int ret = 0;
        for (int i=s.size()-1; i>=0; --i)
            ret = ret * 10 + s[i] - 48;
        return flag * ret;
    }
};