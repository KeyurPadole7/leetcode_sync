class Solution {
public:
    set<vector<int>> s;
    void combsum(vector<int> &arr, int tar, int idx, vector<int> &ctr, vector<vector<int>> &ans){
        if(tar == 0){
            if(s.contains(ctr)) return;
            ans.push_back(ctr);
            s.insert(ctr);
            return;
        }if(tar < 0 || idx == arr.size()) return;

        ctr.push_back(arr[idx]);
        combsum(arr, tar-arr[idx], idx+1, ctr, ans);
        combsum(arr, tar-arr[idx], idx, ctr, ans);

        ctr.pop_back();
        combsum(arr, tar, idx+1, ctr, ans);
        
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> ctr;
        combsum(arr, tar, 0, ctr, ans);

        sort(arr.begin(), arr.end());
        return ans;
    }
};