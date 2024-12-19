/**************************************************************** C++ ****************************************************************/

// **Problem Description:**
// Given a string `s` consisting of lowercase English letters and an integer `repeatLimit`, construct the lexicographically largest string 
// such that no character appears more than `repeatLimit` consecutive times. Return the constructed string.
// 
// Constraints:
// - `1 <= s.length <= 10^5`
// - `1 <= repeatLimit <= s.length`
// - `s` consists of lowercase English letters.

// **Approach-1 (Using pointers and frequency table)**

// **Algorithm:**
// 1. Count the frequency of each character in the string using a frequency table.
// 2. Start iterating from the largest character ('z').
// 3. Append the character up to `repeatLimit` times to the result string.
// 4. If more occurrences of the character remain, find the next largest character and add it to break the repetition.
// 5. Continue until all characters are processed or no valid next character exists.

// **Why use this approach?**
// This approach leverages the fixed size of the alphabet (26 lowercase letters) to iterate efficiently. It is simple and avoids unnecessary overhead while guaranteeing a lexicographically largest valid result.

// **Complexity:**
// - Time Complexity (T.C): O(n)
// - Space Complexity (S.C): O(26) for the frequency table.

// **Points to Remember / Syntax:**
// - `vector<int> count(26, 0);` initializes the frequency table.
// - `result.append(freq, ch);` appends a character `freq` times to the result.
// - `while(j >= 0 && count[j] == 0)` skips over characters with zero frequency.

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); // Frequency table for 26 lowercase letters

        // Step 1: Count frequency of each character in the string (T.C: O(n))
        for(char &ch : s) {
            count[ch - 'a']++;
        }

        string result;
        int i = 25; // Start from the largest character ('z')

        // Step 2: Build the result string by processing the frequency table
        while(i >= 0) { // O(26)
            if(count[i] == 0) { // Skip characters with zero frequency
                i--;
                continue;
            }

            char ch = 'a' + i; // Get the character
            int freq = min(count[i], repeatLimit); // Append up to repeatLimit times

            result.append(freq, ch); // Add character to the result
            count[i] -= freq; // Reduce its frequency

            if(count[i] > 0) { // If more occurrences of `ch` remain
                // Find the next largest character to break the repetition
                int j = i - 1;
                while(j >= 0 && count[j] == 0) { // O(26)
                    j--;
                }

                if(j < 0) { // If no more characters are available
                    break;
                }

                result.push_back('a' + j); // Add the next largest character
                count[j]--; // Reduce its frequency
            }
        }

        return result; // Return the constructed string
    }
};

// **Approach-2 (Using max-heap + frequency table)**

// **Algorithm:**
// 1. Count the frequency of each character in the string.
// 2. Push all characters with non-zero frequency into a max-heap.
// 3. Extract the largest character and append it up to `repeatLimit` times to the result.
// 4. If more occurrences of the character remain, temporarily add the next largest character to break the repetition and reinsert the previous character into the heap.
// 5. Repeat until the heap is empty.

// **Why use this approach?**
// The max-heap dynamically handles the selection of the largest character at every step. This approach is flexible and works well for scenarios where character availability changes dynamically.

// **Complexity:**
// - Time Complexity (T.C): O(n)
// - Space Complexity (S.C): O(26) for the frequency table and heap.

// **Points to Remember / Syntax:**
// - `priority_queue<char> pq;` initializes a max-heap to process characters.
// - `result.append(freq, ch);` appends a character up to the repeat limit.
// - `if(count[nextChar - 'a'] > 0) pq.push(nextChar);` ensures unused characters are re-added to the heap.

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); // Frequency table

        // Step 1: Count frequency of each character in the string
        for(char &ch : s) {
            count[ch - 'a']++;
        }

        // Step 2: Use a max-heap (priority queue) to process characters
        priority_queue<char> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                char ch = 'a' + i;
                pq.push(ch); // Push characters with positive frequency into the heap
            }
        }

        string result;

        // Step 3: Build the result string using the max-heap
        while(!pq.empty()) {
            char ch = pq.top(); // Get the largest character
            pq.pop();

            int freq = min(count[ch - 'a'], repeatLimit); // Append up to repeatLimit times
            result.append(freq, ch); // Add character to the result
            count[ch - 'a'] -= freq; // Reduce its frequency

            if(count[ch - 'a'] > 0 && !pq.empty()) { // If `ch` still has frequency left
                char nextChar = pq.top(); // Get the next largest character
                pq.pop();

                result.push_back(nextChar); // Add it to break repetition
                count[nextChar - 'a']--; // Reduce its frequency

                if(count[nextChar - 'a'] > 0) {
                    pq.push(nextChar); // Push it back if more occurrences remain
                }

                pq.push(ch); // Reinsert `ch` back into the heap
            }
        }

        return result; // Return the constructed string
    }
};

/**************************************************************** Summary ****************************************************************/

// **Why to use these DSAs:**
// - **Frequency Table:** Efficiently tracks character counts in O(1) for each operation. Used in both approaches.
// - **Pointers:** Simplifies traversal in fixed-size datasets (Approach-1).
// - **Max-Heap:** Dynamically selects the largest character, ideal for lexicographical order with constraints (Approach-2).

// **Key Notes for Revision:**
// - Approach-1 is straightforward and optimal for fixed-size alphabets.
// - Approach-2 is dynamic and suited for more general cases or larger character sets.
// - Always verify constraints like `repeatLimit` and edge cases (e.g., single character strings).
