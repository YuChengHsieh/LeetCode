#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    int maxPower(string s) {
        int max = 0;
        int cont = 0;
        char prev = ' ';
        for(auto &ch : s){
            if(ch == prev) cont += 1;
            else{
                if(cont > max) max = cont;
                cont = 1;
            }
            prev = ch;
        }
        if(cont > max) max = cont;
        return max;
    }
};