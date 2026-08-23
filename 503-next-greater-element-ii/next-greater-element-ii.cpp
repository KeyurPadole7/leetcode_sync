class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), 0);

        for(int i=nums.size()-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i]) s.pop();
            ans[i] = s.empty()? INT_MAX : s.top();
            s.push(nums[i]);
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(ans[i] != INT_MAX) continue;
            while(!s.empty() && s.top()<=nums[i]) s.pop();
            ans[i] = s.empty()? -1 : s.top();
            s.push(nums[i]);
        }

        return ans;
    }
};