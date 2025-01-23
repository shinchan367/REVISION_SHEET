#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the next greater element to the right
vector<int> nextGreaterToRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }
    return result;
}

// Function to find the next greater element to the left
vector<int> nextGreaterToLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }
    return result;
}

// Function to find the next smaller element to the right
vector<int> nextSmallerToRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }
    return result;
}

// Function to find the next smaller element to the left
vector<int> nextSmallerToLeft(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }
    return result;
}

// Test the functions
int main() {
    vector<int> nums = {4, 5, 2, 10, 8};

    vector<int> ngr = nextGreaterToRight(nums);
    vector<int> ngl = nextGreaterToLeft(nums);
    vector<int> nsr = nextSmallerToRight(nums);
    vector<int> nsl = nextSmallerToLeft(nums);

    cout << "Next Greater to Right: ";
    for (int num : ngr) cout << num << " ";
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int num : ngl) cout << num << " ";
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int num : nsr) cout << num << " ";
    cout << endl;

    cout << "Next Smaller to Left: ";
    for (int num : nsl) cout << num << " ";
    cout << endl;

    return 0;
}
