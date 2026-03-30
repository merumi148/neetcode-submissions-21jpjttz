class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums){
            mp[n]++;
        }
        vector<pair<int, int>> vt(mp.begin(), mp.end());

        sort(vt.begin(), vt.end(),
        [](auto &a, auto &b) {
            return a.second > b.second;
        }
        );

        vector<int> rs;
        for(int i = 0; i < k; i++){
            rs.push_back(vt[i].first);
        }
        return rs;
    }
};
