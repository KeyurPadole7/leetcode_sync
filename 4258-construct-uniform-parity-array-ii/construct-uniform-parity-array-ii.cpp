class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1) return true;
        int mn = INT_MAX;
        for(int val: nums1) mn = min(mn, val);

        if(mn%2 == 1) return true;

        for(int val: nums1) if(val%2 == 1) return false;

        return true;
    }
};