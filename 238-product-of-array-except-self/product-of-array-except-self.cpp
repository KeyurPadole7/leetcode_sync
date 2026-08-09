class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        vector<int> ans;
        int zeros = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeros ++;
                continue;
            }
            prod *= nums[i];
        }

        if(zeros == 0){
            for(int i = 0; i < n; i++){
                ans.push_back(prod/nums[i]);
            }
        }
        if(zeros == 1){
            for(int i = 0; i<n ; i++){
                if(nums[i] == 0){
                    ans.push_back(prod);
                } else ans.push_back(0);
            }
        }
        if(zeros>1){
            for(int i = 0; i < n; i++){
                ans.push_back(0);
            }
        }



        return ans;
    }
};