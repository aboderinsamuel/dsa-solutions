//
// Created by USER on 5/8/2026.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {1, -1}, {1,1}, {1, 0},{0,1},{0,-1}};
        for (int i=0; i <m; i++) {
            for (int j=0; j<n; j++) {
                int liveNeighbours = 0;
                for (auto& d : dirs) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (abs(board[ni][nj]) == 1) {
                            liveNeighbours++;
                        }
                    }
                }
                //apply rules
                if (board[i][j] == 1 && (liveNeighbours < 2 || liveNeighbours > 3)) {
                    board[i][j] = -1;
                }if (board[i][j] == 0 && liveNeighbours == 3) {
                    board[i][j] = 2;
                }
            }
        }
        //finally
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] > 0)board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    };
    //time complexity = O(m*n)
    //space complexity = O(n)
};