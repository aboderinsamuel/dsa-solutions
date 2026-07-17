#include <queue>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> directions = {{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> distance(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
        //vector<int>(size, value)
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(mat[row][col] == 0){
                    q.push({row,col});
                    visited[row][col] = true;
                }
            }
        }
        while(!q.empty()){
            auto [row, col] = q.front(); // take the oldest cell from the queue
            q.pop();
            for(auto [dr, dc] : directions){ //look in all 4 directions
                int newRow = row + dr;  //calculate the neighbor
                int newCol = col + dc;
                if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
                if(visited[newRow][newCol])continue;
                visited[newRow][newCol] = true;
                distance[newRow][newCol] = distance[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
        return distance;
    }
};