#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto &num: nums){
            s.insert(num);
        }

        int max_cnt = 0, cnt = 0;
        int prev = INT_MIN;
        for(auto& num: s){
            if(num == prev+1){
                cnt += 1;
            }else{
                max_cnt = max(max_cnt,cnt);
                cnt = 1;
            }
            prev = num;
        }
        
        return max(max_cnt,cnt);
    }
};