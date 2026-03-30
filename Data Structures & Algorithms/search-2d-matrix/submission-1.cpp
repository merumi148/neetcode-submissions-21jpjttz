class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        for(int i = 0; i < matrix.size(); i++){
            int low = 0;
            int high = matrix[i].size() - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(target == matrix[i][mid]) return true;
                else if(target > matrix[i][mid]) low = mid + 1;
                else high = mid - 1;
            }
        }  
        return false;
    }
};
