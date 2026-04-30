//
// Created by USER on 4/30/2026.
//
#include <iostream>
#include<vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m+n, 0);

        //multiply every digit pai, right to left
        for(int i = m-1; i>=0; --i){
            for(int j = n-1; j>=0; --j){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos = i + j + 1; // current digit position
                int sum = mul + result[pos];

                result[pos] = sum % 10; //keep the digit
                result[i + j] += sum / 10; //carry up

            }
        }
        //convert to string, skip leading zeros
        string str;
        for(int digit : result){
            if(!(str.empty() && digit == 0)){
                str += (digit + '0');
            }
        }
        return str.empty() ? "0" : str;
    }
};