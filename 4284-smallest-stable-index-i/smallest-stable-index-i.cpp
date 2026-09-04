class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax;
        vector<int> postmin(n);

        premax.push_back(nums[0]);
        postmin[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            premax.push_back(max(premax.back(), nums[i]));
            postmin[n-i-1] = min(postmin[n-i], nums[n-i-1]);
        }

        for(int i=0; i<n; i++){
            if(premax[i]-postmin[i]<=k) return i;
        }

        return -1;
    }
};