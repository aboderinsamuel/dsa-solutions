#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        //step1: count freq
        for(int num : nums){
            freq[num]++;
        }

        //min heap : (freq, number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //step2: push to heap
        for(auto &it : freq){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        //step3: collect answer
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};