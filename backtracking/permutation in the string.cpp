#include <bits/stdc++.h>
using namespace std;

void permutation(string &input, vector<string> &vec, int start) {
    if (start == input.size() - 1) {
        vec.push_back(input);
        return;
    }

    unordered_map<char, int> mp; // Map to track used characters
    for (int i = start; i < input.size(); i++) {
        if (mp.find(input[i]) == mp.end()) { // Fix: Corrected condition
            mp[input[i]]++; // Mark character as used

            swap(input[i], input[start]); // Swap
            permutation(input, vec, start + 1); // Recursive call
            swap(input[i], input[start]); // **Backtracking step**
        }
    }
}

int main() {
    string input = "abc";
    vector<string> vec;
    permutation(input, vec, 0);

    // Print the generated permutations
    for (const string &s : vec) {
        cout << s << endl;
    }

    return 0;
}
