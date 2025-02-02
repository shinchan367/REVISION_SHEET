void solve(int open,int close,string output,vector<string>&ans){
    if(close==0 && open ==0){
        ans.push_back(output);
        return;
    }
    if(open!=0){
        string output1=output;
        output1.push_back('(');
        solve(open-1,close,output1,ans);
    }
    if(close>open){
        string output2=output;
        output2.push_back(')');
        solve(open,close-1,output2,ans);
    }
    
}




vector<string> Solution::generateParenthesis(int A) {
    string output="";
    int close=A;
    int open=A;
    vector<string>ans;
    solve(open,close,output,ans);
    return ans;
}
//////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void solve(int open, int close, string output, vector<string>& ans) {
        if (close == 0 && open == 0) {
            ans.push_back(output);
            return;
        }
        if (open > 0) {
            solve(open - 1, close, output + "(", ans);
        }
        if (close > open) {
            solve(open, close - 1, output + ")", ans);
        }
    }

    vector<string> generateParenthesis(int A) {
        vector<string> ans;
        solve(A, A, "", ans);
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////
//here is the base condition

if (open == 0) {
    for (int i = 0; i < close; i++) {
      op.push_back(')');
    }
    vec.push_back(op);
    return;
  }
