#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    int numSub(string s) {
        int mod = pow(10,9)+7;
        long long ans = 0;
        int cont = 1;
        char prev = ' ';

        for(auto &ch: s){
            if(ch == '1'){
                if(prev == '1') cont += 1;
                else cont = 1;
            }else cont = 0;
            prev = ch;
            ans += cont;
            ans %= mod;
        }
        return ans;
    }
};