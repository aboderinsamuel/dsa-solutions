#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isPalindrome(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    //DFS backtracking helper function
    void dfs(int startIdx, const string& s, vector<string>& path, vector<vector<string>>& result){
        //Best case: If we have reached the end of the string, we have found a valid partition
        if(startIdx >= s.length()){
            result.push_back(path);
            return;
        }
        //iterate through the string to find all possible substrings starting at startIdx
        for(int endIdx = startIdx; endIdx < s.length(); ++endIdx){
            //check if the current substring s[startIdx : endIdx] is a palindrome
            if(isPalindrome(s, startIdx, endIdx)){
                //1. choose: If it is a palindrome, append it to current path
                path.push_back(s.substr(startIdx, endIdx-startIdx+1));
                //2. Explore: Recurse deeper for the remaining substring (start right after endIdx)
                dfs(endIdx+1, s, path, result);
                //backtrack
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(0, s, path, result);
        return result;
    }
};