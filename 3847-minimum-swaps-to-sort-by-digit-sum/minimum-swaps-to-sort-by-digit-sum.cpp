class Solution {
public:
    static bool comparator(pair<pair<int,int>, int> &l, pair<pair<int,int>, int> &r){
        if(l.first.first == r.first.first) return l.first.second < r.first.second;
        else return l.first.first < r.first.first;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        //{{dig sum, org num}, org idx}
        vector<pair<pair<int,int>, int>> sar(n);

        for(int i=0; i<n; i++){
            int sum=0;
            int temp=nums[i];
            while(temp!=0){
                sum+= temp%10;
                temp /= 10;
            }
            sar[i] = {{sum, nums[i]}, i};
        }

        sort(sar.begin(), sar.end(), comparator);
        vector<bool> vis(n, false);
        int swap=0;

        for(int i=0; i<n; i++){
            if(vis[i] || i==sar[i].second) continue;

            int curr = i;
            int cyc = 0;
            while(!vis[curr]){
                vis[curr] = true;
                curr = sar[curr].second;
                cyc++;
            }

            if(cyc>0){
                swap += cyc-1;
            }
        }

        return swap;


    }
};