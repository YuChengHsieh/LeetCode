#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int,int> cnts;
        int mod = pow(10,9)+7;
        int num = 0;
        for(int i=0; i<deliciousness.size(); i++){
            cnts[deliciousness[i]] += 1;
        }

        long long ans = 0;
        for(auto& item: cnts){
            for(int i=0; i<22; i++){
                int val = 1 << i;
                if(cnts.count(val - item.first)){
                    if(val-item.first == item.first) ans += (long long)cnts[item.first]*((long long)cnts[val - item.first]-1);
                    else ans += (long long)cnts[item.first]*(long long)cnts[val - item.first];
                    // ans %= mod;
                } 
            }
        }
        return (ans/2)%mod;
    }
};