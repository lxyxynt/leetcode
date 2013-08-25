class Solution {
public:
    int BinarySearch(int A[], int n, int target){
        if (n<1) return -1;
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
        return ret;
    }
    int search(int A[], int m, int target) {
        if (m<1) return -1;
        int l=0,r=m-1,split=-1;
        while (l<=r){
            int mid = (l+r)>>1;
            if (A[mid]<A[0]){
                split=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if (split==-1) return BinarySearch(A, m, target);
        int ret;
        ret = BinarySearch(A, split, target);
        if (ret!=-1) return ret;
        ret = BinarySearch(A+split, m-split, target);
        if (ret!=-1) return ret+split;
        return -1;
    }
};