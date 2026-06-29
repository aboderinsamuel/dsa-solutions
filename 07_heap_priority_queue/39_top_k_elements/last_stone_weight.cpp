class Solution {
private:
    priority_queue<int> maxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size()  > 1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if( x != y){
                maxHeap.push(y-x);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};