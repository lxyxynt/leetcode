class Solution {
public:
    void sortColors(int A[], int n) {
        int p1 = 0, p2 = n-1, cur = 0;
        while (cur <= p2){
            if (A[cur]==0) swap(A[cur++], A[p1++]);
            else
            if (A[cur]==2) swap(A[cur], A[p2--]);
            else ++cur;
        }
    }
};
