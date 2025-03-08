
      class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        // Count the frequency of each number in nums
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int maxEle = -1, maxEleFreq = -1;

        // Find the largest element and the largest unique element
        for (auto it : mp) {
            if (it.second == 1) 
                maxEleFreq = max(maxEleFreq, it.first);
            maxEle = max(maxEle, it.first);
        }

        if (k == 1) 
            return maxEleFreq;
        else if (k == n) 
            return maxEle;
        else {
            if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1)
                return max(nums[0], nums[n - 1]);
            else if (mp[nums[n - 1]] == 1) 
                return nums[n - 1];
            else if (mp[nums[0]] == 1) 
                return nums[0];
        }

        return -1;
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
