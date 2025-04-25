#include <string>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        char ch1, ch2;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                if(!count){
                    count ++;
                    ch1 = s1[i];
                    ch2 = s2[i];
                }else{
                    if(count == 2) return false;
                    if(ch1 == s2[i] && ch2 == s1[i]) count ++;
                    else return false;
                }
            }
        }
        return count%2 ? false : true;
    }
};