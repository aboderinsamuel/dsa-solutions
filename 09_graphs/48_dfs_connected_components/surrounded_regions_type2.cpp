class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        int m = board.size();
        int n = board[0].size();

        //stop conditions
        if(r < 0 || r >= m || c < 0 || c >= n) return;
        if(board[r][c] != 'O') return;
        board[r][c] = 'S';
        dfs(board, r, c+1);
        dfs(board, r, c-1);
        dfs(board, r-1, c);
        dfs(board, r+1, c);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int r=0; r<m; r++){
            dfs(board, r, 0);
            dfs(board, r, n-1);
        }
        for(int c=0; c<n; c++){
            dfs(board, 0, c);
            dfs(board, m-1, c);
        }
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                board[r][c] = (board[r][c] == 'S') ? 'O' : 'X';
            }
        }
    }
};