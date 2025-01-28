#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnts(26,0); 
        string ans;

        for(auto& ch: s){
            cnts[ch-'a'] ++;
        }

        int first_idx = -1, second_idx = -1;
        for(int i=25; i>=0; i--){
            if(cnts[i] != 0){
                while(cnts[i] > 0){
                    int val = min(repeatLimit,cnts[i]);
                    cnts[i] -= val;
                    for(int j=0; j<val; j++){
                        ans += i + 'a';
                    }
                    if(cnts[i] > 0){
                        bool find = false;
                        for(int j=i-1; j>=0; j--){
                            if(cnts[j] > 0){
                                cnts[j] -= 1;
                                ans += j + 'a';
                                find = true;
                                break;
                            }
                        }
                        if(!find) break;
                    }
                }
            }
        } 
        return ans;
    }
};