// Revision Notes for "Next Larger Element" Problem

// Steps for Optimal Solution (Using Stack)
// Time Complexity: O(n)
// Space Complexity: O(n)
// 1. Create a result array (vec) to store the next greater elements.
// 2. Use a monotonic decreasing stack to keep track of elements.
// 3. Traverse the array from right to left.
//    - While the stack is not empty and the top of the stack is <= current element, pop the stack.
//    - If the stack becomes empty, no greater element exists for the current element; assign -1.
//    - Otherwise, assign the top of the stack as the next greater element for the current element.
//    - Push the current element onto the stack.
// 4. Return the result array.

// Steps for Brute Force Solution
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// 1. Iterate through each element in the array.
// 2. For each element, iterate through the elements to its right.
//    - If a greater element is found, update the current element with that value and break the inner loop.
//    - If no greater element is found, assign -1 to the current element.
// 3. Return the modified array.

// Steps for Better Solution (Using Auxiliary Array)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// 1. Create an auxiliary array initialized to -1 to store results.
// 2. Iterate through each element in the array.
// 3. For each element, iterate through the elements to its right.
//    - If a greater element is found, update the auxiliary array with that value and break the inner loop.
// 4. Return the auxiliary array.

// Key Points:
// 1. Optimal solution uses a monotonic decreasing stack to achieve O(n) complexity.
// 2. Brute force and auxiliary array approaches have O(n^2) complexity due to nested loops.
// 3. Edge Cases:
//    - Descending order array (e.g., [5, 4, 3, 2, 1]): All elements have next greater as -1.
//    - Ascending order array (e.g., [1, 2, 3, 4, 5]): Each element except the last has the next element as the next greater.
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElementOptimized(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // Initialize result with -1 (for elements with no next greater element)
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];  // Update the next greater element for the element at index s.top()
            s.pop();
        }
        s.push(i);  // Push the index of the current element
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElementOptimized(arr);

    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElementBruteForce(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // Initialize result with -1 (for elements with no next greater element)

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;  // Stop once the next greater element is found
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElementBruteForce(arr);

    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
