class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for(int x : nums){
            numbers.insert(x);
        }
        if(numbers.size() == nums.size()) return false;
        else return true;
    }
};