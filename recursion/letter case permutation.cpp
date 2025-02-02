class Solution {
public:
vector<string>vec;
   void solve(string &output,string s){
    if(s.length()==0){
        vec.push_back(output);
        return;
    }

    else{
        if(isdigit(s[0])){
            string output1=output;
             output1.push_back(s[0]);
             s.erase(s.begin()+0);
             solve(output1,s);
        }
        else{
            string small=output;
            string capital=output;
            small.push_back(tolower(s[0]));
            capital.push_back(toupper(s[0]));
            s.erase(s.begin()+0);
            solve(small,s);
            solve(capital,s);
        }
    }
   }

    vector<string> letterCasePermutation(string s) {
        string output="";
        solve(output,s);
        return vec;
             
             
  }
};
