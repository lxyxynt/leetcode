class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str);
        if (len==0) return 0;
        int s = 0, flag = 1;
        while (str[s]==' ' && s<len) ++s;
        if (s==len) return 0;
        long long res = 0;
        if (str[s]=='-'){
            s++;
            flag=-1;
        }
        if (str[s]=='+') s++;
        for (;s<len;++s){
            if (str[s]<'0' || str[s]>'9') break;
            res = res * 10 + str[s] - 48;
        }
        res *= flag;
        if (res < -2147483648) return -2147483648;
        if (res > 2147483647) return 2147483647;
        return res;
    }
};