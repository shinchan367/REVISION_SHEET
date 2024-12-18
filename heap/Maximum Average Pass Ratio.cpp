/*
    Why normal Greedy fails ?
    Assigning extra students to the class with the least passing ratio assumes that improving the worst-performing class will maximize the overall average.
    However, this ignores the fact that the rate of improvement (or marginal gain) varies depending on the current number of passing and total students
    in the class. A class with a low passing ratio might require many additional students to see a significant improvement in its passing ratio,
    while a class with a higher passing ratio might see a much larger improvement with the same number of extra students.
*/

/************************************************************ C++ ************************************************/
//Approach-1 : (Chossing class with max delta/improvement everytime) - Will give TLE/MLE
//T.C : O(extraStudents * n)
//S.C : O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--) { //O(n)
            //student 0

            vector<double> updatedPR(n);
            for(int i = 0; i < n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { //O(n)
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; //AR
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
};



//Approach-2 : (Chossing class with max delta/improvement everytime - Improving with max heap)
//T.C : O(extraStudents * log(n))
//S.C : O(n)
class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  //{max-delta, idx}

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        //O(extraStudents * log(n))
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students oin the class

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};
/*
Revision Notes: Maximum Average Pass Ratio
-------------------------------------------------------------

Problem: Given `n` classes, each represented as `[passed, total]`, and `extraStudents` to distribute, maximize the average pass ratio. Each class has a pass ratio:
PR = passed / total.

Objective: Distribute the extra students among classes to maximize the average pass ratio.

Approaches:

1. **Brute Force (Choosing Class with Max Improvement Repeatedly)**:
   - **T.C**: O(extraStudents * n) --> Iterating over classes for each student.
   - **S.C**: O(n) --> For storing pass ratios.
   - **Logic**:
     - Compute pass ratio for each class.
     - For each extra student, calculate the improvement for all classes and assign the student to the class with the maximum improvement.
   - **Algorithm**:
     1. Calculate initial pass ratios for all classes.
     2. For each extra student:
        - Compute the improvement (\(\Delta\)) for adding one student to each class.
        - Assign the student to the class with the maximum \(\Delta\).
     3. Compute the average pass ratio.

2. **Optimized Using Max-Heap**:
   - **T.C**: O(extraStudents * log(n)) --> Heap operations for each student.
   - **S.C**: O(n) --> For heap and pass ratio storage.
   - **Logic**:
     - Use a max-heap to efficiently track the class with the maximum improvement.
     - Recompute \(\Delta\) and push back updated values into the heap.
   - **Algorithm**:
     1. Initialize a max-heap with \((\Delta, classIndex)\) for all classes.
     2. For each extra student:
        - Pop the class with the maximum \(\Delta\) from the heap.
        - Add the student and recompute \(\Delta\).
        - Push the updated \(\Delta\) back into the heap.
     3. Compute the average pass ratio.

Functions to Remember:
1. **`priority_queue`** --> Max-heap by default in C++.
   - Syntax: `priority_queue<pair<double, int>> pq;`

Comparison:
- **Brute Force**: Easy to understand but inefficient for large inputs.
- **Heap Optimization**: Scales well with larger datasets due to logarithmic heap operations.

*/
