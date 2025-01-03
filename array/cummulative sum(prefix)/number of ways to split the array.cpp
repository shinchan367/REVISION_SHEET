// **Approach 1: Brute Force**
// - Logic: For every possible split point, calculate the sum of the left and right subarrays using nested loops.
// - Time Complexity: O(N^2) (Due to nested loops for sum calculation).
// - Space Complexity: O(1) (No extra space used).

/*
Steps:
1. Iterate through all indices as potential split points.
2. For each split:
   - Calculate the sum of the left subarray (0 to i).
   - Calculate the sum of the right subarray (i+1 to n-1).
   - If leftSum >= rightSum, increment the count.
3. Return the count of valid splits.
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using cummulativeSum array/Prefix Sum Array)
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
     
        vector<long long> cumSum(n);
        cumSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + nums[i];
        }

        int split = 0;
 
        for (int i = 0; i < n - 1; i++) {
            
            long long leftSum = cumSum[i];
            
            long long rightSum = cumSum[n - 1] - cumSum[i];

            if (leftSum >= rightSum) {
                split++;
            }
        }

        return split;
    }
};


//Approach-2 (Using cummulativeSum array/Prefix Sum Array)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        for(int &num : nums) {
            sum += num;
        }

        long long leftSum  = 0;
        long long rightSum = 0;
        int split = 0;

        for(int i = 0; i < n-1; i++) {
            leftSum += nums[i];

            rightSum = sum - leftSum;

            if(leftSum >= rightSum) {
                split++;
            }
        }
        return split;
    }
};

// **Approach 3: Optimized Prefix Sum**
// - Logic: Use a single pass with cumulative sums to avoid recalculating sums for each split.
// - Time Complexity: O(N) (Single pass for calculations).
// - Space Complexity: O(1) (No extra array used).

/*
Steps:
1. Compute the total sum of the array.
2. Initialize leftSum as 0.
3. Iterate through the array:
   - Update leftSum by adding the current element.
   - Calculate rightSum dynamically as totalSum - leftSum.
   - If leftSum >= rightSum, increment the count.
4. Return the count of valid splits.

Key Optimization:
- No need for extra prefix sum arrays. Right sum is derived dynamically.
*/
