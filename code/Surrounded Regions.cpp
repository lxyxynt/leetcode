vector<vector<char> > board;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool flag[3333][3333];
int n,m;

class Solution {
public:
    void fill(int x,int y) {
        queue<pair<int,int> > Q;
        while (!Q.empty()) Q.pop();
        flag[x][y]=false;
        Q.push(make_pair(x,y));
        while (!Q.empty()){
            pair<int,int> t = Q.front();
            Q.pop();
            for (int k=0;k<4;++k){
                int tx = t.first + dx[k], ty = t.second + dy[k];
                if (tx<0 || tx>=n || ty<0 || ty>=m || !flag[tx][ty] || board[tx][ty]=='X') continue;
                flag[tx][ty]=false;
                Q.push(make_pair(tx,ty));
            }
        }
    }
    void solve(vector<vector<char> > &input) {
        if (input.size()==0) return;
        board = input;
        n = board.size();
        m = board[0].size();
        memset(flag,true,sizeof(flag));
        for (int i=0;i<n;++i){
            if (flag[i][0]   && board[i][0]  =='O') fill(i,0);
            if (flag[i][m-1] && board[i][m-1]=='O') fill(i,m-1);
        }
        for (int i=0;i<m;++i){
            if (flag[0][i]   && board[0][i]  =='O') fill(0,i);
            if (flag[n-1][i] && board[n-1][i]=='O') fill(n-1,i);
        }
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (flag[i][j]) input[i][j]='X';
    }
};