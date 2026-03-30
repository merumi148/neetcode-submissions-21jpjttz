class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> stra;
        unordered_map<char, int> strb;


        for(int i = 0; i < s.length(); i++){
            stra[s[i]]++;
            strb[t[i]]++;
        }
        return stra == strb;
    }
};
