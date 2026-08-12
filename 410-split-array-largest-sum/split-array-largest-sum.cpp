class Solution {
public:
    bool isvalid(int mid, vector<int>& nums, int k){
        int count=0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){ 
            if(count>=k) return false;
            if(nums[i]>mid) return false;

            sum = 0;
            while(i<nums.size() && sum+nums[i]<=mid){
                sum += nums[i];
                i++;
            }
            i--;
            count++;
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=0, h=accumulate(nums.begin(), nums.end(), 0);
        int mid;
        int ans = -1;

        while(l<=h){
            mid = l+(h-l)/2;

            if(isvalid(mid, nums, k)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};