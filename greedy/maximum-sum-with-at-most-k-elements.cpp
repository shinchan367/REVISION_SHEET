class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<pair<int,int>>vec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vec.push_back({grid[i][j],i});
            }
        }
        sort(vec.rbegin(),vec.rend());
        vector<int>count(grid.size(),0);
        long long sum=0;
        int selected=0;
        for(const auto&[value,row]:vec){
            if(count[row]<limits[row] && selected<k){
                sum+=value;
                count[row]++;
                selected++;

            }
            if(selected==k)break;
        }
        return sum;
    }
};
