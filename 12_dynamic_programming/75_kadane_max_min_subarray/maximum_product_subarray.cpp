class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Best product of a subarray ending HERE
        int curMax = nums[0];

        // Worst product of a subarray ending HERE
        //
        // We need this because:
        // negative × negative = positive
        //
        // So today's smallest negative product
        // could become tomorrow's biggest product.
        int curMin = nums[0];

        // Best product we've seen anywhere so far
        int result = nums[0];


        for (int i = 1; i < nums.size(); i++) {

            int n = nums[i];


            // There are 3 possibilities for a subarray
            // ending at n:
            //
            // 1. Start fresh:
            //        n
            //
            // 2. Extend the previous maximum:
            //        curMax * n
            //
            // 3. Extend the previous minimum:
            //        curMin * n
            //
            // We need all 3 because n could be positive
            // or negative.

            int tempMax = max({
                n,
                curMax * n,
                curMin * n
            });


            // IMPORTANT:
            //
            // curMin still needs the OLD curMax.
            //
            // That's why we calculate tempMax first.
            //
            // At this point:
            //
            // curMax = OLD curMax
            // curMin = OLD curMin
            //
            // So this is safe.
            curMin = min({
                n,
                curMax * n,
                curMin * n
            });


            // Now we can replace curMax with the
            // newly calculated maximum.
            curMax = tempMax;


            // curMax is the best product ending at
            // this position.
            //
            // Compare it with the best answer we've
            // seen anywhere in the array.
            result = max(result, curMax);
        }


        return result;
    }
};