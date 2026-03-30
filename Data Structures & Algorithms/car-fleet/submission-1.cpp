class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int feets = 0;
        map<int, double> car;
        for(int i = 0; i < position.size(); i++){
            car[position[i]] = (double)(target - position[i]) / speed[i];
        }

        double max_time = 0.0;
        for(auto i = car.rbegin(); i != car.rend(); ++i){
            double curr_time = i->second;
            if(curr_time > max_time){
                feets++;
                max_time = curr_time;
            }
        }
        return feets;
    }
};