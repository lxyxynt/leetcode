class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int p = m-1;
        for (int i=0;i<n;++i){
            while (p>=0 && matrix[i][p]>target) --p;
            if (matrix[i][p]==target) return true;
        }
        return false;
    }
};
