class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;

        for(int i=0; i<k-1; i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
        }

        vector<int> sol;

        for(int i=k-1; i<nums.size(); i++){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);

            sol.push_back(nums[dq.front()]);
        }

        return sol;

    }
};