#include <queue>
#include <string>
using namespace std;
class Solution {
private:
    queue<char> q;
public:
    string predictPartyVictory(string senate) {
        for(auto &ch: senate){
            q.push(ch);
        }
        int r_cnt = 0, d_cnt = 0;
        while(!q.empty()){
            auto ch = q.front();
            if(ch == 'R'){
                if(r_cnt >= 0){
                    d_cnt = min(-1,d_cnt-1);
                    q.push(ch);
                }
                r_cnt += 1;
            }else{
                if(d_cnt >= 0){
                    r_cnt = min(-1,r_cnt-1);
                    q.push(ch);
                }
                d_cnt += 1;
            }
            if(r_cnt > int(senate.size())) return "Radiant";
            if(d_cnt > int(senate.size())) return "Dire";
            q.pop();
        }
        return r_cnt > d_cnt ? "Radiant" : "Dire";
    }
};