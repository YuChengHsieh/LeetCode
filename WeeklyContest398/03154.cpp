#include <vector>
using namespace std;

// dp memorization
class Solution {
private:
    int dp(int val, int op1, int op2, bool use_op1, int k, vector<vector<vector<int>>> &mem){
        if(val-1 > k || val < 0 || op2 > 30 || op1 > 30) return 0;
        if(mem[op1][op2][use_op1] != -1) return mem[op1][op2][use_op1];
        
        int ans = 0;
        if(!use_op1){
            ans += dp(val-1,op1+1,op2,true,k,mem);
            ans += dp(val+pow(2,op2),op1,op2+1,false,k,mem);
        }else{
            ans += dp(val+pow(2,op2),op1,op2+1,false,k,mem);
        }
        if(val == k) ans += 1;
        return mem[op1][op2][use_op1] = ans;
    }
public:
    int waysToReachStair(int k) {
        vector<vector<vector<int>>> mem(31, vector<vector<int>>(31, vector<int>(2,-1)));
        return dp(1,0,0,false, k, mem);
    }
};