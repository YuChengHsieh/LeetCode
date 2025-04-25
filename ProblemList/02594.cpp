#include<vector>
using namespace std;
class Solution {
    private:
        bool check(long long mins, vector<int>& ranks, long long cars){
            long long fixed_car = 0;
            for(auto& r: ranks){
                fixed_car += (int)(sqrtl(mins/(long long)r));
            }
            return fixed_car >= cars;
        }
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            // binary search
            long long start = 0, end = LLONG_MAX;
            while(start <= end){
                long long mid = start + (end-start)/2;
                if(check(mid,ranks,cars)) end = mid - 1;
                else start = mid + 1;
            }
            return start;
        }
    };