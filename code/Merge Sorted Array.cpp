class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pA = m, pB = n;
        for (int i=n+m-1;i>=0;--i){
            if (pA==0){ 
                A[i]=B[--pB];
                continue;
            }
            if (pB==0){ 
                A[i]=A[--pA];
                continue;
            }
            if (A[pA-1]<B[pB-1]) A[i]=B[--pB];
            else A[i]=A[--pA];
        }
    }
};