#include <queue>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        //build the graph
        for (auto edge : times) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            graph[from].push_back({to, weight});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [currentDistance, node] = pq.top();
            pq.pop();
            if (currentDistance > distance[node]) continue;
            for (auto [neighbor, weight] : graph[node]) {
                int newDistance = distance[node] + weight;
                if (newDistance < distance[neighbor]) {
                    distance[neighbor] = newDistance;
                    pq.push({newDistance, neighbor});
                }
            }
        }
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            answer = max(answer, distance[i]);
        }
        return answer;
    }
};