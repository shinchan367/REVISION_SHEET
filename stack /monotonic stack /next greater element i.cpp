#include<bits/stdc++.h>
using namespace std;

// Function to find the next greater element
vector<int> findnextgreater(int arr1[], int arr2[], int n1, int n2) {
    unordered_map<int, int> mp;
    stack<int> st;

    // Process arr2 to find the next greater elements
    for (int i = 0; i < n2; i++) {
        while (!st.empty() && st.top() < arr2[i]) {
            mp[st.top()] = arr2[i];
            st.pop();
        }
        st.push(arr2[i]);
    }

    // Create result vector for arr1
    vector<int> result(n1, -1);
    for (int i = 0; i < n1; i++) {
        if (mp.find(arr1[i]) != mp.end()) {
            result[i] = mp[arr1[i]];
        }
    }

    return result;
}

int main() {
    // Example arrays
    int arr1[] = {4, 1, 2};
    int arr2[] = {1, 3, 4, 2, 5};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Find next greater elements
    vector<int> result = findnextgreater(arr1, arr2, n1, n2);

    // Output the result
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
