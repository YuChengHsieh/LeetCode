#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int hCnt = 0, vCnt = 0, ans = 0;
        priority_queue<pair<int,bool>> pq;
        
        for(int i=0; i<m-1; i++){
            pq.push({horizontalCut[i],true});
        }
        
        for(int i=0; i<n-1; i++){
            pq.push({verticalCut[i],false});
        }
        
        while(!pq.empty()){
            auto [val, hor] = pq.top();
            pq.pop();
            if(hor){
                ans += (vCnt+1)*val;
                hCnt += 1;
            }else{
                ans += (hCnt+1)*val;
                vCnt += 1;
            }
        }
        return ans;
    }
};