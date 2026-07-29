class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ++indegree[e[0]];
            ++indegree[e[1]];
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int remaining = n;
        while(remaining > 2){
            int size = q.size();
            remaining -= size;

            while(size--){
                int leaf = q.front();
                q.pop();

                for(int next : adj[leaf]){
                    if(--indegree[next] == 1){
                        q.push(next);
                    }
                }
            }
        }
        vector<int> centers;
        while(!q.empty()){
            centers.push_back(q.front());
            q.pop();
        }
        return centers;
    }
};