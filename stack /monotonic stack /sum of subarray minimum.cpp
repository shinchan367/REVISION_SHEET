class Solution {
public:
 vector< int> getnsl(vector<int>&arr,int n){
 vector<int> result(n);
        stack<int> st;
       for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
     }
    vector<int>getnsr(vector<int>&arr,int n){
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
     }


    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSL =getnsl(arr,n);
        vector<int>NSR =getnsr(arr,n);
        long long sum=0;
        int m=1e9+7;
        for(int i=0;i<n;i++){
            long long d1=i-NSL[i];
            long long d2=NSR[i]-i;
            long long product=d1*d2;
            long long totalsum=arr[i]*product;
            sum=(sum+totalsum)%m;
        }
        return sum;;
    }
};
