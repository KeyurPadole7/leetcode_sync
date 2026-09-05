class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        vector<int> premax(n);
        vector<int> postmin(n);

        premax[0] = nums[0];
        postmin[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            premax[i] = max(premax[i-1], nums[i]);
            postmin[n-i-1] = min(postmin[n-i], nums[n-i-1]);
        }

        for(int i=0; i<n; i++){
            if(premax[i] - postmin[i] <= k) return i;
        }

        return -1;
    }
};