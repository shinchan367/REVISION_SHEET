class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int sum=0;
        for(int i=0;i<asteroids.size();i++){
            int a=asteroids[i];
       while(a<0 && !st.empty() && st.top()>0){
             sum=a+st.top();
        if(sum>0){
            a=0;
            break;
        }
        else if(sum<0){
            st.pop();
        }
        else{
            st.pop();
            a=0;
        }
       }
        if(a!=0){
            st.push(a);
        }
        }
        int s=st.size();
        vector<int>result(s);
        int n=s-1;
        while(!st.empty()){
            result[n]=st.top();
            st.pop();
            n--;
        }
       return result;
    }
};
