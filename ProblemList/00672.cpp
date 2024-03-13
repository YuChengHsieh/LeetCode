#include<vector>
#include<set>
#include<string>S
using namespace std;
class Solution {
private:
    void dp(string& status, int presses, set<pair<string, int>>& mem, set<string>& s){
        if(presses == 0){
            if(!s.count(status)){            
                s.insert(status);
            }
            return;
        }

        if(mem.count({status, presses})) return;

        string status1 = status, status2 = status, status3 = status, status4 = status;

        for(int i=0; i<status.size(); i++){
            if(status1[i] == '1') status1[i] = '0';
            else status1[i] = '1';                
        }
        for(int i=1; i<status.size(); i+=2){
            if(status2[i] == '1') status2[i] = '0';
            else status2[i] = '1';                
        }
        for(int i=0; i<status.size(); i+=2){
            if(status3[i] == '1') status3[i] = '0';
            else status3[i] = '1';                
        }
        for(int i=0; i<status.size(); i+=3){
            if(status4[i] == '1') status4[i] = '0';
            else status4[i] = '1';                
        }

        dp(status1, presses-1, mem ,s);
        dp(status2, presses-1, mem ,s);
        dp(status3, presses-1, mem ,s);
        dp(status4, presses-1, mem ,s);
        mem.insert({status, presses});
        return;
    }
public:
    int flipLights(int n, int presses) {
        set<pair<string, int>> mem;
        set<string> s;
        string str;
        for(int i=0; i<n; i++) str += "1";
        dp(str, presses,  mem, s);
        return s.size();
    }
};