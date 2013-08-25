const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
bool flag[1111][1111];
class Solution {
public:
    bool dfs(int deep, int x, int y, vector<vector<char> > &board, string word){
        if (deep==word.size()) return true;
        flag[x][y]=false;
        int n = board.size(), m = board[0].size();
        for (int k=0;k<4;++k){
            int tx = x+dx[k];
            int ty = y+dy[k];
            if (tx<0 || tx>=n || ty<0 || ty>=m) continue;
            if (!flag[tx][ty] || board[tx][ty]!=word[deep]) continue;
            if (dfs(deep+1, tx, ty, board, word)) return true;
        }
        flag[x][y]=true;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size()==0 || board[0].size()==0) return false;
        int n = board.size(), m = board[0].size();
        memset(flag,true,sizeof(flag));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (board[i][j]==word[0])
                    if (dfs(1, i, j, board, word)) return true;
        return false;
    }
};