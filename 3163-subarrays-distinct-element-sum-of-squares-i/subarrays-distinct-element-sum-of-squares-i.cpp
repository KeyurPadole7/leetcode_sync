class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum=0;

        for(int i=0; i<n; i++){
            int count=0;
            vector<bool> vis(101, false);
            for(int j=i; j<n; j++){
                if(!vis[nums[j]]){
                    count++;
                    vis[nums[j]] = true;
                }
                sum += count*count;
            }
        }

        return sum;
    }
};