#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        string max_str = "";
        int max_num = -1;
        int cont = 1;
        char prev = ' ';
        for(int i=0; i<num.size(); i++){
            if(num[i] == prev){
                cont += 1;
                if(cont == 3 && stoi(num.substr(i-2,3)) > max_num){
                    max_str = num.substr(i-2,3);
                    max_num = stoi(num.substr(i-2,3));
                }
            }else cont = 1;
            prev = num[i];
        }
        return max_str;
    }
};