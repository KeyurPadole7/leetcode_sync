class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int l = 0, h = mat[0].size()-1;
        int mid = (l+h)/2;

        for(int i = 0; i<mat.size(); i++){
            l = 0; h = mat[0].size()-1;
            while(l<=h){
                int mid = (l+h)/2;

                if(mat[i][mid] == target) return true;
                else if ( mat[i][mid] > target) h = mid - 1;
                else l = mid+1;
            }
        }

        return false;
    }
};