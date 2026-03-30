class Solution {
public:
    bool isPalindrome(string s) {
       string rs = "";
       for(int i = 0 ; i < s.length(); i++){
        if(s[i] == ' ' || !isalnum(s[i])) continue;
        rs += tolower(s[i]);
       }
       int left = 0;
       int right = rs.length() - 1;
       while(left < right){
        if(rs[left]!= rs[right]) return false;
        left++;
        right--;
       }
       return true;
    }
};
