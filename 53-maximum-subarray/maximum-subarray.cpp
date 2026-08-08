class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int sum = 0;
        int i = 0;
        
        while( i<nums.size() && nums[i] <= 0 ){
            maxsum = max(maxsum, nums[i]);
            i++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(sum+nums[i]>0){
                sum += nums[i];
                maxsum = max(sum, maxsum);
            }
            else{
                sum = 0;
            }
        }

        return maxsum;
    }
};