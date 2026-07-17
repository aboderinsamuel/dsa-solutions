//DFS CYCLE DETECTION
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& path, int course){
        if(path[course])return true;
        if(visited[course]) return false;
        visited[course] = true;

        //add to current recursion path
        path[course] = true;

        for(int next : graph[course]){
            if(dfs(graph, visited, path, next)) return true;
        }
        path[course] = false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto edge : prerequisites){
            int course = edge[0];
            int prereq = edge[1];
            graph[prereq].push_back(course);
        }
        vector<bool>visited(numCourses, false);
        vector<bool> path(numCourses,false);
        for(int i=0; i<numCourses; i++){
            if(dfs(graph, visited, path, i)) return false;
        }
        return true;
    }
};