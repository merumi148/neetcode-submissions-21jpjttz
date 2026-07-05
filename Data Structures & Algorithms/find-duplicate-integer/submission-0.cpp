class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
       int temp;
       for(int i = 0; i < n; ++i){
        temp = nums[i];
        for(int j = i + 1; j < n; ++j){
            if(nums[i] == nums[j]) return nums[i];
        }
       }
       return 0;
    }
};
