class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<1) return NULL;
        int m=1, sum=1;
        for (int i=1;i<n;++i){
            if (A[i]!=A[i-1]){ 
                A[m++]=A[i];
                sum = 1;
            }else
            if (A[i]==A[i-1] && sum<2){
                A[m++]=A[i];
                sum++;
            }
        }
        return m;
    }
};
