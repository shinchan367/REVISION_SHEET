
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       int original=count(nums.begin(),nums.end(),k),mx=0;
        for(int m=1;m<=50;m++){
            if(m==k)continue;
            int cnt=0,maxi=0;
            for(auto n:nums){
                cnt+= n==m ?1:n==k ?-1:0;
                cnt=max(cnt,0);
                maxi=max(maxi,cnt);

            }
            mx=max(mx,maxi);
        }
        return mx+original;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) { 
        vector<int> dp(51, 0); 
        int maxi=0,cnt=0;
        for(auto i:nums){
            if(i == k) cnt++;
            else dp[i]=max(dp[i],cnt)+1;

            maxi=max(maxi,dp[i]-cnt);
        }

        return maxi+cnt;
    }
};
