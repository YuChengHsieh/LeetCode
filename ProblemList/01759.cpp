#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    int countHomogenous(string s) {
        int mod = pow(10,9)+7;
        long long ans = 0;
        int cont = 1;
        char prev = ' ';
        for(auto &ch :s){
            if(ch == prev) cont += 1;
            else cont = 1;
            prev = ch;
            ans += cont;
            ans %= mod;
        }
        return int(ans);
    }
};