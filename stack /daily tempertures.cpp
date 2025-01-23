class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>result(n,0);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                    st.pop();
            }
            if(!st.empty()){
                result[i]=st.top().second-i;
            }
            st.push({temperatures[i],i});

        }

        return result;
        }
};

////////////////////////////////////////////
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        
        vector<int> result(n);
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i; //days
            }
            
            st.push(i);
        }
        
        return result;
        
    }
};
