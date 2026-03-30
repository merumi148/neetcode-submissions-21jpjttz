class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size() - 1;
        int low = 0;
        int high = n;
        int min = nums[0];
        while(low <= high){
            if(nums[high] < nums[low]) low++;
            else{
                int mid = low + (high - low) / 2;
                if(nums[mid] < min){
                    min = nums[mid];
                    high = mid - 1;
                }
                else low = mid + 1;
            }
        }
        return min;
    }
};
