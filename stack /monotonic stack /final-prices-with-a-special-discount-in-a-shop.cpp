/************************************************************ C++ ************************************************************/

// **Problem Description:**
// Given an array `prices` where `prices[i]` is the price of an item at index `i`, return an array `result` such that
// `result[i]` is the price of the item at index `i` minus the price of the first cheaper or equal item to its right. If no such item exists, the price remains the same.
//
// Constraints:
// - `1 <= prices.length <= 10^5`
// - `1 <= prices[i] <= 10^9`

// **Approach-1 (Brute Force)**

// **Algorithm:**
// 1. Initialize a `result` array with the same values as `prices`.
// 2. For each price at index `i`, iterate through the remaining items to the right to find the first item with a price less than or equal to `prices[i]`.
// 3. If found, subtract the price of the item from `prices[i]` and update `result[i]`.
// 4. Return the updated `result` array.

// **Why use this approach?**
// - This approach is simple to implement and uses nested loops to brute-force the solution. It works well for smaller input sizes.

// **Complexity:**
// - Time Complexity (T.C): O(n^2)
// - Space Complexity (S.C): O(1)

// **Points to Remember / Syntax:**
// - Use nested loops to compare each element with all elements to its right.
// - Break the inner loop when a match is found to save unnecessary comparisons.

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {

                    result[i] -= prices[j];
                    break;
                }
            }
        }

        return result;
    }
};

// **Approach-2 (Monotonic Stack)**

// **Algorithm:**
// 1. Initialize a `result` array with the same values as `prices`.
// 2. Use a stack to keep track of indices of elements for which the final price has not been determined.
// 3. Iterate through the array:
//    - While the stack is not empty and the current price is less than or equal to the price at the index stored at the top of the stack:
//      - Update the `result` for the index stored at the top of the stack by subtracting the current price.
//      - Pop the top element from the stack.
//    - Push the current index onto the stack.
// 4. Return the `result` array.

// **Why use this approach?**
// - A monotonic stack optimizes the brute-force approach by reducing unnecessary comparisons.
// - This approach is ideal for problems that require processing elements while maintaining a specific order.

// **Complexity:**
// - Time Complexity (T.C): O(n)
// - Space Complexity (S.C): O(n) due to the stack.

// **Points to Remember / Syntax:**
// - Use `stack<int>` to store indices of prices.
// - Use a while loop to efficiently determine the next cheaper or equal price for elements in the stack.
// - Ensure that each index is processed only once, making the approach linear in time complexity.

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(begin(prices), end(prices));
        stack<int> st;
        
        for(int i = 0; i < n; i++) {

            while(!st.empty() && prices[i] <= prices[st.top()]) {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

/************************************************************ Summary ************************************************************/

// **Why to use these DSAs:**
// - **Brute Force:** Easy to understand and implement, useful for small input sizes or initial explorations of the problem.
// - **Monotonic Stack:** Optimized for time complexity, suitable for problems involving finding next/previous greater/smaller elements efficiently.

// **Key Notes for Revision:**
// - Approach-1 is simple but inefficient for larger inputs.
// - Approach-2 leverages the stack to achieve linear time complexity.
// - Always consider edge cases like single-element arrays or arrays with all elements the same.
