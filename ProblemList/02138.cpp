#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string tmp;
        for(int i=0; i<s.size(); i++){
            tmp += s[i];
            if((i+1)%k == 0){
                ans.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp.size()){
            for(int i=tmp.size(); i<k; i++){
                tmp += fill;
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};