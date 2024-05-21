#include <vector>
#include <string>
#include <queue>
using namespace std;

// memorization
class Solution {
private:
    int dp(int ring_idx, int key_idx, bool clockwise, string& ring, string& key, vector<vector<vector<int>>>& mem){
        if(key_idx == key.size()) return 0;
        if(mem[ring_idx][key_idx][clockwise] != -1) return mem[ring_idx][key_idx][clockwise];
        int ans;
        if(ring[ring_idx] == key[key_idx]) 
            ans = min(
                dp(ring_idx,key_idx+1,true,ring,key,mem),
                dp(ring_idx,key_idx+1,false,ring,key,mem)
            );
        else{
            if(clockwise) ans = dp((ring_idx+ring.size()+1)%ring.size(),key_idx,clockwise,ring,key,mem);
            else ans = dp((ring_idx+ring.size()-1)%ring.size(),key_idx,clockwise,ring,key,mem);
        }
        return mem[ring_idx][key_idx][clockwise] = ans+1;
    }
public:
    int findRotateSteps(string ring, string key) {
        // memorization
        vector<vector<vector<int>>> mem(ring.size(), vector<vector<int>>(key.size(), vector<int>(2,-1)));
        return min(dp(0,0,true,ring,key,mem),dp(0,0,false,ring,key,mem));
    }
};

// BFS + memorization
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // queue
        queue<vector<int>> q;
        q.push({0,0,true});
        q.push({0,0,false});
        int ring_sz = ring.size(), key_sz = key.size();
        int step = 0;
        bool success = false;

        vector<vector<vector<bool>>> mem(ring.size(), vector<vector<bool>>(key.size(), vector<bool>(2,false)));

        while(!q.empty() && !success){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto item = q.front();
                q.pop();
                int ring_idx = item[0], key_idx = item[1];
                bool clockwise = item[2];
                if(mem[ring_idx][key_idx][clockwise]) continue;
                else mem[ring_idx][key_idx][clockwise] = true;
                if(ring[ring_idx] == key[key_idx]){
                    if(key_idx+1 == key_sz){
                        success = true;
                        break;
                    } 
                    q.push({ring_idx,key_idx+1,true});
                    q.push({ring_idx,key_idx+1,false});
                }else{
                    if(clockwise) q.push({((ring_idx+ring_sz+1)%ring_sz),key_idx,true});
                    else q.push({((ring_idx+ring_sz-1)%ring_sz),key_idx,false});
                }
            }
            step ++;
        }
        return step;
    }
};