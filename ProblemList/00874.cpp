#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> x_obs;
    unordered_map<int, vector<int>> y_obs;
    int cur_x = 0, cur_y = 0;

    int bs_right(int val, vector<int>& vec){
        int start = 0, end = vec.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val >= vec[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }

    int bs_left(int val, vector<int>& vec){
        int start = 0, end = vec.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(val > vec[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }

    int func(int vert, int c){
        int ret;
        if(vert == 0){
            ret = bs_right(cur_y,x_obs[cur_x]);
            return (ret >= x_obs[cur_x].size() || x_obs[cur_x][ret]-1 > cur_y + c) ? cur_y + c : x_obs[cur_x][ret]-1;
        }else if(vert == 2){
            ret = bs_left(cur_y,x_obs[cur_x]);
            return (ret < 0 || x_obs[cur_x][ret]+1 < cur_y - c) ? cur_y - c : x_obs[cur_x][ret]+1;
        }else if(vert == 1){
            ret = bs_right(cur_x,y_obs[cur_y]);
            return (ret >= y_obs[cur_y].size() || y_obs[cur_y][ret]-1 > cur_x + c) ? cur_x + c : y_obs[cur_y][ret]-1; 
        }else{
            ret = bs_left(cur_x,y_obs[cur_y]);
            return (ret < 0 || y_obs[cur_y][ret]+1 < cur_x - c) ? cur_x - c : y_obs[cur_y][ret]+1;
        }
        return 0;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir_idx = 0, max_dis = 0;
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        sort(obstacles.begin(),obstacles.end());

        for(auto& obs: obstacles){
            x_obs[obs[0]].push_back(obs[1]);
            y_obs[obs[1]].push_back(obs[0]);
        }
        for(auto& c: commands){
            if(c == -1) dir_idx = (dir_idx+1)%4;
            else if(c == -2) dir_idx = (4+dir_idx-1)%4;
            else{
                int ret = func(dir_idx,c);
                if(dir_idx%2 == 0) cur_y = ret;
                else cur_x = ret;
                max_dis = max(max_dis,cur_x*cur_x + cur_y*cur_y);
            }
        }
        return max_dis;
    }
};