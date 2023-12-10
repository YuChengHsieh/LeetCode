#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for(i=num.size()-1; i>=0; i--){
            if(int(num[i])%2 == 1) break;
        }
        return num.substr(0,i+1);
    }
};