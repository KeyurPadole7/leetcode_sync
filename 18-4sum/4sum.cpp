class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 4) return ans;
        
        long long sum = 0;
        int k,l;

        for(int i = 0; i<n-3; i++){
            for(int j = i + 1; j<n-2; j++){
                k = j + 1;
                l = n-1;

                while(k<l && l<n){
                    sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        while(k<l && nums[k] == nums[k+1]) k++;
                        while(k<l && nums[l] == nums[l-1]) l--;
                        k++;l--;
                    }else if(sum>target) l--;
                    else k++;
                }
                while(j<n-2 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-2 && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};