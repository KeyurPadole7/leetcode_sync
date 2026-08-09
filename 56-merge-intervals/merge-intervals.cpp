class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        ans.push_back(intervals[0]);

        for(int i = 0; i < intervals.size(); i++){
            if(ans[ans.size()-1][1]>=intervals[i][0]) ans[ans.size()-1][1] = max(intervals[i][1],ans[ans.size()-1][1]) ;
            else ans.push_back(intervals[i]);
        }

        return ans;
    }
};