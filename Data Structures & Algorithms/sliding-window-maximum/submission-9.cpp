class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rs;
        std::priority_queue<pair<int,int>> maxHeap;
        if(nums.empty()) return rs;
            for(int r = 0; r < nums.size(); r++){
                maxHeap.push({nums[r], r});
                if(r >= k - 1){
                    int l = r - k + 1;
                    while(!maxHeap.empty() && maxHeap.top().second < l){
                        maxHeap.pop();
                    }
                    rs.push_back(maxHeap.top().first);
                }
            }
        

    return rs;
    }
};
