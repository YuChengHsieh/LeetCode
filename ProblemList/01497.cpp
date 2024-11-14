#include <vector>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> check(k,0);
        for(auto& val: arr){
            val %= k;
            if(val < 0) val += k;
            check[val%k] += 1;
        }

        for(int i=1; i<=k/2; i++){
            if(check[i] != check[k-i]) return false;
        }
        return check[0]%2 ? false : true;
    }
};