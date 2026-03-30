class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rsIndex = -1;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            if(nums[low] > target ) low++;
            else if(nums[high] < target) high--;
            else{
                int mid = low + (high - low) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return rsIndex;
    }
};
