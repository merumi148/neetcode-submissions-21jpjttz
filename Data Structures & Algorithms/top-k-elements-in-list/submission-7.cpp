class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums){
            mp[n]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto &n : mp){
            bucket[n.second].push_back(n.first);
        }

        int n = nums.size();
        vector<int> rs;
        for(int i = n; i >=0; i--){
            for(int x : bucket[i]){
                if(k == 0) break;
                rs.push_back(x);
                k--;
            }
        }
        return rs;
    }
};
