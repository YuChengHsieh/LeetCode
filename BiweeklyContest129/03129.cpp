#include <vector>
using namespace std;
class Solution {
private:
    int mod = pow(10,9)+7;
    long long dp(int zero, int one, int past, int cnt, int limit, vector<vector<vector<vector<int>>>>& mem){
        if(zero < 0 || one < 0) return 0;
        if(cnt > limit) return 0;
        if(zero == 0 && one == 0) return 1;
        if(mem[zero][one][past][cnt] != -1) return mem[zero][one][past][cnt];
        
        int ans = 0;
        if(past == 0){
            ans += dp(zero-1, one, 0, cnt+1, limit, mem);    
            ans %= mod;
            ans += dp(zero, one-1, 1, 1, limit, mem);    
            ans %= mod;
            
        }else{
            ans += dp(zero-1, one, 0, 1, limit, mem);    
            ans %= mod;
            ans += dp(zero, one-1, 1, cnt+1, limit, mem);   
            ans %= mod;
        }
        return mem[zero][one][past][cnt] = ans;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> mem(zero+1, vector<vector<vector<int>>>(one+1,vector<vector<int>>(3,vector<int>(limit+1,-1))));
        return dp(zero,one,2,0,limit,mem);
    }
};