#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate increasing numbers
void solve(int &num, int remainingDigits, vector<int> &ans) {
    if (remainingDigits == 0) { // Base case: If no more digits needed
        ans.push_back(num); // Store the valid number in result
        return;
    }
    int largestDigit = num % 10; // Extract the last digit of num
    num *= 10; // Shift left to add the next digit
    
    // Loop through numbers greater than largestDigit to maintain increasing order
    for (int i = largestDigit + 1; i <= 9; i++) {
        num += i; // Append digit i to num
        solve(num, remainingDigits - 1, ans); // Recur for the next digit
        num -= i; // Backtrack: Remove last added digit
    }
    num /= 10; // Backtrack: Remove the added zero shift
}

// Function to initiate recursion and store results
vector<int> increasingNumbers(int n) {
    vector<int> ans;
    int num = 0;
    if (n == 1) ans.push_back(0); // Edge case for single digit numbers
    solve(num, n, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> result = increasingNumbers(n);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

/*
Dry Run for n = 2:
===================
Initial call: solve(0, 2, ans)

1st Call:
num = 0, remainingDigits = 2, largestDigit = 0
Loop i from 1 to 9:
  - Append 1 → num = 1, Call solve(1, 1, ans)

  2nd Call:
  num = 1, remainingDigits = 1, largestDigit = 1
  Loop i from 2 to 9:
    - Append 2 → num = 12, Call solve(12, 0, ans) → Add 12 to ans, Backtrack
    - Append 3 → num = 13, Call solve(13, 0, ans) → Add 13 to ans, Backtrack
    - Repeat for i = 4 to 9 → Add 14, 15, ..., 19
  - Backtrack to 1st Call

  - Append 2 → num = 2, Call solve(2, 1, ans)
    - Append 3 → num = 23, Call solve(23, 0, ans) → Add 23 to ans, Backtrack
    - Append 4 → num = 24, Call solve(24, 0, ans) → Add 24 to ans, Backtrack
    - Repeat for i = 5 to 9 → Add 25, ..., 29

  - Repeat for num = 3, ..., 8, generating numbers 34, 35, ..., 89

Final Output:
12, 13, 14, ..., 19, 23, ..., 29, 34, ..., 39, 45, ..., 49, 56, ..., 89
*/
