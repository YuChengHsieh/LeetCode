#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            int row = moveTime.size(), col = moveTime[0].size();
            pq.push({0, 0, 0, 0});
            while(!pq.empty()){
                auto vec = pq.top();
                pq.pop();
                while(moveTime[vec[1]][vec[2]] == -1){
                    vec = pq.top();
                    pq.pop();
                }
    
                moveTime[vec[1]][vec[2]] = -1;
                if(vec[1] == row-1 && vec[2] == col-1) return vec[0];
                
                if(vec[1]-1 >= 0 && moveTime[vec[1]-1][vec[2]] != -1) 
                    pq.push({max(vec[0],moveTime[vec[1]-1][vec[2]])+1+(vec[3] == 1),vec[1]-1,vec[2],!(vec[3] == 1)});
    
                if(vec[1]+1 < row && moveTime[vec[1]+1][vec[2]] != -1) 
                    pq.push({max(vec[0],moveTime[vec[1]+1][vec[2]])+1+(vec[3] == 1),vec[1]+1,vec[2],!(vec[3] == 1)});
    
                if(vec[2]-1 >= 0 && moveTime[vec[1]][vec[2]-1] != -1) 
                    pq.push({max(vec[0],moveTime[vec[1]][vec[2]-1])+1+(vec[3] == 1),vec[1],vec[2]-1,!(vec[3] == 1)});
    
                if(vec[2]+1 < col && moveTime[vec[1]][vec[2]+1] != -1){
                    pq.push({max(vec[0],moveTime[vec[1]][vec[2]+1])+1+(vec[3] == 1),vec[1],vec[2]+1,!(vec[3] == 1)});
                }
            }
            return -1;
        }
    };