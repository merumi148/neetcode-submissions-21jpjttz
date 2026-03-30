class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int rs = 0;
        unordered_set st(nums.begin(), nums.end());

        for(int x : st){
            if(st.find(x - 1) == st.end()){
                int curr = x;
                int longest = 1;

                while(st.find(curr + 1) != st.end()){
                    curr++;
                    longest++;
                }

                rs = max(rs, longest);
            }
        }
       return rs;
    }
};
