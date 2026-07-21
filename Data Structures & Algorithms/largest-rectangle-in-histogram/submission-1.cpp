class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        stack<int> st;
        heights.push_back(0);
        int len = heights.size();
        for(int i = 0; i < len; ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;
                area = max(area, w * h);
            }
            st.push(i);
        }
        return area;
    }
};
