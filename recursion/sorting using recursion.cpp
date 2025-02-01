#include <iostream>
#include <vector>
using namespace std;

// Function to insert an element into a sorted vector
void insert(vector<int> &v, int value) {
    if (v.size() == 0 || v[v.size() - 1] <= value) {
        v.push_back(value);
        return;
    }
    int temp = v[v.size() - 1];  // Store last element
    v.pop_back();  // Remove last element
    insert(v, value);  // Recursively insert value in remaining sorted vector
    v.push_back(temp);  // Reinsert the removed element
}

// Recursive function to sort the vector
void sort(vector<int> &v) {
    if (v.size() == 1) {
        return;
    }
    int value = v[v.size() - 1];  // Store last element
    v.pop_back();  // Remove last element
    sort(v);  // Recursively sort the smaller vector
    insert(v, value);  // Insert the removed element at the correct position
}

int main() {
    vector<int> v = {1, 5, 0, 2, -6};
    sort(v);  // Call sorting function
    
    // Print sorted vector
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
