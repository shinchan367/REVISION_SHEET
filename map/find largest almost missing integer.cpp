class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int res = -1;

        // Edge case: If k == n, return the max element
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Traverse all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Count frequencies in the current subarray
            for (int j = 0; j < k; j++) {
                freq[nums[i + j]]++;
            }

            // Find the largest number appearing exactly once in this subarray
            for (auto& it : freq) {
                if (it.second == 1) {
                    res = max(res, it.first);
                }
            }
        }

        return res;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int res = -1;

        // First k elements (initialize frequency map)
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        // Find the largest unique element in the first window
        for (auto& it : freq) {
            if (it.second == 1) {
                res = max(res, it.first);
            }
        }

        // Sliding window
        for (int i = k; i < n; i++) {
            // Remove outgoing element (leftmost in window)
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);  // Remove from map if count becomes 0
            }

            // Add new incoming element
            freq[nums[i]]++;

            // Check for largest unique element
            for (auto& it : freq) {
                if (it.second == 1) {
                    res = max(res, it.first);
                }
            }
        }

        return res;
    }
};
