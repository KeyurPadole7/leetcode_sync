class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxw = 0;

        int l = 0;
        int r = n - 1;

        while(l<r){
            maxw = max(maxw, min(height[l],height[r])*(r-l));
            if(height[l] < height[r]) l++;
            else r--;
        }

        return maxw;
        
    }
};