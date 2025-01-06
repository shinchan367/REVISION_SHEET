class Solution {
public:
vector<int>getright(vector<int>&height,int n){
    vector<int>right(n);
    right[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],height[i]);
    }
    return right;
}
vector<int>getleft(vector<int>&height,int n){
    vector<int>left(n);
    left[0]=height[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],height[i]);
    }
    return left;
}

    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2){
            return 0;
        }
        vector<int>left=getleft(height,n);
        vector<int>right=getright(height,n);
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=min(left[i],right[i])-height[i];
        }
        return sum;
    }
};
