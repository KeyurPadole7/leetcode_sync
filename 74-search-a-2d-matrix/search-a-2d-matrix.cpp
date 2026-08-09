class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int coln = matrix[0].size();
    
        int low = 0;
        int high = row*coln-1;
        int mid = 0;

        int flag = 0;

        while(low<=high){
            mid = (low+high)/2;
            int m = matrix[mid/coln][mid%coln];

            if(m == target){
                flag = 1;
                break;
            }else if(m<target)low = mid + 1;
            else high = mid - 1;
        }

        if (flag == 0) return false;
        else return true;
        
    }
};