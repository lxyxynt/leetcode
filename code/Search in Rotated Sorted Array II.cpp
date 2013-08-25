class Solution {
public:
    bool BinarySearch(int A[], int n, int target){
        if (n<1) return false;
        if (n==1) return A[0]==target;
        int l=0, r=n-1, ret=-1;
        while (l<=r){
            int mid = (l+r)>>1;
            if (A[mid]==target){
                ret=mid;
                break;
            }
            if (A[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return (ret!=-1);
    }
    bool search(int A[], int n, int target) {
        if (n<1) return false;
        if (n==1) return A[0]==target;
        int m=1;
        for (int i=1;i<n;++i)
            if (A[i]!=A[i-1]) A[m++]=A[i];
        int l=0,r=m-1,split=-1;
        while (l<=r){
            int mid = (l+r)>>1;
            if (A[mid]<A[0]){
                split=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if (split==-1) return BinarySearch(A, m, target);
        return BinarySearch(A, split, target) || BinarySearch(A+split, m-split, target);
    }
};