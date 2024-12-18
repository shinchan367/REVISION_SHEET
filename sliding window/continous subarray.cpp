/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using Ordered Map)
//T.C : ~O(n) - Explained in the video why O(n) ?
//S.C : ~O(1) - Explained in the video why O(1) ?
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long count = 0;

        while(j < n) {
            mp[nums[j]]++;
            
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2) { //it means it is out of the bound
                //shrink window -move i index
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};



//Approach-2 (Using Ordered Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;


        int i = 0;
        int j = 0;
        long long count = 0;

        while(j < n) { //O(n)
            minHeap.push({nums[j], j}); //Log(n)
            maxHeap.push({nums[j], j}); //Log(n)

            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            count += j-i+1;
            j++;
        }
        //T.C: O(nlogn)
        return count;
    }
};

/*
Revision Notes: Continuous Subarrays Problem
-------------------------------------------------------------

Problem: Given an array `nums`, count the number of continuous subarrays such that the difference 
between the maximum and minimum element in the subarray is less than or equal to 2.

Objective: Return the total count of such subarrays.

-------------------------------------------------------------
Approaches and Algorithms:

Approach-1: Using Ordered Map (Efficient Sliding Window)
-------------------------------------------------------------
**Why Ordered Map?**
- An ordered map (implemented as a balanced BST) allows efficient tracking of minimum and maximum keys.
- The keys maintain a sorted order, making it easy to compute the range of values within the window.
- Efficient shrinking of the window by updating frequencies or erasing elements.

**Algorithm:**
1. Initialize a sliding window with `i` and `j` pointing to the start of the array.
2. Use an ordered map to store element frequencies in the current window.
3. Extend the window by inserting `nums[j]` into the map.
4. If the difference between the smallest and largest keys exceeds 2:
   - Shrink the window by incrementing `i` and adjusting the map.
   - Remove elements with zero frequency.
5. Count valid subarrays using the window size `j - i + 1`.
6. Return the total count.

**Code Implementation:**
```cpp
long long continuousSubarrays(vector<int>& nums) {
    int n = nums.size();
    map<int, int> mp; // Ordered map to store frequencies of elements.

    int i = 0, j = 0;
    long long count = 0;

    while (j < n) {
        mp[nums[j]]++;

        // Shrink the window if difference exceeds 2
        while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }

        count += j - i + 1;
        j++;
    }

    return count;
}
```

**Syntax to Remember:**
- `mp.begin()->first`: Access the smallest key in the map.
- `mp.rbegin()->first`: Access the largest key in the map.
- `mp.erase(key)`: Remove a key from the map.

-------------------------------------------------------------

Approach-2: Using Priority Queues (Min-Heap and Max-Heap)
-------------------------------------------------------------
**Why Priority Queues?**
- Priority queues efficiently track the smallest and largest elements in the window.
- A min-heap maintains the smallest element, while a max-heap maintains the largest.
- Helps dynamically update and validate the window bounds with efficient push/pop operations.

**Algorithm:**
1. Initialize two priority queues (min-heap and max-heap).
2. Maintain a sliding window with indices `i` and `j`.
3. Extend the window by adding `nums[j]` to both heaps.
4. If the difference between the roots of the heaps exceeds 2:
   - Increment `i` to shrink the window.
   - Remove stale elements (indices less than `i`) from the heaps.
5. Count valid subarrays using the window size `j - i + 1`.
6. Return the total count.

**Code Implementation:**
```cpp
long long continuousSubarrays(vector<int>& nums) {
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    priority_queue<pair<int, int>> maxHeap;

    int i = 0, j = 0;
    long long count = 0;

    while (j < n) {
        minHeap.push({nums[j], j});
        maxHeap.push({nums[j], j});

        // Shrink the window if difference exceeds 2
        while (abs(maxHeap.top().first - minHeap.top().first) > 2) {
            i++;

            // Remove stale elements
            while (!maxHeap.empty() && maxHeap.top().second < i) {
                maxHeap.pop();
            }
            while (!minHeap.empty() && minHeap.top().second < i) {
                minHeap.pop();
            }
        }

        count += j - i + 1;
        j++;
    }

    return count;
}
```

**Syntax to Remember:**
- `minHeap.push({value, index})`: Add element to min-heap.
- `maxHeap.push({value, index})`: Add element to max-heap.
- `minHeap.top()`: Get the smallest element.
- `maxHeap.top()`: Get the largest element.
- `minHeap.pop() / maxHeap.pop()`: Remove the root element from the heap.

-------------------------------------------------------------

Comparison:
- **Ordered Map**: Simpler and more efficient for this problem due to constant time for range checks and efficient shrinking.
- **Priority Queues**: Useful when direct dynamic range tracking is needed but involves higher overhead for maintaining heap properties.
*/
