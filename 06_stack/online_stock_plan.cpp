#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
private:
    //stack : pairs of (price, span)
    stack<pair<int, int>> st;
public:
    StockSpanner() {}
    int next(int price) {
        int span = 1;
        //pop elements from the stack while the current price is greater than or equal to the top price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};