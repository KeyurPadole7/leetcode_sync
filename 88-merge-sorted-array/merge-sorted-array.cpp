class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0){
            for(int i = 0; i<n; i++) nums1[i] = nums2[i];
            return;
        }

        vector<int> temp;
        temp.reserve(m+n);

        int i = 0;
        int j = 0;

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                temp.push_back(nums1[i++]);
            }
            else{
                temp.push_back(nums2[j++]);
            }
        }
        while(i<m) temp.push_back(nums1[i++]);
        while(j<n) temp. push_back(nums2[j++]);

        for(int i = 0; i<m+n; i++) nums1[i] = temp[i];
    }
};