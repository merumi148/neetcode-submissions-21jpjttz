class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int rs = 0;
        int maxfre = 0;
        vector<int> arr(26, 0);
        for(int r = 0; r < s.length(); r++){
            arr[s[r] - 'A']++;
            maxfre = max(maxfre, arr[s[r] - 'A']);

            if((r - l + 1) - maxfre > k){
                arr[s[l] - 'A']--;
                l++;
            }
            rs = max(rs, r - l + 1);
        }
        return rs;
    }
};
