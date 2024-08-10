#include <vector>
using namespace std;

// binary search o(nlogn)
class Solution {
private:
    bool check(int day, vector<int>& bloomDay, int m, int k){
        int cont_cnt = 0, bloom_cnt = 0;
        for(auto& b: bloomDay){
            if(day >= b){
                cont_cnt += 1;
                if(cont_cnt == k){
                    cont_cnt = 0;
                    bloom_cnt += 1;
                }
            }else cont_cnt = 0;
        }
        return bloom_cnt >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int max_bloomday = 0;
        for(auto& b: bloomDay) max_bloomday = max(max_bloomday, b);
        int start = 0, end = max_bloomday;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(check(mid,bloomDay,m,k)) end = mid - 1;
            else start = mid + 1;
        }
        return start <= max_bloomday ? start : -1;
    }
};