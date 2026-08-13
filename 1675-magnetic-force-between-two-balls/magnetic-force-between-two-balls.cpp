class Solution {
public:
    bool isvalid(int val, vector<int>& arr, int m){
        int  count = 1;
        int lastball = arr[0];
        
        for(int i = 1; i<arr.size(); i++){
            if(arr[i] - lastball >= val){
                count ++;
                lastball = arr[i];
            }
            if(count == m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin(), arr.end());
        int l=1, h=arr[arr.size()-1] - arr[0];

        int sol, mid;

        while(l<=h){
            mid = l + (h-l)/2;

            cout<<mid<< endl;

            if(isvalid(mid, arr, m)){
                sol = mid;
                l = mid+1;
            }else h = mid-1;
        }

        return sol;
    }
};