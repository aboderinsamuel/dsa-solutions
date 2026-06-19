#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    //Mapping of digits to Letters
    vector<string> digitToLetters = {
        "", //0
        "", //1
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz" //9
    };
    void backtrack(string& digits, int idx, string& current, vector<string>& result){
        //Best case: processed all digits
        if(idx == digits.size()){
            result.push_back(current);
            return;
        }
        // Get the letters for current digit
        int digit = digits[idx] - '0';
        string letters = digitToLetters[digit];

        // Try each letter for this digit
        for(char letter : letters){
            current.push_back(letter);
            backtrack(digits, idx+1, current, result);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        //Edge case: empty input
        if(digits.empty()){
            return result;
        }
        string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};