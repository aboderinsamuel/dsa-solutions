class Solution {
private:
    priority_queue<pair<int, vector<int>>> maxHeap;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto& point : points){
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;
            maxHeap.push({distance, point});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};