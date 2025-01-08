class Solution {
public:
    vector<long long> nextSmallerElements(const vector<int>& heights) {
        int n = heights.size();
        vector<long long> v2(n);
        stack<pair<long long, int>> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top().first >= heights[i]) {
                s.pop();
            }
            v2[i] = s.empty() ? n : s.top().second;
            s.push({heights[i], i});
        }
        return v2;
    }
    
    vector<long long> prevSmallerElements(const vector<int>& heights) {
        int n = heights.size();
        vector<long long> v1(n);
        stack<pair<long long, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first >= heights[i]) {
                s.pop();
            }
            v1[i] = s.empty() ? -1 : s.top().second;
            s.push({heights[i], i});
        }
        return v1;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<long long> v1 = prevSmallerElements(heights);
        vector<long long> v2 = nextSmallerElements(heights);
        int n = heights.size();
        long long maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            long long width = v2[i] - v1[i] - 1;
            long long area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
