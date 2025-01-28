#include <vector>
#include <string>
using namespace std;

// prefix sum
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n+1,0);
        for(auto& shift: shifts){
            if(shift[2] == 0){
                diff[shift[0]] -= 1;
                diff[shift[1]+1] += 1;
            }else{
                diff[shift[0]] += 1;
                diff[shift[1]+1] -= 1;
            }
        }

        vector<int> prefix(n,0);
        prefix[0] = diff[0]%26;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + diff[i]; 
            prefix[i] %= 26;
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] + prefix[i] > 'z') s[i] = 'a' + s[i] + prefix[i] - 'z' - 1;
            else if(s[i] + prefix[i] < 'a') s[i] = 'z' - ('a' - (s[i] + prefix[i])) + 1;
            else s[i] += prefix[i];
        }
        
        return s;
    }
};