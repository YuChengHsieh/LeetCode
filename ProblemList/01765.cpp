#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // BFS
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> heights(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    q.push({i,j});
                } 
            }
        }

        int height = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [r,c] = q.front();
                q.pop();
                if(r+1 < m && !heights[r+1][c] && !isWater[r+1][c]){
                    heights[r+1][c] = height;
                    q.push({r+1,c});
                }
                if(c+1 < n && !heights[r][c+1] && !isWater[r][c+1]){
                    heights[r][c+1] = height;
                    q.push({r,c+1});
                }
                if(r-1 >= 0 && !heights[r-1][c] && !isWater[r-1][c]){
                    heights[r-1][c] = height;
                    q.push({r-1,c});
                }
                if(c-1 >= 0 && !heights[r][c-1] && !isWater[r][c-1]){
                    heights[r][c-1] = height;
                    q.push({r,c-1});
                }
            }
            height ++;
        }

        return heights;
    }
};