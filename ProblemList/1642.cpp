#include <queue>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<heights.size()-1; i++){
            if(heights[i+1]-heights[i] > 0){
                ladders -= 1;
                pq.push(heights[i+1]-heights[i]);
                if(ladders < 0){
                    bricks -= pq.top();
                    pq.pop();
                    if(bricks < 0) return i;
                }
            }
        }
        return heights.size()-1;
    }
};