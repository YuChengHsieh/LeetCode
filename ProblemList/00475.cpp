#include <vector>
using namespace std;
class Solution {
private:
    bool check(int radius, vector<int>& houses, vector<int>& heaters){
        int heater_cnt = 0;
        for(auto& house: houses){
            if(house < heaters[heater_cnt] - radius) return false;
            else if(house > heaters[heater_cnt] + radius){
                while(heater_cnt < heaters.size() && house > heaters[heater_cnt] + radius) heater_cnt += 1;
                if(heater_cnt >= heaters.size() || house < heaters[heater_cnt] - radius) return false;
            }
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int start = 0, end = max(houses.back(),heaters.back());
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid, houses, heaters)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};