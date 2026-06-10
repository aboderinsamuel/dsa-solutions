//
// Created by USER on 6/10/2026.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long hours;
        for (int bananas : piles) {
            hours += (bananas + k -1) / k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (hoursNeeded(piles, mid) <= h) {
                answer = mid; //valid, try smaller
                right = mid - 1;
            }else {
                left = mid  + 1;
            }
        }
        return answer;
    }
};