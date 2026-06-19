#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> board;
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void backtrack(int row, int n){
        //Base case: placed all n queens successfully
        if(row == n){
            result.push_back(board);
            return;
        }
        //Try placing queen in ach column of current row
        for(int col=0; col < n; col++){
            //check if this position is safe
            if(cols.count(col) || diag1.count(row - col) || diag2.count(row + col)){
                continue; //Position attacked
            }
            //Place queen at (row, col)
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            //Move to next row
            backtrack(row + 1, n);

            //backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        //Initialize board with all empty cells
        board = vector<string>(n, string(n, '.'));

        //start backtracking from now 0
        backtrack(0, n);

        return result;
    }
};