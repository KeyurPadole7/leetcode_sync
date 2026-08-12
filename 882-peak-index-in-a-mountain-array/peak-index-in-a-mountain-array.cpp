class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, r=arr.size() - 1;
        int mid;

        while(l<=r){
            mid = l + (r-l)/2;
            if(0==mid && arr[mid]>arr[mid+1]) return mid;
            if(mid==arr.size()-1 && arr[mid-1]<arr[mid]) return mid;

            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;

            if(arr[mid-1]<arr[mid]) l = mid;
            else r = mid;
        }

        return mid;
    }
};