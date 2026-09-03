class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1) return true;
        int mn = INT_MAX;
        bool alleven = true;
        for(int val: nums1){
            mn = min(mn, val);
            if(val%2 == 1) alleven = false;
        }

        if(mn%2 == 1) return true;
        return alleven? true: false;
    }
};