#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for(int row=0; row <n; ++row){
            for(int col=0; col<n; ++col){
                if(grid[row][col] == 1) q.push({row, col});
            }
        }
        //all water or all land
        if(q.empty() || (int) q.size() == n*n) return-1;
        static const vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int distance = -1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [row, col] = q.front();
                q.pop();

                for(auto [dr, dc] : directions){
                    int newR = row + dr;
                    int newC = col + dc;
                    if(newR < 0 || newR >= n || newC < 0 || newC >= n) continue;
                    if(grid[newR][newC] != 0) continue; //water only
                    grid[newR][newC] = 1; //mark on enqueue
                    q.push({newR, newC});
                }
            }
            ++distance;
        }
        return distance;
    }
};