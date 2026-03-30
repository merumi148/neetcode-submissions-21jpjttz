class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> rs(nums.size());
       int total = 1;
       int countzero = 0;
       for(int n : nums){
        if(n == 0) countzero++;
        else{
            total *= n;
        }
       }

        if(countzero > 1) return vector<int>(nums.size(), 0);
       for(int i =  0; i < nums.size(); i++){
            if(countzero > 0){
                if(nums[i] == 0) rs[i] = total;
                else rs[i] = 0;
            }
            else if(countzero == 0){
                rs[i] = total / nums[i];
            }
       }
       return rs;
    }
};
