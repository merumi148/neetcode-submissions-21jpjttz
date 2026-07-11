class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> rs (n, 1);

        int prefix = 1;
       for(int i = 0; i < n; i++){
        rs[i] *= prefix;
        prefix *= nums[i];
       }
        int suffix = 1;
       for(int i = n - 1; i >=0; i--){
        rs[i] *= suffix;
        suffix *= nums[i];
       }
       return rs;
    }
};
