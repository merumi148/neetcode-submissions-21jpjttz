class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
       vector<int> count (n, 0);
       for(int i = 0; i < n; ++i){
        if(count[nums[i]] > 0) return nums[i];
        count[nums[i]]++;
       }
       return 0;
    }
};
