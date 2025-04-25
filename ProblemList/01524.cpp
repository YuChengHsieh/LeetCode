#include <vector>
using namespace std;
class Solution {
    public:
        int mod = 1e9+7;
        int numOfSubarrays(vector<int>& arr) {
            int odd_cnt = 0, even_cnt = 1, sum = 0;
            long long ans = 0;
            for(auto& num: arr){
                sum += num;
                if(sum%2){
                    odd_cnt ++;
                    ans += even_cnt;
                    ans %= mod;
                }else{
                    even_cnt ++;
                    ans += odd_cnt;
                    ans %= mod;
                }
            }
            return (int)ans;
        }
    };