class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> rs (n, 0);
        stack<int> temp;
        int day ;
        for(int i = 0; i < n; i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                int preDay = temp.top();
                temp.pop();
                rs[preDay] = i - preDay;
            }
            temp.push(i);
        }
        return rs;
    }
};
