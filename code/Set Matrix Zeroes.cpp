class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int flag = 0, now = 0;;
        for (int i=0;i<m;++i)
            if (matrix[0][i]==0) flag = 1;
        for (int i=1;i<n;++i){
            now = 0;
            for (int j=0;j<m;++j){
                if (matrix[i][j]==0) now = 1;
                if (matrix[i-1][j]==0) matrix[i][j]=0;
                if (flag) matrix[i-1][j]=0;
            }
            flag = now;
        }
        for (int i=0;i<m;++i)
            if (matrix[n-1][i]==0)
                for (int j=0;j<n;++j) matrix[j][i]=0;
        if (flag)
            for (int i=0;i<m;++i) matrix[n-1][i]=0;
    }
};
