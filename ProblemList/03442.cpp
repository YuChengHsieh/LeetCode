#include <vector>
using namespace std;
class Solution {
public:
    int maxDifference(string s) {
        int max_odd = 0, min_even = INT_MAX;
        vector<int> cnts(26,0);
        for(auto& ch: s){
            cnts[ch-'a'] ++;
        }

        for(int i=0; i<26; i++){
            if(cnts[i] != 0){
                if(cnts[i]%2 && cnts[i] > max_odd) max_odd = cnts[i];
                else if(!(cnts[i]%2) && cnts[i] < min_even) min_even = cnts[i];
            }   
        }

        return max_odd - min_even;
    }
};