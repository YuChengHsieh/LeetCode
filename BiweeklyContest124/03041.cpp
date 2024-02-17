#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        map<int,int> m;
        for(auto& num: nums){
            m[num] += 1;
        }
        
        int max_val = 0;
        bool next = false;
        int prev = -2;
        int cnt = 0;
        int real_cnt = 0;
        for(auto& item: m){
            if(item.first - prev > 2){
                if(next) cnt += 1;
                max_val = max(max_val,cnt);
                cnt = 1;
                real_cnt = 1;
                next = item.second > 1 ? true : false;
            }else if(item.first - prev == 2){
                if(next) cnt += 2;
                else{
                    max_val = max(max_val,cnt);
                    cnt = real_cnt+1;
                } 
                real_cnt = 1;
                next = item.second > 1 ? true : false;
            }else{
                real_cnt += 1;
                cnt += 1;
                next = item.second > 1 || (item.second == 1 && next) ? true : false;
            }
            prev = item.first;
        }
        
        return max(max_val,next ? cnt+1: cnt);
    }
};