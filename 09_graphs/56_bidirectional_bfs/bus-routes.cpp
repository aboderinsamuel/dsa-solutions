#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //if already at target, no need to take any bus
        if(source == target)return 0;

        //stop -> [bus0, bus1] style
        unordered_map<int, vector<int>> stopToBuses;

        for(int bus = 0; bus < routes.size(); bus++){
            for(int stop : routes[bus]){
                stopToBuses[stop].push_back(bus);
            }
        }

        //BFS SETUP
        //queue holds bus stops we can reach
        queue<int> q;
        q.push(source);

        //visitedBuses -> avoid revisiting same stop
        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        //visitedbuses->avoid visiting same bus twice
        unordered_set<int> visitedBuses;

        //number of buses taken (BFS level)
        int busesTaken = 0;

        //BFS traversal..each lvel = take 1 more bus
        while(!q.empty()){
            int size = q.size(); // all stops reachable with current buses
            busesTaken++; //we are taking a new bus layer
            for(int i=0; i<size; i++){
                int stop = q.front();
                q.pop();

                //checl all buses that pass through this stop
                for(int bus : stopToBuses[stop]){
                    //skip if we already used this bus
                    if(visitedBuses.count(bus))continue;

                    //mark bus as used
                    visitedBuses.insert(bus);

                    //travel through this entire bus route
                    for(int nextStop : routes[bus]){
                        //if we reach target, return answer immediately
                        if(nextStop == target){
                            return busesTaken;
                        }
                        //if not visited, add to queue
                        if(!visitedStops.count(nextStop)){
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }

        }
        //if BFS ends, and target not reached
        return -1;
    }
};