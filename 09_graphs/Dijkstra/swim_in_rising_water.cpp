#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        //track minimum time to reach each cell
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));

        //minHeap : {max_elevation_so_far, row, col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        //start from top left
        minTime[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()){
            auto [time, pos] = pq.top();
            pq.pop();

            int row = pos.first;
            int col = pos.second;

            //if we reached the bottom right, return the time
            if(row == n-1 && col == n-1) return time;
            //skip if we already found a better path
            if(time > minTime[row][col]) continue;

            //explore all 4 directions
            for(auto [dr,dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                //check bounds
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                //the new time is max(current time, elevation of new cell)
                //because we need to wai for water level to reach the highest elevation path
                int newTime = max(time, grid[nr][nc]);
                if(newTime < minTime[nr][nc]){
                    minTime[nr][nc] = newTime;
                    pq.push({newTime, {nr, nc}});
                }

            }
        }
        return -1; //should never reach here

    }
};