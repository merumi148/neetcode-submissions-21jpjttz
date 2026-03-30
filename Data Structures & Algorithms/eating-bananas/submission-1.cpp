class Solution {
public:

    bool canEat(vector<int>& piles, int h, int k){
        long totalHour = 0;
        for(int x : piles){
            totalHour += (x + k - 1) / k;
        }
        return totalHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int low = 1;
      int high = *max_element(piles.begin(), piles.end());
      int rs = high;

      while(low <= high){
        int mid = low + (high - low) / 2;
        if(canEat(piles, h, mid)){
            rs = mid;
            high = mid - 1;
        }
        else low = mid + 1;
      }
      return rs;  
    }

};
