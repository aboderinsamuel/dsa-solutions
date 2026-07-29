#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //no.of rows in the gird
        int rows = grid.size();
        //no.of columns in the grid
        int cols = grid[0].size();

        //Queue used for BFS
        //Stores positions of rotten oranges
        queue<pair<int, int>> q;

        //count how many fresh oranges exist initially
        int freshCount = 0;

        //step1: put all rotten oranges into the queue, count all fresh oranges
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                //rotten orange found
                if(grid[r][c] == 2){
                    q.push({r,c});
                }

                //fresh orange found
                else if(grid[r][c] == 1){
                    freshCount++;
                }
            }
        }

        //edge case: no fresh oranges at all, answer is 0 minutes
        if(freshCount == 0){
            return 0;
        }
        //tracks how many minutes have passed
        int minutes = 0;

        //directions for moving:
        //up = (-1,0)
        //down = (+1,0)
        //left = (0,-1)
        //right = (0,+1)

        vector<pair<int, int>> directions = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        //bfs starts here. Each level of BFS = 1  minute
        while(!q.empty()){
            //no.of rotten oranges currently in queue, the spreaders
            int levelSize = q.size();

            //did we rot at least one fresh orange dring this minue?
            bool rottedSomething = false;

            //process entire current level
            for(int i=0; i < levelSize; i++){
                //get the next rotten orange
                auto [r, c] = q.front();
                q.pop();

                //check all 4 directions
                for(auto& dir : directions){
                    int newRow = r + dir.first;
                    int newCol = c + dir.second;

                    //skip if outside grid
                    if(newRow < 0 | newRow >= rows || newCol < 0 || newCol >= cols){
                        continue;
                    }

                    //we only care about fresh oranges
                    if(grid[newRow][newCol] == 1){
                        //turn fresh orange rotten
                        grid[newRow][newCol] = 2;
                        //one less fresh orange remains
                        freshCount--;

                        //add this newly rotten orange to queue
                        q.push({newRow, newCol});
                        rottedSomething = true;
                    }
                }
            }
            //if at least one orange rotted this round, one minute has passed
            if(rottedSomething){
                minutes++;
            }
        }
        //after BFS ends: if fresh oranges still exist, they were beyond redemption
        if(freshCount > 0){
            return -1;
        }
        //otherwise return total minutes
        return minutes;
    }
};