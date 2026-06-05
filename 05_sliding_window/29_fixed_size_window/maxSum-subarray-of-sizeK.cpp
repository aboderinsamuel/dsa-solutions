//
// Created by samuel on 6/5/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumSubarrayofSizeK(int k, const vector<int>& arr)
{
    int maxSum = 0;
    int windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        // Add the next element to the window
        windowSum += arr[windowEnd];
        // If we've hit the window size, we need to slide it
        if (windowEnd >= k - 1)
        {
            //Record the max
            maxSum = max(maxSum, windowSum);
            //subtract the element going out
            windowSum -= arr[windowStart];
            // slide the window forward
            windowStart++;
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    cout << "Max Sum: " << maxSumSubarrayofSizeK(3, arr) << endl;
    return 0;
};

