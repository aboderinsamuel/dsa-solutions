#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for(string op : operations){
            if(op == "+"){
                int first = scores.top();
                scores.pop();
                int second = scores.top();
                int newScore = first + second;

                scores.push(first);
                scores.push(newScore);
            }
            else if(op == "D"){
                scores.push(scores.top()*2);
            }
            else if(op == "C"){
                scores.pop();
            }else{
                scores.push(stoi(op));
            }
        }
        int sum = 0;
        while(!scores.empty()){
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};