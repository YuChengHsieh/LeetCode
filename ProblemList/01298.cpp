#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<int> boxes(n,false);
        for(auto& b: initialBoxes){
            if(status[b]) q.push(b);
            boxes[b] = true;
        }

        int ans = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            ans += candies[cur];

            for(auto& k: keys[cur]){
                if(status[k] == 0 && boxes[k]) q.push(k);
                status[k] = 1;
            }

            for(auto& b: containedBoxes[cur]){
                if(status[b]) q.push(b);
                boxes[b] = true;
            }

            
        }
        return ans;
    }
};