class Solution {
public:

    string encode(vector<string>& strs) {
        string rs = "";
        for(auto &s : strs){
            rs = rs + to_string(s.size()) + "#" + s;
        }
        return rs;
    }

    vector<string> decode(string s) {
        vector<string> rs;
        int i = 0;
        while(i < s.size()){
            int len = 0;
            while(i < s.size() && s[i] != '#'){
                len = len * 10 + (s[i] - '0');
                i++;
            }
            i++;
            rs.push_back(s.substr(i, len));
            i += len;
        }
    
        return rs;
    }
};
