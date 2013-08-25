class Solution {
public:
    double findMedian(int A[], int m, int B[], int n, int k){
        if (m > n) return findMedian(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (n == 0) return A[k-1];
        if (k == 1) return min(A[0], B[0]);
        int l1 = min(k/2, m);
        int l2 = k - l1;
        if (A[l1-1] < B[l2-1]) return findMedian(A + l1, m - l1, B, n, k - l1);
        return findMedian(A, m, B + l2, n - l2, k - l2);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)&1) return findMedian(A, m, B, n, (m+n) / 2 + 1);
        return (findMedian(A, m, B, n, (m+n)/2) + findMedian(A, m, B, n, (m+n)/2+1)) / 2;
    }
};
