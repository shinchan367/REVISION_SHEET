/************************************************************ C++ ************************************************************/
//Approach-1 (Sorting array with indices)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        long long score = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) { //O(n)
            int element = vec[i].first;
            int idx     = vec[i].second;
            if(visited[idx] == false) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && visited[idx-1] == false) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && visited[idx+1] == false) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};



//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {//n
            pq.push({nums[i], i}); //log(n)
        }

        long long score = 0;
        while(!pq.empty()) { //n
            P temp = pq.top();
            int element = temp.first;
            int idx = temp.second;
            pq.pop(); //log(n)

            if(!visited[idx]) {
                visited[idx] = true;
                score += element;

                if(idx-1 >= 0 && !visited[idx-1]) {
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]) {
                    visited[idx+1] = true;
                }
            }
        }

        return score;
    }
};

/*
Revision Notes: Find Score from Array
-------------------------------------------------------------

Problem: Given an array `nums`, calculate the score as follows:
1. Traverse the array and select elements one by one.
2. If an element is selected, its neighbors are also marked as visited.
3. Add the selected element's value to the score.

Objective: Return the maximum score achievable by following the rules.

Approaches:
1. **Sorting Array with Indices**:
   - **T.C**: O(nlogn) --> Sorting + Iteration.
   - **S.C**: O(n) --> For visited array and vector of pairs.
   - **Logic**:
     - Pair each element with its index and sort by value.
     - Traverse sorted array and check if the index is unvisited.
     - If unvisited, add the element's value to the score and mark neighbors as visited.
   - **Algorithm**:
     1. Create a vector of pairs `{nums[i], i}`.
     2. Sort the vector based on element values.
     3. Iterate through the sorted vector:
        - If the current index is unvisited:
          - Add the element value to the score.
          - Mark current, previous, and next indices as visited.
     4. Return the score.

2. **Using Min-Heap**:
   - **T.C**: O(nlogn) --> Heap operations.
   - **S.C**: O(n) --> For visited array and heap storage.
   - **Logic**:
     - Use a min-heap to process elements in ascending order.
     - Pop elements one by one and check if the index is unvisited.
     - If unvisited, add the element's value to the score and mark neighbors as visited.
   - **Algorithm**:
     1. Push all elements with their indices into a min-heap.
     2. While the heap is not empty:
        - Pop the smallest element.
        - If its index is unvisited:
          - Add the element value to the score.
          - Mark current, previous, and next indices as visited.
     3. Return the score.

Functions to Remember:
1. **`sort`** --> Sorts vector of pairs.
   - Syntax: `sort(begin(v), end(v));`

2. **`priority_queue` (Min-Heap)** --> Min-heap using `greater<>`.
   - Syntax: `priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;`

Comparison:
- **Sorting Approach**: Simple to implement and efficient for static inputs.
- **Min-Heap Approach**: More dynamic and leverages STL heap properties for efficiency.

*/
