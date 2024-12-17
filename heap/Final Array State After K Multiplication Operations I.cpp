/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int j = 0; j < k; j++) {

            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
};


//Approach-2 (Using stl::priority_queue)
//T.C : O(nlogn + klogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while(k--) {
            pair<int, int> temp = pq.top();
            pq.pop();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            pq.push({nums[idx], idx});
        }

        return nums;
    }
};


//Approach-3 (Using vector as heap for O(n) heapify)
//T.C : O(n + klogn)
//S.C : O(n)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        make_heap(begin(vec), end(vec), greater<>());

        while(k--) {
            pop_heap(begin(vec), end(vec), greater<>());
            pair<int, int> temp = vec.back();
            vec.pop_back();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            vec.push_back({nums[idx], idx});
            push_heap(begin(vec), end(vec), greater<>());
        }

        return nums;
    }
};

/*
Revision Notes: Get Final State of Array
-------------------------------------------------------------

Problem: Given an array `nums`, apply the following operation `k` times:
- Find the minimum element in the array.
- Multiply the minimum element by `multiplier`.

Objective: Return the final state of the array.

Approaches:
1. **Brute Force**:
   - **T.C**: O(n * k) --> Linear search for minimum * k iterations.
   - **S.C**: O(1).
   - **Logic**: Repeatedly find the minimum element and update it.
   - **Algorithm**:
     1. Loop `k` times.
     2. Find the index of the minimum element by iterating through the array.
     3. Multiply the minimum element by `multiplier`.
     4. Update the array.
     5. Repeat.

2. **priority_queue (Min-Heap)**:
   - **T.C**: O(nlogn + klogn) --> Heap initialization + k updates.
   - **S.C**: O(n).
   - **Logic**: Use STL `priority_queue` to efficiently extract and update the minimum element.
   - **Algorithm**:
     1. Create a `priority_queue` (min-heap) of pairs `{nums[i], i}`.
     2. Extract the top element (minimum) `k` times.
     3. Update the corresponding array index by multiplying with `multiplier`.
     4. Push the updated value back into the heap.
     5. Repeat `k` times.

3. **Custom Vector Heap**:
   - **T.C**: O(n + klogn) --> Heapify + k updates.
   - **S.C**: O(n).
   - **Logic**: Use `make_heap`, `pop_heap`, and `push_heap` to implement a min-heap with vector.
   - **Algorithm**:
     1. Convert the array into a heap using `make_heap` with `greater<>`.
     2. Perform `k` iterations:
        - Use `pop_heap` to extract the minimum value.
        - Multiply the value by `multiplier` and update the array.
        - Push the updated value back into the heap using `push_heap`.
     3. Return the updated array.

Functions to Remember:
1. **`priority_queue`** --> Min-heap using `greater<>`.
   - Syntax: `priority_queue<int, vector<int>, greater<int>> pq;`

2. **`make_heap`** --> Converts vector into a valid heap.
   - Syntax: `make_heap(v.begin(), v.end(), greater<>());`

3. **`pop_heap`** --> Removes top element and re-heapifies.
   - Syntax:
     ```cpp
     pop_heap(v.begin(), v.end(), greater<>());
     v.pop_back(); // Remove the last element manually
     ```

4. **`push_heap`** --> Adds a new element and restores heap property.
   - Syntax:
     ```cpp
     v.push_back(new_element);
     push_heap(v.begin(), v.end(), greater<>());
     ```

Comparison:
- **Brute Force**: Suitable for small inputs.
- **priority_queue**: Optimal for larger inputs, leverages STL.
- **Custom Vector Heap**: Slightly better T.C with manual heap operations.

*/
