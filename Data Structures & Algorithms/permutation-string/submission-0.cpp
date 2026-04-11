class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> vt1 (26, 0);
        vector<int> vt2 (26, 0);

        int n1 = s1.length();
        int n2 = s2.length();
        int l = 0;
        int r = n1 - 1;
        
        for(int i = 0; i < n1; i++){
            vt1[s1[i] - 'a']++;
            vt2[s2[i] - 'a']++;
        }
        if(vt1 == vt2) return true;
        for(int i = n1; i < n2; i++){
            vt2[s2[i] - 'a']++;
            vt2[s2[i - n1] - 'a']--;
            if(vt1 == vt2) return true;
        }


        return vt1 == vt2;
    }
};
