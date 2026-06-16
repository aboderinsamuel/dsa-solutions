#include <vector>
class Solution {
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currentTank = 0;
        int startStation = 0;

        for (int i=0; i<gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            currentTank += (gas[i] - cost[i]);
            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }
        return (totalGas < totalCost)  ? -1 : startStation;
    }
};