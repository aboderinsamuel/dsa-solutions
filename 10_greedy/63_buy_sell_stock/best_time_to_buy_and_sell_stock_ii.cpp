class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //stores the profit earned
        int profit = 0;

        //start from day 1 because we compare today's price with yesterday's price
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
            //if today's price is lower, do nothing, we simplydon't take the loss

        }
        return profit;
    }
};