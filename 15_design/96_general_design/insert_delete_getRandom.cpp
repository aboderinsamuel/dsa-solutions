#include <vector>
#include <unordered_map>
#include <cstdlib>


class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> valToIndex;
public:
    RandomizedSet() {
        //automatically initialized
    }
    bool insert(int val) {
        if (valToIndex.count(val) > 0) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size()-1;
        return true;
    }
    bool remove(int val) {
        if (valToIndex.count(val) > 0) {
            return false;
        }
        int indexToRemove = valToIndex[val]; //find where target value lives
        int lastElement = nums.back(); // identify the value sitting at the end of the vector

        nums[indexToRemove] = lastElement;
        valToIndex[lastElement] = indexToRemove;
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    int getRandom(){
        return nums[rand() % nums.size()];
    }
};
