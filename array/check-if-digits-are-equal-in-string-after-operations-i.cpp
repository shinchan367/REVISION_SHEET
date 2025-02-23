class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.length()>2){
         string newd;
            for(size_t i=0;i<s.length()-1;i++){
                int firstdigit=s[i]-'0';
                int seconddigit=s[i+1]-'0';
                int newdigit=(firstdigit+seconddigit)%10;
                newd += to_string(newdigit);
            }
            s=newd;
        }
        return s[0]==s[1];
    }
};
