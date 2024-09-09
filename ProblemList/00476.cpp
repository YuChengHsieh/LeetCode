#include <vector>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        vector<bool> bits;
        while(num > 0){
            if(num%2 == 1) bits.push_back(0);
            else bits.push_back(1);
            num /= 2;
        }
        bits.pop_back();
        
        int ans = 0;
        for(int i=0; i<bits.size(); i++){
            ans += bits[i]*(1 << i);
        }
        return ans;
    }
};