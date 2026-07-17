class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int result = 0;
        for(int price : prices){
            minPrice = min(minPrice, price);
            result = max(price-minPrice, result);
        }
        return result;
    }
};