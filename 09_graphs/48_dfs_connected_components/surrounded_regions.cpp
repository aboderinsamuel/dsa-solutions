#include <vector>
using namespace std;
class Solution {
public:
    //4 directions
    //  OR static constexpr pair<int, int> directions[4] = {{1,0},{-1,0},{0,-1},{0,1}};
    vector<pair<int, int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board, int row, int col){
        //outside the board?
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if(board[row][col] != 'O') return;
        board[row][col] = 'S';
        for(auto [dr, dc] : directions){
            dfs(board, row+dr, col+dc);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        //left and right boarders
        for(int row=0; row<rows; row++){
            dfs(board, row, 0);
            dfs(board, row, cols-1);
        }
        //top and bottom boarders
        for(int col=0; col < cols; col++){
            dfs(board, 0, col);
            dfs(board, rows-1, col);
        }
        for(int row=0; row<rows; row++){
            for(int col=0; col < cols; col++){
                if(board[row][col] == 'O') board[row][col] = 'X';
                else if(board[row][col] == 'S') board[row][col] = 'O';
            }
        }
    }
};