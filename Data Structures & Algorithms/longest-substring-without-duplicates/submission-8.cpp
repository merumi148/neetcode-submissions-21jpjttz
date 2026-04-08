class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rs = 0;
        vector<int> arr(256, -1);
        int firstString = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(arr[c] >= firstString){
                firstString = arr[c] + 1;
            }
            
            arr[c] = i;
            rs = max(rs, i - firstString + 1);
            
        }

        return rs;
    }
};
