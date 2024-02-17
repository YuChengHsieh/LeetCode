#include <queue>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int m = maze.size(), n = maze[0].size();
        q.push(make_pair(entrance[0],entrance[1]));
        maze[entrance[0]][entrance[1]] = '#';
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [row,col] = q.front();
                q.pop();
                if(row == 0 || row == m-1 || col == 0 || col == n-1 ) 
                    if(row != entrance[0] || col != entrance[1]) return steps;

                if(row-1 >= 0 && maze[row-1][col] == '.'){
                    maze[row-1][col] = '#';
                    q.push(make_pair(row-1,col));
                } 
                if(row+1 < m && maze[row+1][col] == '.'){
                    maze[row+1][col] = '#';
                    q.push(make_pair(row+1,col));
                }
                if(col-1 >= 0 && maze[row][col-1] == '.'){
                    maze[row][col-1] = '#';
                    q.push(make_pair(row,col-1));
                } 
                if(col+1 < n && maze[row][col+1] == '.'){
                    maze[row][col+1] = '#';
                    q.push(make_pair(row,col+1));
                } 
            }
            steps += 1;
        }

    return -1;
    }
};