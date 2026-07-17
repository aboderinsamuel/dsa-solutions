#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //Deadends act like walls
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000")) return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int turns = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                
                if(curr == target)return turns;
                for(int i=0; i<4; i++){
                    char original = curr[i];
                    for(int move : {-1, 1}){
                        string next = curr;
                        next[i] = (original - '0' + move + 10) % 10 + '0';
                        if(dead.count(next)) continue;
                        if(visited.count(next)) continue;
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            turns++;
        }
        return -1;

    }
};