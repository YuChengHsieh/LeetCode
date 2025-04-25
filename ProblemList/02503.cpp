#include <vector>
#include<queue>
#include<map>
using namespace std;
class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int cnt = 0, m = grid.size(), n = grid[0].size();
            int cur_max = 0;
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            map<int,int> mp;
            vector<int> vals;
            vals.push_back(0);
            mp[0] = 0;
    
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[0][0] = true;
            pq.push({grid[0][0],0,0});
    
            while(!pq.empty()){
                vector<int> cur = pq.top();
                pq.pop();
                int row = cur[1], col = cur[2];
                if(cur[0] > cur_max){
                    cur_max = cur[0];
                    vals.push_back(cur_max);
                }
                mp[cur_max] = ++cnt;
    
    
                if(row-1 >=0 && !visited[row-1][col]){
                    visited[row-1][col] = true;
                    pq.push({grid[row-1][col],row-1,col});
                }
                if(row+1 < m && !visited[row+1][col]){
                    visited[row+1][col] = true;
                    pq.push({grid[row+1][col],row+1,col});
                }
                if(col-1 >=0 && !visited[row][col-1]){
                    visited[row][col-1] = true;
                    pq.push({grid[row][col-1],row,col-1});
                }
                if(col+1 < n && !visited[row][col+1]){
                    visited[row][col+1] = true;
                    pq.push({grid[row][col+1],row,col+1});
                }
            }
    
    
            vector<int> ans;
            for(auto& q: queries){
                int start = 0, end = vals.size() -1;
                while(start <= end){
                    int mid = start + (end-start)/2;
                    if(vals[mid] > q-1) end = mid - 1;
                    else start = mid + 1;
                }
                ans.push_back(mp[vals[end]]);
            }
            return ans;
        }
    };