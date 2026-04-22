class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";

        vector<int> countT (128, 0);
        for(char c : t){
            countT[c]++;
        }
        vector<int> window (128, 0);
        int have = 0, need = 0;
        for(int i = 0; i < 128; i++){
            if(countT[i] > 0) need++;
        }

        int resL = -1, minLen = INT_MAX;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;
            if(countT[c] > 0 && window[c] == countT[c]) have++;

            while(have == need){
                if(right - left + 1 < minLen){
                    resL = left;
                    minLen = right - left + 1;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if(countT[leftChar] > 0 && window[leftChar] < countT[leftChar]) have--;
                left++;
            }
        }
        return (resL == -1) ? "" : s.substr(resL, minLen);
    }
};
