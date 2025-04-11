class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
         
         for(int i=low;i<=high;i++){
            string s=to_string(i);
            int l=s.length();
            if(l%2!=0){
                continue;
            }  
                int firstsum = 0;
            int secondsum = 0;

            for(int j=0;j<l/2;j++){
                firstsum+=s[j]-'0';
            }  
            for(int j=l/2;j<l;j++){
                 secondsum+=s[j]-'0';
            } 
                   if(firstsum==secondsum){
                    count++;
                   }     
         }
          return count;       
    }
};
