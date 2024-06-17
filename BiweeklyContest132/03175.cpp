#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        queue<int> q;
        unordered_map<int ,int> pos;
        int max_val = 0, max_idx = -1;
        for(int i=0; i<skills.size(); i++){
            q.push(skills[i]);
            pos[skills[i]] = i;
            if(skills[i] > max_val){
                max_val = skills[i];
                max_idx = i;
            }
        }
        
        if(k > skills.size()) return max_idx;
        
        int winner = q.front(), streak = 0;
        q.pop();
        for(int i=0; i<skills.size(); i++){
            int next = q.front();
            q.pop();
            if(winner > next) streak += 1;
            else{
                winner = next;
                streak = 1;
            }
            if(streak == k) return pos[winner];
        }
        return max_idx;
    }
};