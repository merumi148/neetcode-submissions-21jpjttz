class Solution {
public:
    int maxArea(vector<int>& heights) {
        int rs = 0;
        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
           int h = min(heights[l], heights[r]);
           int w = r - l;
           int sq = h * w;
           rs = max(rs, sq);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return rs;
    }
};
