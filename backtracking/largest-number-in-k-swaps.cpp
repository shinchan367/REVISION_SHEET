class Solution {
  public:
    // Function to find the largest number after k swaps.
    void solve(string&s,int k,string&res,int start){
        if(k==0 || start==s.size()-1){
            return;
        }
        char maxchar=*max_element(s.begin()+start+1,s.end());
        for(int i=start+1;i<s.size();i++){
            if(s[start]<s[i] && s[i]==maxchar){
                swap(s[start],s[i]);
                if(s.compare(res)>0)res=s;
                solve(s,k-1,res,start+1);
                 swap(s[start],s[i]);
            }
            solve(s,k,res,start+1);
        }
    }
    
    
    
    
    
    
    string findMaximumNum(string& s, int k) {
        // code here.
        string res=s;
        int start=0;
        solve(s,k,res,start);
    }
};
