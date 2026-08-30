class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mni, mxi;
        int mn = INT_MAX, mx = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] < mn){
                mn = nums[i];
                mni = i;
            }
            if(nums[i] > mx){
                mx = nums[i];
                mxi = i;
            }
        }

        int rt = n - abs(mxi-mni) + 1;
        if(mni < mxi) rt = min(rt, min(mxi+1, n-mni));
        else rt = min(rt, min(mni+1, n-mxi));

        return rt;
    }
};