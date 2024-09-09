#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string new_s;
        for(auto& ch: s){
            new_s += to_string(ch-'a'+1);
        }

        string cur_s = new_s;
        for(int i=0; i<k; i++){
            int val = 0;
            for(int j=0; j<cur_s.size(); j++){
                val += cur_s[j] - '0';
            }
            cur_s = to_string(val);
        }
        return stoi(cur_s);
    }
};