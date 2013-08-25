class Solution {
public:
    int numTrees(int n) {
        long long Num = 1;
        for (int i = n+2; i <= n*2; ++i) Num *= i;
        for (int i = 1; i <= n; ++i) Num /= i;
        return Num;
    }
};