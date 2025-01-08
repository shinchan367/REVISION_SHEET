#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;  // stack stores the pair (price, span)

    StockSpanner() {}

    int next(int price) {
        int span = 1;
        
        // Calculate span for the given price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Add the span of the previous element
            st.pop();  // Pop the previous element from the stack
        }
        
        st.push({price, span});  // Push current price and its span
        return span;  // Return the span
    }
};
