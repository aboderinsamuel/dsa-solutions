class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int prefix = 0;
        int answer = 0;

        for(int num : nums){
            prefix += num;
            if(prefixCount.count(prefix-k))answer += prefixCount[prefix-k];

            //record current prefix sum
            prefixCount[prefix]++;
        }
        return answer;
    }
};